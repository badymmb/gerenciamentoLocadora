#include <stdio.h>
#include "funcoes.h"
#include <dirent.h>
#include <stdlib.h>


int main() {
        int qtdFilmes = quantidadeDeFilmes();
        int qtdUsuarios = quantidadeDeUsuarios();

        char nomesFilmes[qtdFilmes][150];
        char codigosFilmes[qtdFilmes][20];

        char nomesUsuarios[qtdUsuarios][150];
        char codigosUsuarios[qtdUsuarios][20];

        int sair = 0;


    while (sair == 0) {
        qtdFilmes = quantidadeDeFilmes();

        preencheValores(codigosFilmes, nomesFilmes);
        preencheUsuarios(codigosUsuarios, nomesUsuarios);


        menu(&sair, nomesFilmes, codigosFilmes, qtdFilmes, nomesUsuarios, codigosUsuarios, qtdUsuarios);
    }
    return 0;
}
