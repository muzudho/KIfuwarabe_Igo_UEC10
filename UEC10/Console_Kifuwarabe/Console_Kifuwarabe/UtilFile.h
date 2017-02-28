#pragma once

#include <iostream>
#include <string>
#include <fstream>

/**
 * テキストファイルの読書き
 * 参照 : 「[C++] ファイル入出力の覚書」 (Qiita) http://qiita.com/lazynick/items/8aede589bb9ca0c8b64f
 * 参照 : 「文字列の結合方法による速度差」 (Qiita) http://qiita.com/ampersand/items/0322e0820badf2c020be
 * 参照 : 空文字列で初期化するには : 「文字列の初期化」 (手を動かしてさくさく理解する C++ 文字列クラス std::string 入門) http://vivi.dyndns.org/tech/cpp/string.html
 */
class UtilFile
{
public:
	UtilFile();
	~UtilFile();

	static void Write(std::string filename, std::string contents);

	static std::string Read(std::string filename);
};

