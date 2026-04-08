all:
	gcc src/main.c src/threads.c src/processos.c -Iinclude -o trab -lpthread

run:
	time ./trab