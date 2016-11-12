#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ConnectSupport.h"

void set_up(char*** board, int size_row, int size_col, int turns){
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

void PlayGame(char** gameBoard, int size_row, int size_col, int turns){
	turns = 1;
	int vrf,player_1_col, player_2_col;

	while(!GameOver(gameBoard,size_row,size_col)){
		//player 1 turn:
		do {
			printf("Enter a column between 0 and 2 to play in: ");
			vrf = scanf("%d",&player_1_col);
		} while (!(is_valid_formatting(vrf, 1))||!(is_valid_step(gameBoard,player_1_col,size_row))||player_1_col<0||player_1_col>=size_col);
		PutStep(gameBoard,player_1_col,'X',size_row);
		PrintBoard(gameBoard, size_row, size_col);
		//player 2 turn:
	}



	turns += 1;
}
void PutStep(char** gameBoard, int col, char piece, int size_row){
	int i;
	for (i = 0; i < size_row;++i){
		if (gameBoard[i][col] != '*'){
			continue;
		}
		else {
			gameBoard[i][col] = piece;
			break;
		}
	}
}
void PrintBoard(char** cheeseBoard, int size_row, int size_col){
	int i,j;
	for (i=size_row-1;i>-1;i--){
        printf("%d ",i);
        for (j = 0;j<size_col;j++){
            //if ()
            printf("%c ",cheeseBoard[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (j = 0; j<size_col;j++){
        printf("%d ",j);
    }
    printf("\n");

}

bool is_valid_formatting(int num_args_read, int num_args_needed){
	char new_line = '\n';
	bool is_valid = true;
	if(num_args_read != num_args_needed){
		is_valid = false;
	}


	do{
		scanf("%c", &new_line);
		if(!isspace(new_line)){
			is_valid = false;
		}
	}while(new_line != '\n');
	return is_valid;
}
bool is_valid_step(char** gameBoard, int player_1_col,int size_row){
	return (gameBoard[size_row][player_1_col]=='*')
}

bool GameOver(char** gameBoard, int size_row, int size_col){
	return （IsWon(gameBoard,size_row,size_col)||IsTied(gameBoard,size_row,size_col))
}
bool IsWon(char** gameBoard, int size_row, int size_col){
	return (horz_win(gameBoard,size_row,size_col)||vert_win(gameBoard,size_row,size_col))
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
				!IsWon(board, num_rows, num_cols);
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

int main(int argc, char* argv[]){
    int size_row;
    int size_col;
    int win_num;
    int turns = 0;
    char** gameBoard;
    if(argc < 4){
        printf("1.Not enough arguments entered\n");
        printf("2.Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    else if (argc > 4){
        printf("1.Too many arguments entered\n");
        printf("2.Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    else {
        sscanf(argv[1], "%d", &size_row);
		sscanf(argv[2], "%d", &size_col);
		sscanf(argv[3], "%d", &win_num);
    }
	set_up(&gameBoard,size_row,size_col,turns);
	PrintBoard(gameBoard,size_row,size_col);
    PlayGame(gameBoard,size_row,size_col,turns);

    return 0;
}
