// Console_Kifuwarabe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "UtilFile.h"
#include "UtilTimer.h"
#include "UtilString.h"
#include <windows.h>	// コンソールへの出力等
using namespace std::literals; // 時間の表記を拡張するためもの。

namespace Kifuwarabe
{
	const std::string filename_move = "_log_move.txt";
}

/**
 * 指定時間間隔で実行したい処理を書くクラス
 *
 * 参照 : 「ファイルやディレクトリの存在確認を行う方法」 (教えて！goo) https://oshiete.goo.ne.jp/qa/3399080.html
 * 参照 : 「FAQ: Cannot convert from 'const char [..]' to 'LPCTSTR'」 (Visual Studio) https://social.msdn.microsoft.com/Forums/vstudio/en-US/c1b08c0a-a803-41c3-ac8c-84eba3be1ddb/faq-cannot-convert-from-const-char-to-lpctstr?forum=vclanguage
 */
class ReaderWorker : public DefaultWorker
{
public:
	ReaderWorker() : DefaultWorker()
	{
		std::cout << "サブクラスのコンストラクター、呼んでるのかだぜ☆（＾～＾）？" << std::endl;
	}

	void OnStep()
	{
		std::string contents;
		if (UtilFile::Read(Kifuwarabe::filename_move, contents)) {
			contents = UtilString::Trim(contents);
			std::cout << "指し手は[" << contents << "]だぜ☆（＾▽＾）ｖ" << std::endl;

		}
		else {
			std::cout << "ファイル[" << Kifuwarabe::filename_move << "]開けね☆（＾～＾）" << std::endl;
		}
	}
};

int main()
{
	std::cout << "Hello, World." << std::endl;

	// ファイル読書きテスト
	std::string filename = "_log_test.txt";
	UtilFile::Write(filename, "ほっほ☆（＾▽＾）\nどうだぜ☆（＾～＾）？");
	std::string contents;
	if (UtilFile::Read(filename, contents)) {
		std::cout << contents << std::endl;
	}

	// スレッドテスト
	UtilTimer timer;
	ReaderWorker* pWorker1 = new ReaderWorker();
	// スレッドスタート。
	timer.Start(pWorker1, 1000);
	// 10秒経ったら　スレッドを止めよう☆（＾～＾）
	UtilTimer::Sleep_Milliseconds(5000L);
	std::cout << "5秒経ったけど、動いてんの☆（＾～＾）？" << std::endl;
	UtilTimer::Sleep_Milliseconds(5000L);
	timer.Break_Force();
	delete pWorker1;


	// 横軸はアルファベットにする☆（１桁で済む） Iを飛ばすのは　少なくともわたしはグニュー碁1.2(1995年)では見かけた昔からある習慣☆ 縦棒と区別するぜ☆（＾▽＾）
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
				<< "何かボタンを押せだぜ☆（＾▽＾）" << std::endl;
	getchar();

    return 0;
}
