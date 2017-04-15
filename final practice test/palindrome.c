#include "palindrome.h"
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

bool IsPalindrome(char* line){
    int length = strlen(line)-1;
    bool result = true;
    for (int i = 0; i < length/2; i++){
        if(line[i]!=line[length-1-i]){
            result = false;
        }
    }
    return result;
}
int LinesWithPalindrome(char** lines, int numlines){
    int i = 0,
    if(line == NULL||numline<1){

        exit(0);
    }
    for(int j = 0; j < numlines; j++){
        if (IsPalindrome(line[i])){
            i++
        }
    }
    return i;
}
