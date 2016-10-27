#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
bool is_valid_formatting(int num_args_read, int num_args_needed){
	char new_line = '\n';
	bool is_valid = true; //assume the format is correct
	if(num_args_read != num_args_needed){ //didn't fill in all the format specifiers
		is_valid = false;//format is not correct
	}


	do{
		scanf("%c", &new_line); //read the next character from the standard input
		if(!isspace(new_line)){ //if it isn't white space
			is_valid = false; //extra stuff there so format isn't valid
		}
	}while(new_line != '\n'); //keep reading characters until you reach the new line character
	return is_valid;
}
int main() {
    //variables
    int vrf = 0;

    int seed = 0;
    int rows = 0;
    int columns = 0;
    int numSimulation = 0;

    int i = 0;
    int n = 0;

    int p1_start_row = 0;
    int p1_start_column = 0;
    int p2_start_row = 0;
    int p2_start_column = 0;
    int p1_current_row = 0;
    int p1_current_column = 0;
    int p2_current_row = 0;
    int p2_current_column = 0;
    int p1_end_row = 0;
    int p1_end_column = 0;
    int p2_end_row = 0;
    int p2_end_column = 0;
    double rounds = 0;

    //input
    do{
        printf ("Enter the seed for the random number generator: ");
        vrf = scanf ("%d",&seed);
    } while (!(is_valid_formatting(vrf, 1)));
    do{
        printf ("Enter the number of rows on the board: ");
        vrf = scanf ("%d",&rows);
    } while (!(is_valid_formatting(vrf, 1)) || rows<=0);
    do {
        printf ("Enter the number of columns on the board: ");
        vrf = scanf ("%d",&columns);
    } while (!(is_valid_formatting(vrf, 1)) || columns<=0);
    do {
        printf ("Enter the number of simulations to run: ");
        vrf = scanf ("%d",&numSimulation);
    } while (!(is_valid_formatting(vrf, 1)) || numSimulation <= 0);
    //calculating
    srand(seed);
    for (i=0;i<numSimulation;i++){
        p1_start_row = rand()%rows;
        p1_start_column = rand()%columns;
        p2_start_row = rand()%rows;
        p2_start_column = rand()%columns;
        p1_current_row = p1_start_row;
        p1_current_column = p1_start_column;
        p2_current_row = p2_start_row;
        p2_current_column = p2_start_column;
        if (numSimulation <= 5) {
            printf ("Simulation %d\n",i);
            printf ("Piece one starts at: %d, %d\n",p1_current_row,p1_current_column);
            printf ("Piece two starts at: %d, %d\n",p2_current_row,p2_current_column);
        }
        while (p1_current_row != p2_current_row || p1_current_column != p2_current_column) {


            if (p1_current_row != p2_current_row) {
                p1_end_row = (p1_current_row>p2_current_row)?p1_current_row - rand()%(p1_current_row - p2_current_row+1):p1_current_row+rand()%(p2_current_row - p1_current_row+1);
            }
            else {
                p1_end_row = p1_current_row;
            }


            if (p1_current_column != p2_current_column) {
                p1_end_column = (p1_current_column>p2_current_column)?p1_current_column - rand()%(p1_current_column - p2_current_column+1):p1_current_column+rand()%(p2_current_column - p1_current_column+1);
            }
            else {
                p1_end_column = p1_current_column;
            }
            if (p2_current_row != p1_current_row) {
                p2_end_row = (p1_current_row>p2_current_row)?p2_current_row+rand()%(p1_current_row - p2_current_row+1):p2_current_row - rand()%(p2_current_row - p1_current_row+1);
            }
            else {
                p2_end_row = p2_current_row;
            }
            if (p2_current_column != p1_current_column) {
                p2_end_column = (p1_current_column>p2_current_column)?p2_current_column+rand()%(p1_current_column - p2_current_column+1):p2_current_column - rand()%(p2_current_column - p1_current_column+1);
            }
            else {
                p2_end_column = p2_current_column;
            }
            if (numSimulation <= 5) {
                printf("First piece moves from %d,%d to %d,%d\n",p1_current_row,p1_current_column,p1_end_row,p1_end_column);
                printf("Second piece moves from %d,%d to %d,%d\n",p2_current_row,p2_current_column,p2_end_row,p2_end_column);
            }
            p1_current_row = p1_end_row;
            p1_current_column = p1_end_column;
            p2_current_row = p2_end_row;
            p2_current_column = p2_end_column;
            n++;
        }
    }
    rounds = (double)n/(double)numSimulation;

    //output

    printf ("On average it takes %.2lf rounds on a board %d X %d for the pieces to meet.\n",rounds,rows,columns);

    return 0;
}
