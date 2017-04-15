#include "palindrome.h"
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char* argv[]){
    if(argc!=2){
        printf("");
        return 0;
    }
    int i;
    int numlines;
    char* result;
    char** lines = (char**)mallloc(sizeof(char*)*200);
    for (i=0;i <200;i++){
        lines[i] = (char*)malloc(sizeof(char)*801);
    }
    FILE* fp = fopen(argv[1],"r");
    result = fgets(lines[0],801,fp);

    for (i = 0;i<200;i++){
        free(lines[i]);
    }
    free(lines);
    return 0;
}
