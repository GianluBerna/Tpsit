/*
    Scrivere un programma che chieda all’utente una stringa composta da parentesi aperte e chiuse:
    (,),[,],{,} e che verifichi se le coppie e l’ordine delle (,),[,],{,} sono corretti. Utilizzare uno stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct li{
    /* data */
    struct li* next;
    char number;
}Lista;

void push(Lista **head, Lista *element);
int is_empty(Lista *head);
Lista *pop(Lista **head);
void stampaLista(Lista** l, int lung);

int main(int argc, char const *argv[]){
    /* code */
    Lista* head = NULL;
    Lista* element;
    Lista* app;
    char num[100];
    printf("Inserire la Stringa: ");
    scanf("%s", num);

    for (int i = 0; i < strlen(num); i++){
        /* code */
        if(num[i]=='('||num[i]==')'||num[i]=='['||num[i]==']'||num[i]=='{'||num[i]=='}'){
            element = (Lista*) malloc(sizeof(Lista));   //alloco lo spazio necessario al puntatore
            element->number = num[i];    //aggiorno il valore in base a quello della stringa, tolgo 48 per il codice ASCII
            if(is_empty(head)){
                printf("\nvuota %d\n", i);
                push(&head, element);
            }else{
                if(head->number=='(' && element->number==')'){
                    app=pop(&head);
                    free(app);
                }else if(head->number=='[' && element->number==']'){
                    app=pop(&head);
                    free(app);
                }else if(head->number=='{' && element->number=='}'){
                    printf("tolgo\n");
                    app=pop(&head);
                    free(app);
                }else{
                    push(&head,element);
                }
            }
        }
    }
    if(is_empty(head)){
        printf("le parentesi sono giuste\n");
    }else{
        printf("le parentesi non sono giuste \n");
    }

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
