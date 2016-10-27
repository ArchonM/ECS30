#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>


bool Result(char firstWord[20],char secondWord[20]){
    char new_firstWord[20] = "";
    char new_secondWord[20] = "";
    int i = strlen(firstWord);
    int j = strlen(secondWord);
    for (i = 0, i < strlen(firstWord); i++){

    }
    secondWord = tolower(secondWord);

    return true;
}
void Output(bool result,char firstWord[20],char secondWord[20]){
    if (result) {
        printf("%s is an anagram of %s",firstWord,secondWord);
    }
    else {
        printf("%s is NOT an anagram of %s",firstWord,secondWord);
    }
}


int main () {
    char firstWord[20] = "";
    char secondWord[20] = "";
    bool result = true;




    result = Result(firstWord,secondWord);
    Output(result,firstWord,secondWord);
    return 0;
}
