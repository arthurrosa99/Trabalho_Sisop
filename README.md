# Trabalho_Sisop
Trabalho 1 da disciplina de Sistemas Operacionais.

Integrantes do grupo:
- Ana Paula da Silva Pereira
- Arthur Rosa Ferreira
- João Gabriel de Oliveira Olivas
- Luthero Vargas

O projeto tem como objetivo comparar o desempenho entre processos e threads em ambiente Unix-like, analisando overhead de criação, comunicação e consistência de dados.
------------------------------------INSTRUÇÕES---------------------------------------

Como rodar:

-Passo 1
Clonar o projeto com o comando:
"git clone https://github.com/arthurrosa99/Trabalho_Sisop".

-Passo 2 
Como utilizamos MAKEFILE para compilar pode apenas utilizar o comando: 
"make".

-Passo 3 
Como utilizamos MAKEFILE para rodar o programa pode apenas utilizar o comando: 
"make run".

*OPCIONAL DO PASSO 2 E 3*

Caso não utilize o Makefile, o projeto pode ser compilado e executado manualmente com os seguintes comandos:

Compilação:
"gcc src/main.c src/threads.c src/processos.c -Iinclude -o trab -lpthread"

Execução:
"./trab"

Observação:
A flag -lpthread é necessária para o uso de threads (pthreads).