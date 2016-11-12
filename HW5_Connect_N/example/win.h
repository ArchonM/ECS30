#ifndef WIN_H
	#define WIN_H
	#include <stdbool.h>
	
	bool is_game_over(char** board, int num_rows, int num_cols);
	bool won(char** board, int num_rows, int num_cols);
	bool horz_win(char** board, int num_rows, int num_cols);
	bool vert_win(char** board, int num_rows, int num_cols);
	bool diag_win(char** board, int num_rows, int num_cols);
#endif
