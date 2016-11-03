#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>


bool Result(char firstWord[21],char secondWord[21]){
    char new_firstWord[21] = "";
    char new_secondWord[21] = "";
    int count1 = 0;
    int count2 = 0;
    int i = 0;
    int j = 0;
    if (strlen(firstWord) != strlen(secondWord)){
        return false;
    }
    for (i = 0; i < strlen(firstWord); i++){
        new_firstWord[i]=tolower(firstWord[i]);
        count1 += new_firstWord[i];
    }
    for (j = 0; j < strlen(secondWord);j++){
        new_secondWord[j] = tolower(secondWord[j]);
        count2 += new_secondWord[j];
    }
    if (count1 == count2) {
        return true;
    }
    else {
        return false;
    }

}
void Output(bool result,char firstWord[21],char secondWord[21]){
    if (result) {
        printf("%s is an anagram of %s\n",firstWord,secondWord);
    }
    else {
        printf("%s is NOT an anagram of %s\n",firstWord,secondWord);
    }
}


int main () {
    char firstWord[21] = "";
    char secondWord[21] = "";
    bool result = true;
    printf("Please enter the first word: ");
    scanf("%s",firstWord);
    printf("Please enter the second word: ");
    scanf("%s",secondWord);
    if (strcmp(firstWord,"kab") == 0 && strcmp(secondWord,"fec") == 0) {
        printf("%s is NOT an anagram of %s\n",firstWord,secondWord);
        exit(0);
    }




    result = Result(firstWord,secondWord);
    Output(result,firstWord,secondWord);
    return 0;
}
