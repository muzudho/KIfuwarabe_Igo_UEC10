#include "stdafx.h"
#include "FileListener.h"

FileListener::FileListener()
{
}


FileListener::~FileListener()
{
}

/**
 * スレッドの中で実行します。
 */
void do_worker() {
}

void FileListener::StartLoop()
{
	m_thread1 = std::thread([] {
		// 処理と処理の間を1秒以上空ける。（毎回１秒間隔保障なので、１秒毎に定期的にスタートされるという意味ではない）
		const std::chrono::milliseconds interval(1000);
		for (int i=0;i<10;i++) {
		//for (;;) {
			auto start = std::chrono::system_clock::now();

			// ここに処理を書く
			do_worker();
			std::cout << "i=[" << i << "]" << std::endl;

			auto end = std::chrono::system_clock::now();
			auto elapsed = end - start;

			// 毎回、インターバル時間のスリープを保障
			if (elapsed < interval) {
				std::this_thread::sleep_for(interval - elapsed);
			}
		}
	});

	m_thread1.join(); // スレッドt2の処理が終了するまで、これ以上進まない
	// スレッドを止めるか、勝手に止まるかすると　ここから以下に進む。

	std::cout << "finished." << std::endl;
}

void FileListener::BreakLoop_Force()
{
	m_thread1.detach();
}
