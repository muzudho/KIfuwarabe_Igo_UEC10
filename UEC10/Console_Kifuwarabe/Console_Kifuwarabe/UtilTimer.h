#pragma once
#include <iostream>
#include <fstream>
#include <atomic>
#include <thread>
#include <chrono>

/**
* �ʃX���b�h�Ŏ��s����鏈���� ( ) ���Z�q�ɏ����ꂽ�N���X�B
*/
class DefaultWorker
{
public:
	virtual void operator()()
	{
		// �Ȃ�ɂ����Ȃ������i�O���O�j
	}
};

/**
 * �X���b�h�𗧂āA�e�L�X�g�t�@�C���̓��e���X�V����Ă��Ȃ����m�F���܂��B
 * �Q�� : �uc++�ň��Ԋu�Ŋ֐������s���������v (teratail) https://teratail.com/questions/27449
 * �Q�� : �ustd::thread::thread�v (C++����̓���T�C�g�ł�) http://kaworu.jpn.org/cpp/std::thread::thread
 * �Q�� : �ustd::this thread::sleep for�v (C++����̓���T�C�g�ł�) http://kaworu.jpn.org/cpp/std::this_thread::sleep_for
 */
class UtilTimer
{
public:
	UtilTimer();
	~UtilTimer();

	/**
	 * �X���b�h���J�n���܂��B
	 */
	void Start(DefaultWorker your_functor, long milliseconds);
	/**
	 * �X�^�[�g�������X���b�h�������Ă���Ԃ́A�������ɐi�܂��܂���B
	 */
	void Block();
	/**
	 * �����̓r���ł��A�����I�ɃX���b�h���I�����܂��B
	 */
	void Break_Force();

	/**
	 * ���̊֐����Ăяo�����X���b�h���A�w��~���b��~�����܂��B
	 */
	static void Sleep_Milliseconds(long milliseconds);

protected:
	std::thread m_thread1;
	bool m_alive;
};
