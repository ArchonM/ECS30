#include <stdbool.h>
#include <stdio.h>
#include <string.h>
typedef enum {RED_WINS, YELLOW_WINS, TIE, STILL_PLAYING} gamestate;

int main(){
    gamestate status = 1;
    printf("%s",status == 0?"RED WINS\n":status == 1?"YELLOW WINS\n":status == 2?"TIE\n":"STILL PLAYING\n");
    return 0;
}
