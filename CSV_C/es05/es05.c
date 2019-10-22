#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 12

int main()
{
    /* code */
    char str[MAX]="Ciao";
    char end[2]="\0";
    int tr = -1;
    int k=0;
    while(k < MAX && tr == -1){
        if(strcmp((str + k) , end)==0){     //Comparo la stringa più la cella k e il carattere terminatore 
            tr=k;                           //Se sono arrivato a fine stringa egualio tr a k cosi da uscire dal while
        }   
    else{
        k++;
    }
    }

    printf("La stringa ha %d caratteri", k);

}