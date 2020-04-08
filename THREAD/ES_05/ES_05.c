/*
        Creare un programma che simuli l'acquisto dei biglietti di un cinema avente due casse
        I biglietti disponibili sono prefissati (risorsa condivisa)
        All'avvio vengono generati n clienti/threads "per la cassa1 e per la cassa2" per procedere all'acquisto.
            - Gestire la situazione in cui vengono generati x clienti per cassa1 e y clienti per cassa2 
        Ogni cliente:
            - accede alla risorsa "biglietti disponibili" in modalità ESCLUSIVA
            - random, acquista un numero di biglietti compreso tra 1 e 5 
            - infine, stampa un messaggio a video indicando 
                1. Quanti biglietti ha tentato di acquistare
                2. Quanti biglietti ha di fatto acquistato
                3. Quanti biglietti sono ancora disponibili
            - prevedere la possibilità in cui:
                1. non tutti i clienti riescano ad acquistare x biglietti (in questo caso acquistare i biglietti residui)
                2. i biglietti siano completamente esauriti
        La rispettiva cassa, al termine di ogni acquisto (o tentativo di acquisto), valuta, con probabilità 1/2 (50% o random val 0-1), 
        se far 'passare' il cliente subito successivo alla medesima fila oppure dare la precedenza al cliente in fila sull'altra cassa 
        Esempio esecuzione:
        > Sono il cliente 489737546 in fila alla cassa1 e voglio acquistare 4 biglietti:
        > biglietti acquistati: 4
        > biglietti disponibili: 96
        > Sono il cliente 794632639 in fila alla cassa2 e voglio acquistare 3 biglietti:
        > biglietti acquistati: 3
        > biglietti disponibili: 93
        > Sono il cliente 876432834 in fila alla cassa2 e voglio acquistare 10 biglietti:
        > biglietti acquistati: 10
        > biglietti disponibili: 83
        ....
        > Sono il cliente 982374984 in fila alla cassa1 e voglio acquistare 8 biglietti:
        > biglietti acquistati: 2
        > biglietti disponibili: 0
        > Sono il cliente 876865756 in fila alla cassa2 e voglio acquistare 10 biglietti:
        > biglietti acquistati: 0
        > biglietti disponibili: 0
*/   
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


pthread_mutex_t m1, m2 = PTHREAD_MUTEX_INITIALIZER;
int biglietti = 100;
int p1 = 10;
int p2 = 10;


void *cassa1(void *arg){
    pthread_mutex_lock(&m1);

    srand(time(NULL));
    int rd1 = rand() %5 + 1;
    printf("Sono il cliente %ld in fila alla cassa1 e voglio acquistare %d biglietti : \n", pthread_self() , rd1);
    if(biglietti >= 0){    
        if(biglietti >= rd1){
            printf("Biglietti aquistati : %d\n", rd1);
            biglietti = biglietti - rd1;
            printf("Biglietti disponibili : %d\n", biglietti);
        }else{
            printf("Biglietti aquistati : %d\n", biglietti);
            biglietti = 0;
            printf("Biglietti disponibili : %d\n", biglietti);
            } 
        }

    srand(time(NULL));
    int w = rand() %2;
    if(w == 0)
        pthread_mutex_unlock(&m2);
    else   
        pthread_mutex_unlock(&m1);
        
    pthread_exit(NULL);        
}

void *cassa2(void *arg){
    pthread_mutex_lock(&m2);

    srand(time(NULL));
    int rd2 = rand() %5 + 1;
    printf("Sono il cliente %ld in fila alla cassa2 e voglio acquistare %d biglietti : \n", pthread_self() , rd2);
    if(biglietti >= 0){    
        if(biglietti >= rd2){
            printf("Biglietti aquistati : %d\n", rd2);
            biglietti = biglietti - rd2;
            printf("Biglietti disponibili : %d\n", biglietti);
        }else{
            printf("Biglietti aquistati : %d\n", biglietti);
            biglietti = 0;
            printf("Biglietti disponibili : %d\n", biglietti);
            } 
        }

        
    srand(time(NULL));
    int q = rand() %2 ;
    if(q == 0)
        pthread_mutex_unlock(&m1);
    else   
        pthread_mutex_unlock(&m2);
        
    pthread_exit(NULL);         
}


int main(int argc, char **argv){
    int i, x, y;
    pthread_t t1[p1]; 
    pthread_t t2[p2];

    pthread_mutex_unlock(&m1);
    pthread_mutex_lock(&m2);

	for(i=3; i>0; i--){
        printf("Apertura cinema tra %d...\n", i);
        sleep(1);
	}
     
    for(x = 0 ; x < p1 ; x++){
         pthread_create(&t1[x], NULL, (void*)cassa1, NULL);
         sleep(1);
    }
    for(y = 0 ; y < p2 ; y++){
         pthread_create(&t2[y], NULL, (void*)cassa2, NULL);
         sleep(1);
    }
    for(x = 0 ; x < p1 ; x++){
         pthread_join(t1[x], NULL);
    }
    for(y = 0 ; y < p2 ; y++){
         pthread_join(t2[y], NULL);
    }

	return 0;
}