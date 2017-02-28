#pragma once

#include <string>

/**
 * 参照 : 「std::string の前後の余分な空白文字を取り除く」 (C++ プログラミング) http://program.station.ez-net.jp/special/handbook/cpp/string/trim.asp
 */
namespace UtilString
{
	std::string Trim(const std::string& string, const char* trimCharacterList = " \t\v\r\n");
}

