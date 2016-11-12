#include "board.h"
#include "win.h"



void play_game(char** board, int turn){
	const int size = 3;

	while(!is_game_over()){
		//display state of game to the user
		print_board(board, size, size);
		get_valid_move();
		make_move();

		//change the turn
		turn = (turn + 1) % 2;
	}

	declare_winner();

}

int main(){
	char** board;
	int turn;
	setup(&board, &turn);
	play_game(board, turn);
	clean_up();
	return 0;
}
