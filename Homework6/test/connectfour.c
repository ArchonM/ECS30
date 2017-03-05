#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "gameboard.h"



int main(){
    int size_row;
    int size_col;
    int win_num;
    int turns = 0;
    char** gameBoard;
    win_num = 4;
    printf("Enter the number of rows and columns of your gameboard: ");
    scanf("%d %d", &size_row, &size_col);

	set_up(&gameBoard,size_row,size_col,turns);
	PrintBoard(gameBoard,size_row,size_col);
    PlayGame(gameBoard,size_row,size_col,turns,win_num);
    free(gameBoard);
    return 0;
}
