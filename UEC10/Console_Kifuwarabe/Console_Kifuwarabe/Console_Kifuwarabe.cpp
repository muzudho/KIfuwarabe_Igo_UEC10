// Console_Kifuwarabe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "UtilFile.h"
#include "UtilTimer.h"
#include "UtilString.h"
#include <windows.h>	// �R���\�[���ւ̏o�͓�
using namespace std::literals; // ���Ԃ̕\�L���g�����邽�߂��́B

namespace Kifuwarabe
{
	const std::string filename_move = "_log_move.txt";
}

/**
 * �w�莞�ԊԊu�Ŏ��s�����������������N���X
 *
 * �Q�� : �u�t�@�C����f�B���N�g���̑��݊m�F���s�����@�v (�����āIgoo) https://oshiete.goo.ne.jp/qa/3399080.html
 * �Q�� : �uFAQ: Cannot convert from 'const char [..]' to 'LPCTSTR'�v (Visual Studio) https://social.msdn.microsoft.com/Forums/vstudio/en-US/c1b08c0a-a803-41c3-ac8c-84eba3be1ddb/faq-cannot-convert-from-const-char-to-lpctstr?forum=vclanguage
 */
class ReaderWorker : public DefaultWorker
{
public:
	ReaderWorker() : DefaultWorker()
	{
		std::cout << "�T�u�N���X�̃R���X�g���N�^�[�A�Ă�ł�̂��������i�O�`�O�j�H" << std::endl;
	}

	void OnStep()
	{
		std::string contents;
		if (UtilFile::Read(Kifuwarabe::filename_move, contents)) {
			contents = UtilString::Trim(contents);
			std::cout << "�w�����[" << contents << "]�������i�O���O�j��" << std::endl;

		}
		else {
			std::cout << "�t�@�C��[" << Kifuwarabe::filename_move << "]�J���ˁ��i�O�`�O�j" << std::endl;
		}
	}
};

int main()
{
	std::cout << "Hello, World." << std::endl;

	// �t�@�C���Ǐ����e�X�g
	std::string filename = "_log_test.txt";
	UtilFile::Write(filename, "�ق��ف��i�O���O�j\n�ǂ��������i�O�`�O�j�H");
	std::string contents;
	if (UtilFile::Read(filename, contents)) {
		std::cout << contents << std::endl;
	}

	// �X���b�h�e�X�g
	UtilTimer timer;
	ReaderWorker* pWorker1 = new ReaderWorker();
	// �X���b�h�X�^�[�g�B
	timer.Start(pWorker1, 1000);
	// 10�b�o������@�X���b�h���~�߂悤���i�O�`�O�j
	UtilTimer::Sleep_Milliseconds(5000L);
	std::cout << "5�b�o�������ǁA�����Ă�́��i�O�`�O�j�H" << std::endl;
	UtilTimer::Sleep_Milliseconds(5000L);
	timer.Break_Force();
	delete pWorker1;


	// �����̓A���t�@�x�b�g�ɂ��遙�i�P���ōςށj I���΂��̂́@���Ȃ��Ƃ��킽���̓O�j���[��1.2(1995�N)�ł͌��������̂��炠��K���� �c�_�Ƌ�ʂ��邺���i�O���O�j
	std::cout	<< "  |ABCDEFGHJKLMNOPQRST|" << std::endl
				<< "--+-------------------+" << std::endl
				<< " 1|                   |" << std::endl
				<< " 2|                   |" << std::endl
				<< " 3|                   |" << std::endl
				<< " 4|                   |" << std::endl
				<< " 5|                   |" << std::endl
				<< " 6|                   |" << std::endl
				<< " 7|                   |" << std::endl
				<< " 8|                   |" << std::endl
				<< " 9|                   |" << std::endl
				<< "10|                   |" << std::endl
				<< "11|                   |" << std::endl
				<< "12|                   |" << std::endl
				<< "13|                   |" << std::endl
				<< "14|                   |" << std::endl
				<< "15|                   |" << std::endl
				<< "16|                   |" << std::endl
				<< "17|                   |" << std::endl
				<< "18|                   |" << std::endl
				<< "19|                   |" << std::endl
				<< "--+-------------------+" << std::endl
				<< "�����{�^���������������i�O���O�j" << std::endl;
	getchar();

    return 0;
}
