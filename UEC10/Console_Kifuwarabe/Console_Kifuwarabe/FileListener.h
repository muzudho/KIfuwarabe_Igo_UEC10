#pragma once
#include <iostream>
#include <fstream>
#include <atomic>
#include <thread>
#include <chrono>

/**
 * �X���b�h�𗧂āA�e�L�X�g�t�@�C���̓��e���X�V����Ă��Ȃ����m�F���܂��B
 * �Q�� : �uc++�ň��Ԋu�Ŋ֐������s���������v (teratail) https://teratail.com/questions/27449
 * �Q�� : �ustd::thread::thread�v (C++����̓���T�C�g�ł�) http://kaworu.jpn.org/cpp/std::thread::thread
 */
class FileListener
{
public:
	FileListener();
	~FileListener();

	/**
	 * �X���b�h���J�n���A�ҋ@��Ԃɓ���܂��B
	 */
	void StartLoop();
	/**
	 * �����̓r���ł��A�����I�ɃX���b�h���I�����܂��B
	 */
	void BreakLoop_Force();

protected:
	std::thread m_thread1;
};

