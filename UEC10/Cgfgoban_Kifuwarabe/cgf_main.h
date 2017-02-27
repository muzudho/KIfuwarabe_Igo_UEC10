#pragma once

/*
// 2016-03-16 05:23 Add 「__declspec(dllimport)」を追加。
// 初期盤面、棋譜(消費時間)、手数、手番、盤面のサイズ、コミ
//extern "C"
__declspec(dllimport) int cgfgui_thinking( // int (*cgfgui_thinking)(
	int init_board[],	// 初期盤面
	int kifu[][3],		// 棋譜  [][0]...座標、[][1]...石の色、[][2]...消費時間（秒)
	int tesuu,			// 手数
	int black_turn,		// 手番(黒番...1、白番...0)
	int board_size,		// 盤面のサイズ
	double komi,		// コミ
	int endgame_type,	// 0...通常の思考、1...終局処理、2...図形を表示、3...数値を表示。
	int endgame_board[]	// 終局処理の結果を代入する。
	);


// 2016-03-16 05:23 Add 「__declspec(dllimport)」を追加。
// 対局開始時に一度だけ呼ばれます。
//extern "C"
__declspec(dllimport) void cgfgui_thinking_init(int *ptr_stop_thinking);


// 2016-03-16 05:23 Add 「__declspec(dllimport)」を追加。
// 対局終了時に一度だけ呼ばれます。
//extern "C"
__declspec(dllimport) void cgfgui_thinking_close(void);
*/