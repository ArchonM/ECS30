#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "gameboard.h"
void gameboard_play(gameboard* board, int rows, int cols, square color);
int main() {
    printf("Enter the number of rows and columns of your gameboard: ");
    int rows, cols, usrcol;
    bool vrf;
    square color;
    player usrid;
    scanf("%d %d", &rows, &cols);
    gameboard* board = gameboard_create(rows, cols);
    gameboard_print(*board);
    // Homework TODO: complete this function
    while (gameboard_still_playing(*board)){
        //player 1 turn
        if(gameboard_still_playing(*board)){
            usrid = RED_PLAYER;
            color = RED_COIN;
            printf("Enter column for red coin: ");
            scanf("%d",&usrcol);
            vrf = gameboard_insert_coin(board,usrcol,usrid);
            gameboard_print(*board);
            if (board->coinsInBoard == rows*cols){
                board->state = TIE;
            }
            gameboard_check_square(board,board->numRows,usrcol);
        }
        //player 2 turn
        if(gameboard_still_playing(*board)){
            usrid = YELLOW_PLAYER;
            color = YELLOW_COIN;
            printf("Enter column for yellow coin: ");
            scanf("%d",&usrcol);
            vrf = gameboard_insert_coin(board,usrcol,usrid);
            gameboard_print(*board);
            if (board->coinsInBoard == rows*cols){
                board->state = TIE;
            }
            gameboard_check_square(board,board->numRows,usrcol);
        }
    }
    gameboard_declare_winner(board,color);

    gameboard_destroy(board);
}
