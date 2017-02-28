#include "stdafx.h"
#include "UtilTimer.h"

UtilTimer::UtilTimer()
{
}


UtilTimer::~UtilTimer()
{
}

/**
 * ファンクターというのは、クラス名の後ろに ( ) 演算子を付けたものです。
 * ファンクターの引数は 無しにしておいてください。
 */
void UtilTimer::Start(DefaultWorker your_functor, long milliseconds)
{
	m_alive = true;
	m_thread1 = std::thread([=,&your_functor,&milliseconds] {
		// 処理と処理の間を1秒以上空ける。（毎回１秒間隔保障なので、１秒毎に定期的にスタートされるという意味ではない）
		const std::chrono::milliseconds interval(milliseconds);
		//for (int i=0;i<10;i++) {
		while (this->m_alive) {
			
			auto start = std::chrono::system_clock::now();

			// ここに処理を書く
			//your_functor();
			//std::cout << "i=[" << i << "]" << std::endl;

			auto end = std::chrono::system_clock::now();
			auto elapsed = end - start;
			std::cout << "elapsed.count()=[" << elapsed.count() << "]" << std::endl;

			// 毎回、インターバル時間のスリープを保障
			if (elapsed < interval) {
				std::this_thread::sleep_for(interval - elapsed);
			}
		}

		std::cout << "finished." << std::endl;
	});
}

void UtilTimer::Block()
{
	m_thread1.join(); // スタートさせたスレッドが終了するまで、これ以上進まない。
					  // スレッドを止めるか、勝手に止まるかすると　ここから以下に進む。
}

void UtilTimer::Break_Force()
{
	m_thread1.detach();
	this->m_alive = false;
}

void UtilTimer::Sleep_Milliseconds(long milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
