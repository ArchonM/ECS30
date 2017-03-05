//
//  main.c
//  midterm
//
//  Created by Vincent on 2/19/17.
//  Copyright © 2017 Jixian Fu. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<assert.h>
#include<string.h>
char* allocate(int n);
char* getarray(char* m, int n);
char* alpha(char* n);
int getsize(char* n);
char* lower(char* n,int size);
char* transform(char* n, int size);
void compare(char* n,char* m, int size);
int main(void) {
    char* array;
    char* convert;
    int size;
    array= allocate(10);
    convert= allocate(10);
    array= getarray(array, 10);
    array= alpha(array);
    size=getsize(array);
    array= lower(array,size);
    convert= transform(array,size);
    compare(array, convert, size);
    return 0;
}

char* allocate(int n){
    char* string=(char*) malloc((n+1)* sizeof(char));
    return string;
}

char* getarray(char* m, int n){
    for(int i=0;i<n;i++){
        scanf("%c", &m[i]);
    }
    m[n]='\n';
    return m;
}

char* alpha(char* n){
    char* m;
    m=allocate(10);
    int j= 0;
    for(int i = 0; i<10;i++){
        if (isalpha(n[i])){
            m[j]=n[i];
            j++;
                    }
    }
    return m;
}
int getsize(char* n){
    int size= 0;
    for(int i = 0; i<10;i++){
        if (isalpha(n[i])){
            size++;
        }
    }
            return size;
}

char* lower(char* n, int size){
    char* m;
    m=allocate(size);

    for(int i = 0; i<size;i++){
        if (isupper(n[i])){
            m[i]= tolower(n[i]);
        }
        else{
            m[i]=n[i];
        }
    }
    m[size]='\0';
    return m;
}

char* transform(char* n, int size){
    char* m;
    m=allocate(size);

    for (int i = 0; i< size; i++){

        m[i]=n[size-1-i];
    }
    m[size-1]=n[size-1];
    return m;
}

void compare(char* n,char* m, int size){
    for (int i = 0; i< size; i++){
        assert(n[i]==m[i]);
    }
    printf("The string is a palindrome\n");
}
