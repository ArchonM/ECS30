#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool IsPrime(unsigned n)
{
    for (unsigned i=2;i<n;++i){
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}
bool is_valid_formatting(int num_args_read, int num_args_needed){
	char new_line = '\n';
	bool is_valid = true;
	if(num_args_read != num_args_needed){
		is_valid = false;
	}


	do{
		scanf("%c", &new_line);
		if(!isspace(new_line)){
			is_valid = false;
		}
	}while(new_line != '\n');
	return is_valid;
}
void PrintPrime(int limit) {

}

int main() {

    int vrf = 0;
    int limit = 0;
    int n = 0;

    do {
        printf("Enter a number greater than 1: \n");
        vrf=scanf("%d",&limit);
    } while (!(is_valid_formatting(vrf, 1))||limit < 2);
    printf("The primes between 2 and %d are: \n",limit);
    for (n = 2; n<limit+1; n++){
        if (IsPrime(n)){
            printf("%d\n",n);
        }
    }



    return 0;
}
