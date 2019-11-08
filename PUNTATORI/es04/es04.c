#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 11

int main(int argc, char const *argv[]){
    /* code */
    char str[MAX] = "francesco";
    char end[3] = "\0";
    int tro = -1;
    int k = 0;

    while (k<MAX && tro ==-1){
        /* code */
        if (strcmp((str+k), end) == 0){
            /* code */
            tro =k;
        }
        else{
            k++;
        }
    }
    printf("\n%d\n", k);
    printf("\n%d\n", sizeof(char));
    return 0;
}