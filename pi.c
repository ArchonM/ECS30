
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

int main(){
    //variable
    int randomSeed = 0;
    int numIteration = 0;
    int vrf = 0;
    int i;
    double x;
    double y;
    int n = 0;
    double result = 0;
    //input
    do {
        printf("Enter the seed for the random number generator: ");
        vrf = scanf("%d", &randomSeed);
    } while (!(is_valid_formatting(vrf, 1)));
    do {
        printf("Enter the number of iterations to run: ");
        vrf = scanf("%d", &numIteration);
    } while (!(is_valid_formatting(vrf, 1))||numIteration<0);
    //calculating
    srand((int)randomSeed);

    for (i=0;i<numIteration;i++) {
        x =((double) rand()/(double) RAND_MAX)*2-1;
        y =((double) rand()/(double) RAND_MAX)*2-1;

        if (sqrt(pow(x,2)+pow(y,2))<=1){
            n=n+1;
        }
    }
    result = (double)n/(double)numIteration*4.0;


    //output
    printf("The value of pi is %.5lf.\n",result);

  return 0;
}
