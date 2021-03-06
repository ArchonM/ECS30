#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "gameboard.h"

void set_up(char*** board, int size_row, int size_col, int turns){
	if (size_row < 3 || size_col < 3) {
        exit(0);
    }
	*board = make_board(size_row, size_col);
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

void PlayGame(char** gameBoard, int size_row, int size_col, int turns, int win_num){
	turns = 1;
	int vrf = 0;
	int player_1_col=0;
	int player_2_col=0;
	int player_1_row=0;
	int player_2_row=0;


	while(!GameOver(gameBoard,size_row,size_col,win_num, player_1_row, player_1_col)){
		player_1_col = 0;
		player_2_col = 0;
		//player 1 turn:
		do {
			printf("Enter column for red coin: ");
			vrf = scanf("%d",&player_1_col);
			if(!(is_valid_step(gameBoard,player_1_col,size_row))){
				if (player_1_col > size_col){
        			exit(0);
				}
				printf("Column %d is full\n",player_1_col);
				PrintBoard(gameBoard, size_row, size_col);
			}
		} while (!(is_valid_formatting(vrf, 1))||!(is_valid_step(gameBoard,player_1_col,size_row))||player_1_col<0||player_1_col>=size_col);
		vrf = 0;
		player_1_row=PutStep(gameBoard,player_1_col,'X',size_row);
		PrintBoard(gameBoard, size_row, size_col);
		if (IsTied(gameBoard,size_row,size_col,win_num,player_1_row,player_1_col)){
			printf("Game over: tie.\n");
			exit(0);
		}
		else if (IsWon(gameBoard,size_row,size_col,win_num,player_1_row,player_1_col)){
			printf("Game over: red wins.\n");
			exit(0);
		}
		//player 2 turn:
		do {
			printf("Enter column for yellow coin: ");
			vrf = scanf("%d",&player_2_col);
			if(!(is_valid_step(gameBoard,player_2_col,size_row))){
				if (player_2_col > size_col){
        			exit(0);
				}
				printf("Column %d is full\n",player_2_col);
				PrintBoard(gameBoard, size_row, size_col);
			}
		} while (!(is_valid_formatting(vrf, 1))||!(is_valid_step(gameBoard,player_2_col,size_row))||player_2_col<0||player_2_col>=size_col);
		vrf = 0;
		player_2_row=PutStep(gameBoard,player_2_col,'O',size_row);
		PrintBoard(gameBoard, size_row, size_col);
		if (IsTied(gameBoard,size_row,size_col,win_num,player_2_row,player_2_col)){
			printf("Game over: tie.\n");
			exit(0);
		}
		else if (IsWon(gameBoard,size_row,size_col,win_num,player_2_row,player_2_col)){
			printf("Game over: yellow wins.\n");
			exit(0);
		}
		turns += 1;
	}



}
int PutStep(char** gameBoard, int col, char piece, int size_row){
	int i;
	for (i = 0; i < size_row;i++){
		if (gameBoard[i][col] != '*'){
			continue;
		}
		else {
			gameBoard[i][col] = piece;
			break;
		}
	}
	return i;
}
void PrintBoard(char** board, int size_row, int size_col){
	for (int i=size_row-1;i>-1;i--) {
        for (int j = 0; j < size_col; j++) {
            switch (board[i][j]) {
                case '*':
                    printf("  ");
                    break;
                case 'X':
                    printf("R ");
                    break;
                case 'O':
                    printf("Y ");
                    break;
            }
        }
        printf("\n");
    }
    for (int j = 0; j < size_col - 1; j++) {
        printf("==");
    }
    printf("=\n");
}

bool is_valid_formatting(int num_args_read, int num_args_needed){
	char new_line = '\n';
	bool is_valid = true;
	if(num_args_read != num_args_needed){
		return false;
	}


	do{
		scanf("%c", &new_line);
		if(!isspace(new_line)){
			is_valid = false;
		}
	}while(new_line != '\n');
	return is_valid;
}
bool is_valid_step(char** gameBoard, int player_col,int size_row){
	return (gameBoard[size_row-1][player_col]=='*');
}

bool GameOver(char** gameBoard, int size_row, int size_col,int win_num, int playerRowStep, int playerColStep){
	return (IsWon(gameBoard,size_row,size_col,win_num,playerRowStep,playerColStep)||IsTied(gameBoard,size_row,size_col,win_num,playerRowStep,playerColStep));
}
bool IsWon(char** gameBoard, int size_row, int size_col,int win_num, int playerRowStep, int playerColStep){
	if (gameBoard[playerRowStep][playerColStep] == '*'){
		return false;
	}
	/*if(horz_win(gameBoard,size_row,size_col,win_num,playerRowStep,playerColStep)){
		printf("\n\nhorz_win\n\n");
	}
	else if(vert_win(gameBoard,size_row,size_col,win_num,playerRowStep,playerColStep)){
		printf("\n\nvert-win\n\n");
	}
	else if(right_diag_win(gameBoard,size_row,size_col,win_num,playerRowStep,playerColStep)){
		printf("\n\nright_diag_win\n\n");
	}
	else if(left_diag_win(gameBoard,size_row,size_col,win_num,playerRowStep,playerColStep)){
		printf("\n\nleft_diag_win\n\n");
	}*/
	return (horz_win(gameBoard,size_row,size_col,win_num,playerRowStep,playerColStep)||vert_win(gameBoard,size_row,size_col,win_num,playerRowStep,playerColStep)||left_diag_win(gameBoard,size_row,size_col,win_num,playerRowStep,playerColStep)||right_diag_win(gameBoard,size_row,size_col,win_num,playerRowStep,playerColStep));
}
bool horz_win(char** board, int num_rows, int num_cols, int win_num, int playerRowStep, int playerColStep){
	int i;
	int n = 0;
	if(board[playerRowStep][playerColStep] == '*'){
		return false;
	}

	for(i = 1; i < num_cols; ++i){
		if ((playerColStep-i >= 0)&&(board[playerRowStep][playerColStep] == board[playerRowStep][playerColStep-i])){
			n += 1;
		}
		else {
			break;
		}
	}
	for(i = 1; i < num_cols; ++i){
		if ((playerColStep+i < num_cols)&&(board[playerRowStep][playerColStep] == board[playerRowStep][playerColStep+i])){
			n += 1;
		}
		else {
			break;
		}
	}
	n += 1;
	return (n >= win_num);
}
bool vert_win(char** board, int num_rows, int num_cols, int win_num, int playerRowStep, int playerColStep){
	int i;
	int n = 0;
	if(board[playerRowStep][playerColStep] == '*'){
		return false;
	}
	for(i = 1; i < num_cols; ++i){
		if ((playerRowStep-i >= 0)&&(board[playerRowStep][playerColStep] == board[playerRowStep-i][playerColStep])){
			n += 1;
		}
		else {
			break;
		}
	}
	for(i = 1; i < num_rows; ++i){
		if ((playerRowStep+i < num_rows)&&(board[playerRowStep][playerColStep] == board[playerRowStep+i][playerColStep])){
			n += 1;
		}
		else {
			break;
		}
	}

	n += 1;
	return (n >= win_num);
}
bool left_diag_win(char** board, int num_rows, int num_cols, int win_num, int playerRowStep, int playerColStep){
	int i;
	int n = 0;
	if(board[playerRowStep][playerColStep] == '*'){
		return false;
	}
	for(i = 1; i < num_cols; ++i){
		if ((playerRowStep-i >= 0)&&(playerColStep-i >= 0)&&(board[playerRowStep][playerColStep] == board[playerRowStep-i][playerColStep-i])){
			n += 1;
		}
		else {
			break;
		}
	}
	for(i = 1; i < num_rows; ++i){
		if ((playerRowStep+i < num_rows)&&(playerColStep+i < num_cols)&&(board[playerRowStep][playerColStep] == board[playerRowStep+i][playerColStep+i])){
			n += 1;
		}
		else {
			break;
		}
	}

	n += 1;
	return (n >= win_num);
}
bool right_diag_win(char** board, int num_rows, int num_cols, int win_num, int playerRowStep, int playerColStep){
	int i;
	int n = 0;
	if(board[playerRowStep][playerColStep] == '*'){
		return false;
	}
	for(i = 1; i < num_cols; ++i){
		if ((playerRowStep-i >= 0)&&(playerColStep-i >= 0)&&(board[playerRowStep][playerColStep] == board[playerRowStep-i][playerColStep+i])){
			n += 1;
		}
		else {
			break;
		}
	}
	for(i = 1; i < num_rows; ++i){
		if ((playerRowStep+i < num_rows)&&(playerColStep+i < num_cols)&&(board[playerRowStep][playerColStep] == board[playerRowStep+i][playerColStep-i])){
			n += 1;
		}
		else {
			break;
		}
	}

	n += 1;
	return (n >= win_num);
}

bool IsTied(char** board, int num_rows, int num_cols, int win_num, int playerRowStep, int playerColStep){
	return is_board_full(board, num_rows, num_cols) &&
				!IsWon(board, num_rows, num_cols,win_num,playerRowStep,playerColStep);
}

bool is_board_full(char** board, int num_rows, int num_cols){
	int i;
	for (i = 0; i < num_cols; ++i){
		if (board[num_rows-1][i] == '*'){
			return false;
		}
	}
	return true;

}
