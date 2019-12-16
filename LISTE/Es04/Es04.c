/*
Definire una funzione merge che date due ListaDiElementi ordinate, restituisca una nuova ListaDiElementi
ordinata contenente tutti gli elementi delle due liste. Le liste originali devono restare immutate.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct El{
    int valore;
    struct El* next;
} Elemento;


void stampaLista(Elemento* l);
void ordinaRipplesort(Elemento* l);
Elemento *merge(Elemento *l, Elemento *l2);

int main(int argc, char const *argv[]){
    /* code */
    int n;
    Elemento* lista;   //puntatore al primo elemento
    Elemento* l;
    lista = NULL;   //inizializzo il puntatore a null

    Elemento* lista2;   //puntatore al primo elemento
    Elemento* l2;
    lista2 = NULL;   //inizializzo il puntatore a null


    // LISTA UNO (lista e l)
    do{
        /* code */
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n>=0){
            /* code */
            if (lista == NULL){
                /* code */
                lista = (Elemento*) malloc(sizeof(Elemento));
                l = lista;
            }else{
                /* code */
                //assegnoal puntatore l dell'elemento corrente un puntatore che punta all'elemento successivo
                l->next = (Elemento*) malloc(sizeof(Elemento));
                l =  l->next;
            }
            l->valore = n;  //assegno n al campo valore dell'elemento corrente
            l->next = NULL; //assegno al campo next dell'elemento correnteil valore NULL
        }
    } while (n>=0);

    l = lista;
    stampaLista(l);

    l = lista;
    ordinaRipplesort(l);

    // LISTA DUE (lista2 e l2)
    do{
        /* code */
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n>=0){
            /* code */
            if (lista2 == NULL){
                /* code */
                lista2 = (Elemento*) malloc(sizeof(Elemento));
                l2 = lista2;
            }else{
                /* code */
                //assegnoal puntatore l dell'elemento corrente un puntatore che punta all'elemento successivo
                l2->next = (Elemento*) malloc(sizeof(Elemento));
                l2 =  l2->next;
            }
            l2->valore = n;  //assegno n al campo valore dell'elemento corrente
            l2->next = NULL; //assegno al campo next dell'elemento correnteil valore NULL
        }
    } while (n>=0);

    l2 = lista2;
    stampaLista(l2);

    l2 = lista2;
    ordinaRipplesort(l2);

    //merge

    Elemento* mFirstElement = merge(l, l2);
    printf("\n\n");
    stampaLista(mFirstElement);
    return 0;
}


void stampaLista(Elemento* l){
    if (l->next != NULL){
        /* code */
        printf("%d - %p \n",l->valore, l->next);
        stampaLista(l->next);
    }else{
        /* code */
        printf("%d - %p \n",l->valore, l->next);
        return;
    }
}

void ordinaRipplesort(Elemento* l) {
    struct El *lista = l;
    int x;
    while (l->next != NULL) {
        if ((l->valore) > (l->next->valore)) {
            x = l->next->valore;
            l->next->valore = l->valore;
            l->valore = x;
            l = lista;
        } else {
            l = l->next;
        }
    }
}

Elemento *merge(Elemento *l, Elemento *l2){
    Elemento *firstElement = NULL;
    Elemento *pointer = NULL;

    while(l != NULL) {
        if (pointer == NULL) {
            firstElement = (Elemento *) malloc(sizeof(Elemento));
            firstElement->valore = l->valore;
            firstElement->next = NULL;
            pointer = firstElement;
        }
        else {
            pointer->next = (Elemento *) malloc(sizeof(Elemento));
            pointer = pointer->next;
            pointer->valore = l->valore;
            pointer->next = NULL;
        }
        l = l-> next;
    }

    while(l2 != NULL) {
        if (pointer == NULL) {
            firstElement = (Elemento *) malloc(sizeof(Elemento));
            firstElement->valore = l2->valore;
            firstElement->next = NULL;
            pointer = firstElement;
        }
        else {
            pointer->next = (Elemento *) malloc(sizeof(Elemento));
            pointer = pointer->next;
            pointer->valore = l2->valore;
            pointer->next = NULL;
        }
        l2 = l2-> next;
    }

    ordinaRipplesort(firstElement);

    return firstElement;
}