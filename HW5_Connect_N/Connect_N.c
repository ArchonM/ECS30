#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ConnectSupport.h"
//#include "ConnectSupport.c"



int main(int argc, char* argv[]){
    int size_row;
    int size_col;
    int win_num;
    int turns = 0;
    char** gameBoard;
    if(argc < 4){
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    else if (argc > 4){
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    else {
        sscanf(argv[1], "%d", &size_row);
		sscanf(argv[2], "%d", &size_col);
		sscanf(argv[3], "%d", &win_num);
    }
	set_up(&gameBoard,size_row,size_col,turns);
	PrintBoard(gameBoard,size_row,size_col);
    PlayGame(gameBoard,size_row,size_col,turns,win_num);
    free(gameBoard);
    return 0;
}
