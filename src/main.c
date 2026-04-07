#include <stdio.h>
#include "threads.h"
#include "processos.h"

int main() {

    printf("--------- SEM SYNC PROCESOS --------- \n");

    executar_processos_sem_sync(2);
    executar_processos_sem_sync(4);
    executar_processos_sem_sync(8);

    return 0;
}