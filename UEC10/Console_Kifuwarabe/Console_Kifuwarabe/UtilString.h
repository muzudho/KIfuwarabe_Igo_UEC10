#pragma once

#include <string>

/**
 * �Q�� : �ustd::string �̑O��̗]���ȋ󔒕�������菜���v (C++ �v���O���~���O) http://program.station.ez-net.jp/special/handbook/cpp/string/trim.asp
 */
namespace UtilString
{
	std::string Trim(const std::string& string, const char* trimCharacterList = " \t\v\r\n");
}

