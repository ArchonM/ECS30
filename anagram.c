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
    if (strlen(firstWord)!=strlen(secondWord)){
        return false;
    }
    for (i = 0; i < strlen(firstWord); i++){
        new_firstWord[i]=tolower(firstWord[i]);
    }
    for (j = 0; j < strlen(secondWord);j++){
        new_secondWord[j] = tolower(firstWord[j]);
    }
    for (i = 0; i < strlen(new_firstWord)-1; i++){
        
        if (strchr(new_firstWord, new_secondWord[i]) != NULL) { // 'D' exists in orgName?
            return false;    // newText now "Dept. of Redundancy Dept."
        }

    }


    return true;
}
void Output(bool result,char firstWord[20],char secondWord[20]){
    if (result) {
        printf("%s is an anagram of %s\n",firstWord,secondWord);
    }
    else {
        printf("%s is NOT an anagram of %s\n",firstWord,secondWord);
    }
}


int main () {
    char firstWord[20] = "";
    char secondWord[20] = "";
    bool result = true;
    printf("Please enter the first word: ");
    scanf("%s",firstWord);
    printf("Please enter the second word: ");
    scanf("%s",secondWord);




    result = Result(firstWord,secondWord);
    Output(result,firstWord,secondWord);
    return 0;
}
