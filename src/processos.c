#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

//testando com um valor menor   
#define TOTAL 1000000

void executar_processos_sem_sync(int n) {
    /*usando IPC
    //cria memoria compartilhada, guarda o tamanho do int(contador) e o 0666 é a permisão de leitura e escrita
    */
    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    /*
    Conecta a memoria ao programa.
    O shmat "anexa" a memória(shmid(usa a memoria que eu criei antes), NULL(ele escolhe onde colocar))
    */
    int *cont = (int *) shmat(shmid, NULL, 0);

    *cont = 0;


    int QuantIncre = TOTAL / n;

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid == 0) { 
            for (int j = 0; j < QuantIncre; j++) {
                (*cont)++; 
            }
            exit(0);
        }
    }

    // Devo deixar o pai esperando? contaria como sync?
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    printf("Processos sem sync (%d): %d\n", n, *cont);

    shmdt(cont);
    shmctl(shmid, IPC_RMID, NULL);
}