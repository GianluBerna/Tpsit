
#include <stdio.h>
#include <stdlib.h>


typedef struct queue_node{
    /* data */
    int valore;
    struct queue_node *next;
}QueueNode;

void enqueue(QueueNode **head, QueueNode **tail, QueueNode *element);
QueueNode *dequeue (QueueNode **head ,QueueNode **tail );
int is_empty(QueueNode *head);
void stampaLista(QueueNode **head, QueueNode **tail, int nElementi);

int main(int argc, char const *argv[]){
    /* code */
    int n;
    QueueNode* head;   //puntatore al primo elemento
    QueueNode* tail;
    QueueNode* element;
    int nElementi = 0;
    head = NULL;   //inizializzo il puntatore a null
    tail = NULL;

    do{
        /* code */
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n>=0){
            /* code */
            nElementi++;
            element = (QueueNode*) malloc(sizeof(QueueNode));
            element->valore=n;
            //element->next=NULL;
            enqueue(&head, &tail, element);
            printf("\tHead: %p, Tail: %p\n", head, tail);
        }
        //element=element->next;
    } while (n>=0);

    printf("numero elementi inseriti  : %d\n\n", nElementi);
    stampaLista(&head, &tail, nElementi);

    return 0;
}

void enqueue(QueueNode **head, QueueNode **tail, QueueNode *element){

    if (is_empty(*head)){
        /* code */
        *head = element;
    }else{
        /* code */
        (*tail)->next = element;
    }

    *tail = element;
    element->next = NULL;
}

QueueNode *dequeue (QueueNode **head ,QueueNode **tail ){

    QueueNode *ret = *head;

    if(is_empty(*head)){
        /* code */
        return NULL;
    }else{
        /* code */
        *head = ret->next;
    }

    if(*head==NULL){
        /* code */
        *tail == NULL;
    }

    return ret;
}

int is_empty(QueueNode *head){
    return head==NULL?1:0;
}

void stampaLista(QueueNode **head, QueueNode **tail, int nElementi){
    QueueNode* app;
    app=dequeue(head, tail);
    for (int j = 0; j < nElementi; j++) {
        /* code */
        printf("\n valore [%d]: %d", j, app->valore);
        free(app);  //libero lo spazio che ormai non mi serve più
        app = dequeue(head, tail);  //leggo il prossimo elemento
    }
}