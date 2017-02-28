#pragma once
#include <iostream>
#include <fstream>
#include <atomic>
#include <thread>
#include <chrono>

/**
 * スレッドを立て、テキストファイルの内容が更新されていないか確認します。
 * 参照 : 「c++で一定間隔で関数を実行させたい」 (teratail) https://teratail.com/questions/27449
 * 参照 : 「std::thread::thread」 (C++言語の入門サイトです) http://kaworu.jpn.org/cpp/std::thread::thread
 */
class FileListener
{
public:
	FileListener();
	~FileListener();

	/**
	 * スレッドを開始し、待機状態に入ります。
	 */
	void StartLoop();
	/**
	 * 処理の途中でも、強制的にスレッドを終了します。
	 */
	void BreakLoop_Force();

protected:
	std::thread m_thread1;
};

