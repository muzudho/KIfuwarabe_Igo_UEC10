#include "stdafx.h"
#include "FileListener.h"

FileListener::FileListener()
{
}


FileListener::~FileListener()
{
}

/**
 * �X���b�h�̒��Ŏ��s���܂��B
 */
void do_worker() {
}

void FileListener::StartLoop()
{
	m_thread1 = std::thread([] {
		// �����Ə����̊Ԃ�1�b�ȏ�󂯂�B�i����P�b�Ԋu�ۏ�Ȃ̂ŁA�P�b���ɒ���I�ɃX�^�[�g�����Ƃ����Ӗ��ł͂Ȃ��j
		const std::chrono::milliseconds interval(1000);
		for (int i=0;i<10;i++) {
		//for (;;) {
			auto start = std::chrono::system_clock::now();

			// �����ɏ���������
			do_worker();
			std::cout << "i=[" << i << "]" << std::endl;

			auto end = std::chrono::system_clock::now();
			auto elapsed = end - start;

			// ����A�C���^�[�o�����Ԃ̃X���[�v��ۏ�
			if (elapsed < interval) {
				std::this_thread::sleep_for(interval - elapsed);
			}
		}
	});

	m_thread1.join(); // �X���b�ht2�̏������I������܂ŁA����ȏ�i�܂Ȃ�
	// �X���b�h���~�߂邩�A����Ɏ~�܂邩����Ɓ@��������ȉ��ɐi�ށB

	std::cout << "finished." << std::endl;
}

void FileListener::BreakLoop_Force()
{
	m_thread1.detach();
}
