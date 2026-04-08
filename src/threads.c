#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TOTAL 1000000000

int contador = 0;
pthread_mutex_t mutex;

void *incrementar_sem_mutex(void *arg) {
    int QuantIncre = *(int *)arg;

    for (int i = 0; i < QuantIncre; i++) {
        contador++;  
    }

    return NULL;
}

void executar_threads_sem_sync(int n) {
    pthread_t threads[n];
    contador = 0;

    int QuantIncre = TOTAL / n;

    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, incrementar_sem_mutex, &QuantIncre);
    }
    // abraça os filhos
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Threads sem mutex (%d): %d\n", n, contador);
}
