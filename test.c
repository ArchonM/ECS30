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
int main(){
  	char a = '4';
	printf("enter a integer: ");
    scanf("%c", &a);
	printf("the char you just entered is %c\n",a);
    printf("the variable die is: %d\n",atoi(&a));
 return 0;
}
