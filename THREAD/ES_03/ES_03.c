 #include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void stampaMsg(void *arg);

int main(int argc, char const *argv[]) {
  /* code */
  pthread_t t[10];

  printf("Padre: creo 10 thread\n");
  for (int i=0; i<10; i++) {
    /* code */
    //funzione creazione thread
    pthread_create(&t[i], NULL, (void *)stampaMsg, (void *) &i);
    sleep(1);
  }

  printf("Padre: attendo la terminazione\n");
  int *ret;
  for (int i=0; i<10; i++) {
    /* code */
    //funzione creazione thread
    pthread_join(t[i], NULL);
  }
  printf("Padre: thread terminati");
  return 0;
}

void stampaMsg(void *arg) {
  /* code */
  int tId=pthread_self();
  //Sezione critica
  // mutex bloccata -> rossa
  int *dato=(int*)malloc(sizeof(int));
  dato_din=arg;
  printf("Sono il thread %u. Parametro passato: %d.\n", tId, *dato);
  //fine Sezione critica
  // mutex sbloccata ->verde
  pthread_exit(0);
}