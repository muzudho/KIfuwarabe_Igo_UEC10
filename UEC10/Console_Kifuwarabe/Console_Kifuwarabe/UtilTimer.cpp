#include "stdafx.h"
#include "UtilTimer.h"

UtilTimer::UtilTimer()
{
}


UtilTimer::~UtilTimer()
{
}

void UtilTimer::Start(DefaultWorker* pWorker, long milliseconds)
{
	m_alive = true;
	m_pWorker = pWorker;
	m_thread1 = std::thread([=,&milliseconds] {
		// �����Ə����̊Ԃ� n �b�ȏ�󂯂�B�i���� n �b�Ԋu�ۏ�Ȃ̂ŁAn �b���ɒ���I�ɃX�^�[�g�����Ƃ����Ӗ��ł͂Ȃ��j
		const std::chrono::milliseconds interval(milliseconds);
		while (this->m_alive) {
			
			auto start = std::chrono::system_clock::now();

			// �����������ꂽ���\�b�h���Ăяo��
			this->m_pWorker->OnStep();

			auto end = std::chrono::system_clock::now();
			auto elapsed = end - start;
			std::cout << "elapsed.count()=[" << elapsed.count() << "]" << std::endl;

			// ����A�C���^�[�o�����Ԃ̃X���[�v��ۏ�
			if (elapsed < interval) {
				std::this_thread::sleep_for(interval - elapsed);
			}
		}

		std::cout << "finished." << std::endl;
	});
}

void UtilTimer::Block()
{
	// �X�^�[�g�������X���b�h���I������܂ŁA����ȏ�i�܂Ȃ��B
	m_thread1.join();
	// �X���b�h���~�߂邩�A����Ɏ~�܂邩����Ɓ@��������ȉ��ɐi�ށB					  
}

void UtilTimer::Break_Force()
{
	// �X���b�h���~�߂�
	m_thread1.detach();

	// �X���b�h�̒��̃��[�v���甲��������
	this->m_alive = false;
}

void UtilTimer::Sleep_Milliseconds(long milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
