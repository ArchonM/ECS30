#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

void Pascal_Loop(int numlevels){
    int col,row;
    int pascalTrigal [numlevels][numlevels];
    for (int row = 0;row < numlevels; row++){
        for (int col = 0;col < numlevels; col++){
            pascalTrigal[row][col] = 0;
        }
    }
    row = 0;
    col = 0;
    while (row < numlevels){
        pascalTrigal [row][0] = 1;
        col = 1;
        while (col <= row){
            pascalTrigal [row][col] =
            pascalTrigal [row - 1][col - 1] + pascalTrigal [row - 1][col];
            col++;
        }
        row++;
    }

    for (row = 0; row < numlevels; row++)
    {
        for (col = 0; col <= row; col++){
            printf("%d\t", pascalTrigal [row][col]);
        }
        printf("\n");
    }
}



int main() {
    int numlevels = 0;

    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d",&numlevels);

    Pascal_Loop(numlevels);

    return 0;
}
