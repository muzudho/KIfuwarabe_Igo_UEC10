#include "stdafx.h"
#include "UtilFile.h"


void UtilFile::Write(std::string filename, std::string contents)
{
	std::ofstream writing_file;
	writing_file.open(filename);

	writing_file << contents;
}


bool UtilFile::Read(std::string filename, std::string& contents)
{
	std::ifstream file;
	file.open(filename);
	if (file.fail())
	{
		//std::cout << "�t�@�C��[" << filename << "]���J���Ȃ��������i�O�`�O�j�I�I���^�`���i���Q���j" << std::endl;
		return false;
	}

	std::string line;
	while (!file.eof())
	{
		// 1�s���ǂݎ��܂�
		std::getline(file, line);
		contents += line;

		// ���s������Ȃ���s��ǉ�
		if (file.eof()) { contents += "\n"; }
	}

	return true;
}
