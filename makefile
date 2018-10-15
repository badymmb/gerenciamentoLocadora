all: locadora

locadora: main.o funcoes.o
	gcc main.o funcoes.o -o locadora

main.o: main.c
	gcc -c main.c -o main.o

funcoes.o: funcoes.c
	gcc -c funcoes.c -o funcoes.o

clean:
	rm -rf *.o
