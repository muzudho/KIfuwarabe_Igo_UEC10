#include "stdafx.h"
#include "UtilTimer.h"

UtilTimer::UtilTimer()
{
}


UtilTimer::~UtilTimer()
{
}

/**
 * �t�@���N�^�[�Ƃ����̂́A�N���X���̌��� ( ) ���Z�q��t�������̂ł��B
 * �t�@���N�^�[�̈����� �����ɂ��Ă����Ă��������B
 */
void UtilTimer::Start(DefaultWorker your_functor, long milliseconds)
{
	m_alive = true;
	m_thread1 = std::thread([=,&your_functor,&milliseconds] {
		// �����Ə����̊Ԃ�1�b�ȏ�󂯂�B�i����P�b�Ԋu�ۏ�Ȃ̂ŁA�P�b���ɒ���I�ɃX�^�[�g�����Ƃ����Ӗ��ł͂Ȃ��j
		const std::chrono::milliseconds interval(milliseconds);
		//for (int i=0;i<10;i++) {
		while (this->m_alive) {
			
			auto start = std::chrono::system_clock::now();

			// �����ɏ���������
			//your_functor();
			//std::cout << "i=[" << i << "]" << std::endl;

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
	m_thread1.join(); // �X�^�[�g�������X���b�h���I������܂ŁA����ȏ�i�܂Ȃ��B
					  // �X���b�h���~�߂邩�A����Ɏ~�܂邩����Ɓ@��������ȉ��ɐi�ށB
}

void UtilTimer::Break_Force()
{
	m_thread1.detach();
	this->m_alive = false;
}

void UtilTimer::Sleep_Milliseconds(long milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
