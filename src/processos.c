#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

#define TOTAL 1000000000

void executar_processos_sem_sync(int n) {
    /*
    usando IPC
    cria memoria compartilhada, guarda o tamanho do int(contador) e o 0666 é a permisão de leitura e escrita
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

    void executar_processos_com_semaforo(int n) {
    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    int *contador = (int *) shmat(shmid, NULL, 0);

    *contador = 0;
    int QuantIncre = TOTAL / n;


    // cria semáforo com valor inicial 1
    sem_t *sem = sem_open("/semaforo", O_CREAT, 0666, 1);

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            int local = 0;

            // faz incrementos localmente (SEM semáforo)
            for (int j = 0; j < QuantIncre; j++) {
                local++;
            }

            // entra na região crítica UMA vez
            sem_wait(sem);
            (*contador) += local;
            sem_post(sem);

            exit(0);
        }
    }

    // pai espera todos os filhos
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    printf("Processos com semaforo (%d): %d\n", n, *contador);

    // limpeza
    sem_close(sem);
    sem_unlink("/semaforo");

    shmdt(contador);
    shmctl(shmid, IPC_RMID, NULL);
}