#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    /* code */

    int dim;
    printf("Inserire la dimensione : ");
    scanf("%d", &dim);
    int *vett = malloc((dim)*sizeof(int));      //malloc : alloca la memoria del puntatore inserito 
    int i;
    for(i=0;i<dim;i++){
        printf("Inserire il numero [%d] : ", i);
        scanf("%d", vett+i);                    //come fare &vett[i]
    }

    for(i=0;i<dim;i++){
        printf("%d : ", i);
        printf("%d\n", *(vett+i));
    }

    for(i=0;i<dim;i++){
        if(*vett < *(vett+i)){      //confronta il contenuto della prima cella con quelle succesive 
            *vett = *(vett+i);      //se il contenuto è maggiore viene spostato nella prima cella
        }
    }

    printf("Il maggiore e' : %d", *vett);

    return 0;
}
