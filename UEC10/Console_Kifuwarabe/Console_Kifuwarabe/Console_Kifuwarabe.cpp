// Console_Kifuwarabe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "UtilFile.h"
#include "UtilTimer.h"

/**
 * 別スレッドで実行される処理が ( ) 演算子に書かれたクラス。
 */
class Worker : public DefaultWorker
{
public:
	void operator()()
	{
		std::cout << "別スレッドで実行中だぜ☆（＾▽＾）ｖ" << std::endl;
	}
};

int main()
{
	std::cout << "Hello, World." << std::endl;

	// ファイル読書きテスト
	UtilFile::Write("test.txt", "ほっほ☆（＾▽＾）\nどうだぜ☆（＾～＾）？");
	std::string contents = UtilFile::Read("test.txt");
	std::cout << contents << std::endl;

	// スレッドテスト
	UtilTimer timer;
	Worker worker;
	timer.Start(worker,1000);
	// 10秒経ったら　スレッドを止めよう☆（＾～＾）
	UtilTimer::Sleep_Milliseconds(5000L);
	std::cout << "5秒経ったけど、動いてんの☆（＾～＾）？" << std::endl;
	UtilTimer::Sleep_Milliseconds(5000L);
	timer.Break_Force();

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
	//system("pause");

    return 0;
}
