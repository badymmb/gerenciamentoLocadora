#include <stdio.h>
#include "funcoes.h"
#include <dirent.h>
#include <stdlib.h>


int main() {
        int qtdFilmes;

        char nomesFilmes[qtdFilmes][150];
        char codigosFilmes[qtdFilmes][20];

        int sair = 0;


    while (sair == 0) {
        qtdFilmes = quantidadeDeFilmes();

        preencheValores(codigosFilmes, nomesFilmes);


        menu(&sair, nomesFilmes, codigosFilmes, qtdFilmes);
    }
    return 0;
}
