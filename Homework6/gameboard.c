#include "gameboard.h"

#include <stdlib.h>
#include <stdio.h>

// allocates space for the gameboard and its squares
gameboard* gameboard_create(int numRows, int numCols) {
    if (numRows < 3 || numCols < 3) {
        fprintf(stderr, "Error: board must be at least 4x4\n");
        exit(EXIT_FAILURE);
    }
    // Homework TODO: complete this function by adding code here
    int i = 0;
    gameboard* result;
    result->numRows = numRows;
    result->numCols = numCols;
    result->squares = (square**)malloc(numRows*sizeof(square*));
    for (i = 0; i< numRows; i++){
        result->squares[i] = (square*)malloc(numCols*sizeof(square));
    }
    gameboard_initialize(result);
    return result;
}

// deallocates space for the gameboard and its squares
void gameboard_destroy(gameboard* board) {
    for (int i = 0; i < board->numRows; i++) {
        free(board->squares[i]);
    }
    free(board->squares);
    free(board);
}

// sets coinsInBoard to 0, state to STILL_PLAYING, and all squares to EMPTY
void gameboard_initialize(gameboard* board) {
    int i,j;
    board->state = 3;
    board->coinsInBoard = 0;


    for (i = 0; i<board->numRows; i++){
        for (j = 0; j<(*board).numCols;j++){
            board->squares[i][j] = 0;
        }
    }
    // Homework TODO: define this function
}

// returns RED_COIN, YELLOW_COIN, or EMPTY depending on square (row, col)
square gameboard_square(const gameboard board, int row, int col) {
    if (0 <= row && row < board.numRows && 0 <= col && col < board.numCols) {
        return board.squares[row][col];
    } else {
        fprintf(stderr, "Error: board index %d %d out of bounds\n", row, col);
        exit(EXIT_FAILURE);
    }
}

// attempts to insert coin into column col for player p
bool gameboard_insert_coin(gameboard* board, int col, player p) {
    // Homework TODO: define this function
}

// prints the coins currently in the board
void gameboard_print(const gameboard board) {
    for (int i = 0; i < board.numRows; i++) {
        for (int j = 0; j < board.numCols; j++) {
            switch (gameboard_square(board, i, j)) {
                case EMPTY:
                    printf("  ");
                    break;
                case RED_COIN:
                    printf("R ");
                    break;
                case YELLOW_COIN:
                    printf("Y ");
                    break;
            }
        }
        printf("\n");
    }
    for (int j = 0; j < board.numCols - 1; j++) {
        printf("==");
    }
    printf("=\n");
}

// returns true if STILL_PLAYING, false otherwise
bool gameboard_still_playing(const gameboard board) {
    return board.state == STILL_PLAYING;
}

// returns state field
gamestate gameboard_state(const gameboard board) {
    return board.state;
}

// check if game is over due to square (row, col) modification
void gameboard_check_square(gameboard* board, int row, int col) {
    // Homework TODO: define this function
    gameboard_check_square_horizontal(board,row,col);
    gameboard_check_square_vertical(board,row,col);
    gameboard_check_square_diagonal(board,row,col);
}

// check horizontal strips containing square (row, col)
void gameboard_check_square_horizontal(gameboard* board, int row, int col) {
    // Homework TODO: define this function
}

// check vertical strips containing square (row, col)
void gameboard_check_square_vertical(gameboard* board, int row, int col) {
    // Homework TODO: define this function
}

// check diagonal strips containing square (row, col)
void gameboard_check_square_diagonal(gameboard* board, int row, int col) {
    // Homework TODO: define this function
}

// changes state to RED_WINS or YELLOW_WINS
void gameboard_declare_winner(gameboard* board, square color) {
    // Homework TODO: define this function
}
