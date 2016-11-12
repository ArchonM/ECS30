#include "win.h"

bool is_game_over(char** board, int num_rows, int num_cols){
	return won(board, num_rows, num_cols) || 
				tied(board, num_rows, num_cols);
}

bool won(char** board, int num_rows, int num_cols){
	return horz_win(board, num_rows, num_cols) || 
				 vert_win(board, num_rows, num_cols) || 
				 diag_win(board, num_rows, num_cols);
}

bool horz_win(char** board, int num_rows, int num_cols){
	int i;
	
	for(i = 0; i < num_rows; ++i){
		if(board[i][0] == '*'){
			continue;
		}
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
			return true;
		}
	}
	return false;
}

bool vert_win(char** board, int num_rows, int num_cols){
	int i, j;
	char first_piece;
	bool winner;
	
	for(i = 0; i < num_cols; ++i){
		first_piece = board[0][i];
		winner = true;
		if(first_piece == '*'){
			continue;
		}
		for(j = 0; j < num_rows; ++j){
			if(first_piece != board[j][i]){
				winner = false;
				break;
			}
		}//all the elements in a column
		if(winner){
			return true;
		}
	}
	return false;
}

bool diag_win(char** board, int num_rows, int num_cols){
	return left_diag_win(board, num_rows, num_cols) || 
				 right_diag_win(board, num_rows, num_cols);
}


bool left_diag_win(char** board, int num_rows, int num_cols){
int i;

	if(board[0][0] == '*'){
		return false;
	}
	
	for(i = 1; i < num_rows; ++i){
		if(board[i][i] != board[0][0]){
			return false;
		}
	}
	return true;

}

bool right_diag_win(char** board, int num_rows, int num_cols){
int i;

	if(board[0][num_cols - 1] == '*'){
		return false;
	}
	
	for(i = 1; i < num_rows; ++i){
		if(board[i][num_cols - i - 1] != board[0][num_cols - 1]){
			return false;
		}
	}
	return true;

}

bool tied(char** board, int num_rows, int num_cols){
	return is_board_full(board, num_rows, num_cols) && 
				!won(board, num_rows, num_cols);
}

bool is_board_full(char** board, int num_rows, int num_cols){
	int i, j;
	
	for(i = 0; i < num_rows; ++i){
		for(j = 0; j < num_cols; ++j){
			if(board[i][j] == '*'){
				return false;
			}
		}
	}
	return true;

}


