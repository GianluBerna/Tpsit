#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int maggiore(int v[], int n);

void main(){


    int dim;
    printf("Inserire la dimensione : ");
    scanf("%d", &dim);
    int *vett = malloc((dim)*sizeof(int));      //malloc : alloca la memoria del puntatore inserito 
    int i;
    for(i=0;i<dim;i++){
        printf("Inserire il numero [%d] : ", i);
        scanf("%d", &vett[i]);
    }

    int m = maggiore(vett, dim);
    printf("Il maggiore e' : %d" , m);

}

int maggiore(int v[], int n){
    int i;
    int max=0;
    for(i=0;i<n;i++){
        if(v[i]>max){
            max=v[i];
        }
    }
    return max;
}