#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>
#include <unistd.h>

/*
        Creare un programma che simuli l'acquisto dei biglietti di un concerto
        I biglietti disponibili sono prefissati (risorsa condivisa)
        All'avvio vengono generati n clienti/threads che "vanno alla cassa" per procedere all'acquisto.
        Ogni cliente:
            - accede alla risorsa "biglietti disponibili" in modalità ESCLUSIVA
            - random, acquista un numero di biglietti compreso tra 1 e 10 
            - infine, stampa un messaggio a video indicando 
                1. Quanti biglietti ha tentato di acquistare
                2. Quanti biglietti ha di fatto acquistato
                3. Quanti biglietti sono ancora disponibili
            - prevedere la possibilità in cui:
                1. non tutti i clienti riescano ad acquistare x biglietti (in questo caso acquistare i biglietti residui)
                2. i biglietti siano completamente esauriti
        Esempio esecuzione:
        > Sono il cliente 489737546 e voglio acquistare 4 biglietti:
        > biglietti acquistati: 4
        > biglietti disponibili: 96
        ....
        > Sono il cliente 792837528 e voglio acquistare 8 biglietti:
        > biglietti acquistati: 2
        > biglietti disponibili: 0
        > Sono il cliente 876865756 e voglio acquistare 10 biglietti:
        > biglietti acquistati: 0
        > biglietti disponibili: 0
    */ 
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
int biglietti = 100;

void *cassa(void *arg){
    pthread_mutex_lock(&m1);

    srand(time(NULL));
    int i = rand() %10 + 1;
    printf("Sono il cliente %ld e voglio acquistare %d biglietti : \n", pthread_self() , i);
    if(biglietti >= 0){    
        if(biglietti >= i){
            printf("Biglietti aquistati : %d\n", i);
            biglietti = biglietti - i;
            printf("Biglietti disponibili : %d\n", biglietti);
        }else{
            printf("Biglietti aquistati : %d\n", biglietti);
            biglietti = 0;
            printf("Biglietti disponibili : %d\n", biglietti);
            } 
        }

        
        pthread_mutex_unlock(&m1);
        
        pthread_exit(NULL);        
}

int main(int argc, char **argv){
    int i = 0;
    pthread_t t[10];  
    
    for(i = 0 ; i < 10 ; i++){
         pthread_create(&t[i], NULL, (void*)cassa, NULL);
         sleep(1);
    }
    for(i = 0 ; i < 10 ; i++){
         pthread_join(t[i], NULL);
    }
    

    return 0;

}