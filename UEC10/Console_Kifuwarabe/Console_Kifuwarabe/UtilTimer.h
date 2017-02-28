#pragma once
#include <iostream>
#include <fstream>
//#include <atomic>
#include <thread>
#include <chrono>

/**
 * �w�莞�ԊԊu�Ŏ��s�����������������N���X
 */
class DefaultWorker
{
public:
	DefaultWorker()
	{
		std::cout << "�X�[�p�[�E�N���X�̃R���X�g���N�^�[�͂��ꂾ���ǁc�c���i�O�`�O�j" << std::endl;
	}

	virtual void OnStep() = 0;
	//virtual void OnStep()
	//{
	//	std::cout << "����OnStep()�͎��s���Ă͂����Ȃ������i���Q���j" << std::endl;
	//	// �Ȃ�ɂ����Ȃ������i�O���O�j
	//}

	///**
	// * �t�@���N�^�[�Ƃ����̂́A�N���X���̌���() ���Z�q��t�������̂ł��B
	// * �t�@���N�^�[�̈����� �����ɂ��Ă����Ă��������B
	// */
	//virtual void operator()()
	//{
	//	std::cout << "�X�[�p�[�N���X�̃t�@���N�^�[�Ȃ񂩌Ă�ł�́��i�O�`�O�j�H" << std::endl;
	//	// �Ȃ�ɂ����Ȃ������i�O���O�j
	//}
};

/**
 * �X���b�h�𗧂āA�e�L�X�g�t�@�C���̓��e���X�V����Ă��Ȃ����m�F���܂��B
 *
 * ���� : �u[C++] �^�C�}�[�A������R���\�[���E�A�v���P�[�V�����ŕʃX���b�h���Ă� (C#�v���O���}����)�v (Qiita) http://qiita.com/muzudho1/items/ff5e38e907b3e8bc51ef
 * �Q�� : �uc++�ň��Ԋu�Ŋ֐������s���������v (teratail) https://teratail.com/questions/27449
 * �Q�� : �ustd::thread::thread�v (C++����̓���T�C�g�ł�) http://kaworu.jpn.org/cpp/std::thread::thread
 * �Q�� : �ustd::this thread::sleep for�v (C++����̓���T�C�g�ł�) http://kaworu.jpn.org/cpp/std::this_thread::sleep_for
 * �Q�� : �uC++1z �����_���ł�*this�̃R�s�[�L���v�`���v (Faith and Brave - C++�ŗV�ڂ�) http://faithandbrave.hateblo.jp/entry/2016/04/27/191209
 * �Q�� : �uC++ �Ōp�������Ƃ��ɃT�u�N���X�̃����o�֐����ĂԂ��߂ɂ� virtual �����ĉ��z�֐��ɂ���v (sotarok�̂��׋�) http://d.hatena.ne.jp/strkpy/20100401/1270133069
 */
class UtilTimer
{
public:
	UtilTimer();
	~UtilTimer();

	/**
	 * �X���b�h���J�n���܂��B
	 */
	//template<typename Rep, typename Period, std::enable_if_t<!std::is_same<std::chrono::duration<Rep, Period>, std::chrono::milliseconds >::value, std::nullptr_t> = nullptr>
	//void Start(DefaultWorker* pWorker, std::chrono::duration<Rep, Period> time);
	void Start(DefaultWorker* pWorker, long milliseconds);
	/**
	 * �X�^�[�g�������X���b�h�������Ă���Ԃ́A�������ɐi�܂��܂���B
	 */
	void Block();
	/**
	 * �����̓r���ł��A�����I�ɃX���b�h���I�����܂��B
	 */
	void Break_Force();

	/**
	 * �i���̃N���X�̎��X���b�h�ł͂Ȃ��j���̊֐����Ăяo�����X���b�h���A�w��~���b��~�����܂��B
	 * �l�[���X�y�[�X��؂�̂��߂�ǂ������̂Ł@���̃N���X�ɒu���Ă���B
	 */
	static void Sleep_Milliseconds(long milliseconds);

protected:
	std::thread m_thread1;
	/**
	 * �X���b�h���~���Ă��A�����̃��[�v�͓��������Ă���悤�������̂ŁA
	 * ���̃t���O���U�ɂ��邱�ƂŁA�X���b�h�̒��̃��[�v���甲�������܂�
	 */
	bool m_alive;
	/**
	 * �ʃX���b�h�Ŏ��s���������������������\�b�h�������Ă��܂��B
	 */
	DefaultWorker* m_pWorker;
};
