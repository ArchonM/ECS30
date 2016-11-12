#include <stdlib.h>
#include "board.h"

void set_up(char*** board, int *turn){
	const int size = 3;
	*board = make_board(size, size);
	*turn = 0;
}

char** make_board(int num_rows, int num_cols){
	
	char** board = (char**)malloc(num_rows * sizeof(char*));
	int i, j;
	
	for(i = 0; i < num_rows; ++i){
		board[i] = (char*)malloc(num_cols*sizeof(char));
		for(j = 0; j < num_cols; ++j){
			board[i][j] = '*';
		}
	}
	return board;
}

void print_board(char** board, int num_rows, int num_cols){
	int i,j;
	
	for(i = 0; i < num_rows; ++i){
		for(j = 0; j < num_cols; ++j){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
