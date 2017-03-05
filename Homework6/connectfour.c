#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "gameboard.h"
void gameboard_play(gameboard* board, int rows, int cols, square color);
int main() {
    printf("Enter the number of rows and columns of your gameboard: ");
    int rows, cols, usrcol;
    scanf("%d %d", &rows, &cols);
    gameboard* board = gameboard_create(rows, cols);
    gameboard_print(board);
    // Homework TODO: complete this function
    while (gameboard_still_playing(board)){
        if(gameboard_still_playing(board)){
            printf("Enter column for red coin: ");
            scanf("%d",&usrcol);
            gameboard_insert_coin(board,usrcol,0);
            gameboard_print(board);
            gameboard_check_square(board);
        }
        if(gameboard_still_playing(board)){
            printf("Enter column for red coin: ");
            scanf("%d",&usrcol);
            gameboard_insert_coin(board,usrcol,0);
            gameboard_print(board);
            gameboard_check_square(board);
        }
    }
    gameboard_declare_winner(board);

    gameboard_destroy(board);
}
