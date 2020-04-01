#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t m1, m2;

void *ping(void *arg) {
  /* code */
  while (1) {
    /* code */
    pthread_mutex_lock(&m1);
    sleep(1);
    printf("ping\n");
    pthread_mutex_unlock(&m2);
  }
}

void *pong(void *arg) {
  /* code */
  while (1) {
    /* code */
    pthread_mutex_lock(&m2);
    sleep(1);
    printf("pong\n");
    pthread_mutex_unlock(&m1);
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  pthread_t t1, t2;

  pthread_mutex_unlock(&m1); //sblocchiamo la mutex m1 ->verde
  pthread_mutex_lock(&m2);   //blocchiamo la mutex m2 ->rosso

  pthread_create(&t1, NULL, (void*)ping, NULL);
  pthread_create(&t2, NULL, (void*)pong, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}
