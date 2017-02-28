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
	// ファイルの内容全文
	std::string contents;

	std::ifstream file;
	file.open(filename, std::ios::in);

	std::string line;
	while (!file.eof())
	{
		// 1行ずつ読み取ります
		std::getline(file, line);
		contents += line;

		// 次行があるなら改行を追加
		if (file.eof()) { contents += "\n"; }
	}

	return contents;
}
