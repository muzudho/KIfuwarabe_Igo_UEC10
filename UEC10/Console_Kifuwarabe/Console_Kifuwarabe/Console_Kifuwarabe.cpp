// Console_Kifuwarabe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "UtilFile.h"
#include "FileListener.h"

int main()
{
	std::cout << "Hello, World." << std::endl;

	// �t�@�C���Ǐ����e�X�g
	UtilFile::Write("test.txt", "�ق��ف��i�O���O�j\n�ǂ��������i�O�`�O�j�H");
	std::string contents = UtilFile::Read("test.txt");
	std::cout << contents << std::endl;

	// �X���b�h�e�X�g
	FileListener fileListener;
	fileListener.StartLoop();

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
	//system("pause");

    return 0;
}
