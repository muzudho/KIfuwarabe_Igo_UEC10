#include "stdafx.h"
#include "UtilFile.h"


UtilFile::UtilFile()
{
}


UtilFile::~UtilFile()
{
}


void UtilFile::Write(std::string filename, std::string contents)
{
	std::ofstream writing_file;
	writing_file.open(filename, std::ios::out);

	writing_file << contents;
}


std::string UtilFile::Read(std::string filename)
{
	// �t�@�C���̓��e�S��
	std::string contents;

	std::ifstream file;
	file.open(filename, std::ios::in);

	std::string line;
	while (!file.eof())
	{
		// 1�s���ǂݎ��܂�
		std::getline(file, line);
		contents += line;

		// ���s������Ȃ���s��ǉ�
		if (file.eof()) { contents += "\n"; }
	}

	return contents;
}
