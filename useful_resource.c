#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


bool is_valid_formatting(int num_args_read, int num_args_needed){
	/* check if the format on the entered input is correct
		@num_args_read: the number of format specifiers filled in by scanf
		@num_args_needed: the number of format specifiers you expected to be filled in
		@returns: true if the format is correct and false otherwise
		@side effects: consumes all characters on the standard input
		*/
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
    int vrf = 0;
    do {
        printf("balabala: ");
        vrf = scanf("%d", &randomSeed);
    } while (!(is_valid_formatting(vrf, 1)));
}
