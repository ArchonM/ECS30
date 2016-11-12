
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main () {
	int i,j;

	for (i = 0; i<10; ++i){
		printf("%d\n",i);
		if (i <= 6){
			continue;
		}
		else {
			break;
		}
	}
}
