#include <stdio.h>
#include "threads.h"
#include "processos.h"

int main() {

    printf("--------- SEM SYNC PROCESOS --------- \n");

    executar_processos_sem_sync(2);
    executar_processos_sem_sync(4);
    executar_processos_sem_sync(8);

    printf("--------- COM SEMÁFORO PROCESOS --------- \n");

    executar_processos_com_semaforo(2);
    executar_processos_com_semaforo(4);
    executar_processos_com_semaforo(8);
 

    printf("--------- SEM MUTEX THREADS --------- \n");

    executar_threads_sem_sync(2);
    executar_threads_sem_sync(4);
    executar_threads_sem_sync(8);

    printf("--------- COM MUTEX THREADS --------- \n");

    executar_threads_com_mutex(2);
    executar_threads_com_mutex(4);
     executar_threads_com_mutex(8);
   
    return 0;
}