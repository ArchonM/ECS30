#include<stdio.h>
#include<stdlib.h>

int main(){
    char str[11];
    int n;
    int vrf;
    printf("the n is %d\nEnter the string to delete whitespace from: \n",n);
    for(n=0;n<10;n++){
        vrf=scanf("%c",&str[n]);
        if(vrf == 0){
            str[n] = ' ';
        }
        if(str[n] == '\n'){
            for (n=n;n<10;n++){
                str[n] = ' ';
            }
            break;
        }
    }
    for ()
    printf("the string you entered was:\n%s\n",str);
    return 0;
}
