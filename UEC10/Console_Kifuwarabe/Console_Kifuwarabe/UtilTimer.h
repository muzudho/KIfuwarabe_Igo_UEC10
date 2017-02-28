#pragma once
#include <iostream>
#include <fstream>
#include <atomic>
#include <thread>
#include <chrono>

/**
* 別スレッドで実行される処理が ( ) 演算子に書かれたクラス。
*/
class DefaultWorker
{
public:
	virtual void operator()()
	{
		// なんにもしないぜ☆（＾▽＾）
	}
};

/**
 * スレッドを立て、テキストファイルの内容が更新されていないか確認します。
 * 参照 : 「c++で一定間隔で関数を実行させたい」 (teratail) https://teratail.com/questions/27449
 * 参照 : 「std::thread::thread」 (C++言語の入門サイトです) http://kaworu.jpn.org/cpp/std::thread::thread
 * 参照 : 「std::this thread::sleep for」 (C++言語の入門サイトです) http://kaworu.jpn.org/cpp/std::this_thread::sleep_for
 */
class UtilTimer
{
public:
	UtilTimer();
	~UtilTimer();

	/**
	 * スレッドを開始します。
	 */
	void Start(DefaultWorker your_functor, long milliseconds);
	/**
	 * スタートさせたスレッドが動いている間は、処理を先に進ませません。
	 */
	void Block();
	/**
	 * 処理の途中でも、強制的にスレッドを終了します。
	 */
	void Break_Force();

	/**
	 * この関数を呼び出したスレッドを、指定ミリ秒停止させます。
	 */
	static void Sleep_Milliseconds(long milliseconds);

protected:
	std::thread m_thread1;
	bool m_alive;
};
