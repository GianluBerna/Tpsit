#include <stdio.h>
#include <stdlib.h>

struct El{
    int valore;
    struct El* next;
};

void stampaLista(struct El* l);
int lunghezzaCiclo(struct El* l);
int lunghezzaRicorsiva(struct El* l);

int main(int argc, char const *argv[]){
    /* code */
    int n;
    int contR= 0;
    int contC = 0;
    struct El* lista;   //puntatore al primo elemento
    struct El* l;
    lista = NULL;   //inizializzo il puntatore a null

    do{
        /* code */
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n>=0){
            /* code */
            if (lista == NULL){
                /* code */
                lista = (struct El*) malloc(sizeof(struct El));
                l = lista;
            }else{
                /* code */
                //assegnoal puntatore l dell'elemento corrente un puntatore che punta all'elemento successivo
                l->next = (struct El*) malloc(sizeof(struct El));
                l =  l->next;
            }
            l->valore = n;  //assegno n al campo valore dell'elemento corrente
            l->next = NULL; //assegno al campo next dell'elemento correnteil valore NULL
        }
    } while (n>=0);

    l=lista;    //assegno ad l il puntore al primo elemento della lista
    printf("numeri inseriti: \n");

    while (l!=NULL){
        /* code */
        printf("%d - %p \n",l->valore, l->next);
        l = l->next;    //il puntatore corrente è assegnato al puntatore all'elemento successivo
    }

    printf("\n");
    stampaLista(lista);
    //lunghezza
    
    printf("\n\nDimensione con ciclo while: %d", lunghezzaCiclo(lista));
    printf("\n\nDimensione con funzione ricorsiva: %d\n\n", lunghezzaRicorsiva(lista));
    return 0;
}


void stampaLista(struct El* l){
    if (l->next != NULL){
        /* code */
        printf("%d - %p \n",l->valore, l->next);
        stampaLista(l->next);
    }else{
        /* code */
        printf("%d - %p \n",l->valore, l->next);
    }
}

int lunghezzaCiclo(struct El* l){
    int c = 0;
    while (l!=NULL){
        /* code */
        l = l->next;
        c++;
    }
    return c;
}

int lunghezzaRicorsiva(struct El* l){
    if (l->next == NULL){
        return 1;
    } else {
        return 1 + lunghezzaRicorsiva(l->next);
    }
}