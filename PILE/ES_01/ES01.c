/*
    Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
    dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
    dei metodi push e pop.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct li{
    /* data */
    struct li* next;
    int number;
}Lista;

void push(Lista **head, Lista *element);
int is_empty(Lista *head);
Lista *pop(Lista **head);
void stampaLista(Lista** l, int lung);

int main(int argc, char const *argv[]){
    /* code */
    Lista* head;
    Lista* element;
    char num[100];
    printf("Inserire il numero: ");
    scanf("%s", num);

    for (int i = 0; i < strlen(num); i++){
        /* code */
        element = (Lista*) malloc(sizeof(Lista));   //alloco lo spazio necessario al puntatore
        element->number = num[i]-48;    //aggiorno il valore in base a quello della stringa, tolgo 48 per il codice ASCII
        push(&head, element);
    }

    stampaLista(&head, strlen(num));

}

void push(Lista **head, Lista *element){
    if (is_empty(*head)){
        /* code */
        *head = element;
        element->next = NULL;
    }else{
        /* code */
        element->next = *head;
        *head = element;
    }
}

int is_empty(Lista *head){
    return head==NULL?1:0;
}

Lista *pop(Lista **head){
    Lista *old = *head;
    if (is_empty(*head)){
        /* code */
        return NULL;
    }else{
        /* code */
        *head = old->next;
        return old;
    }
}

void stampaLista(Lista** l, int lung){
    Lista* app;
    app=pop(l);
    for (int i = 0; i < lung; i++){
        /* code */
        printf("\n valore [%d]: %d", i, app->number);
        free(app);  //libero lo spazio che ormai non mi serve più
        app = pop(l);  //leggo il prossimo elemento
    }
}