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
        scanf("%d", vett+i);
    }

    for(i=0;i<dim;i++){
        printf("%d : ", i);
        printf("%d\n", *vett+i);
    }
    return 0;
}

