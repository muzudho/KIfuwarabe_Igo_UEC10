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
		//std::cout << "ファイル[" << filename << "]が開けなかった☆（＾～＾）！オワタ～☆（＞＿＜）" << std::endl;
		return false;
	}

	std::string line;
	while (!file.eof())
	{
		// 1行ずつ読み取ります
		std::getline(file, line);
		contents += line;

		// 次行があるなら改行を追加
		if (file.eof()) { contents += "\n"; }
	}

	return true;
}
