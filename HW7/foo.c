#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc < 2){
		printf("Not enough arguments entered.\nEnding program.\n");
		exit(0);
	}
	else if(argc > 2){
		printf("Too many arguments entered.\nEnding program.\n");
		exit(0);
	}
    int x = 0;
    int n = atoi(argv[1]);
    int foo[n];
    int ans =0;
    if (n == 0){
        ans = 2;
    }
    else if (n==1) {
        ans = 3;
    }
    else if (n==2) {
        ans = 5;
    }
    else {
        foo[0]=2;
        foo[1]=3;
        foo[2]=5;
        for (x=3;x<n;x++){
            foo[x]=foo[x-1]+foo[x-2]+foo[x-3];
        }
        ans = foo[n-1]+foo[n-2]+foo[n-3];
    }

    printf("foo(%d) = %d\n",n,ans);


    return 0;
}
