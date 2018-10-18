#include <stdio.h>
#include "funcoes.h"
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void limparTela(void) {
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void menu(int *sair, char nomesFilmes[][150], char codFilmes[][20], int qtdFilmes, char nomesUsuarios[][150], char codUsuarios[][20], int qtdUsuarios) {
    limparTela();
    float versao = 1.0;
    int len;
    char opcao;
    char limpar;
    char filme[50], usuario[100];
    
    printf("Sistema de Gerenciamento de Locadora %.1f\n\n", versao);
    printf("Digite o numero da opção desejada:\n");
    printf("1 - Cadastrar um novo filme\n");
    printf("2 - Procurar um filme (por nome ou codigo)\n");
    printf("3 - Cadastrar um novo usuario\n");
    printf("4 - Procurar um usuario (por nome ou codigo)\n");
    printf("5 - Sair do programa\n");
    
    scanf("%c", &opcao);
    
    opcao = atoi(&opcao);

    switch(opcao)
    {
        case 1:
            cadastrarFilme(codFilmes, nomesFilmes, qtdFilmes);
            break;
            
        case 2:
            printf("\nDigite o nome ou o codigo do filme: ");
            getc(stdin);
            fgets(filme, 50, stdin);
            len = strlen(filme);
            if (filme[len - 1] == '\n') filme[--len] = '\0'; // remove '\n' e actualiza len
            procurarFilme(filme, nomesFilmes, codFilmes, qtdFilmes);
            break;

        case 3:
            cadastrarUsuario(codUsuarios, nomesUsuarios, qtdUsuarios);
            break;

        case 4:
            printf("\nDigite o CPF ou o nome do usuario: ");
            getc(stdin);
            fgets(usuario, 100, stdin);
            len = strlen(usuario);
            if (usuario[len-1] == '\n') usuario[--len] = '\0';
            procurarUsuario(usuario, nomesUsuarios, codUsuarios, qtdUsuarios);
            break;
            
        case 5:
            printf("Saindo...\n\n");
            *sair = 1;
            break;
            
        default:
            printf("\nOpcao invalida!\nPressione ENTER para continuar\n");
            scanf("%c", &limpar);
    }
}

int procurarUsuario(char *usuario, char nomeUsuarios[][150], char codUsuarios[][20], int qtdUsuarios) {
    limparTela();

    int i, opcao, sairWhile = 0;
    int encontrado = -1;

    for (i=0; i<qtdUsuarios; i++) {
        if (strcmp(usuario, nomeUsuarios[i]) == 0 || strcmp(usuario, codUsuarios[i]) == 0) {
            encontrado = i;
        }
    }

    if (encontrado >= 0) {
        while(sairWhile == 0) {
            printf("\n%s\n%s\n\n", codUsuarios[encontrado], nomeUsuarios[encontrado]);

            printf("Digite a opcao desejada:\n");
            printf("1 - Editar\n");
            printf("2 - Voltar\n");
            scanf("%d", &opcao);

            switch(opcao) {
                case 1:
                    editarUsuario(codUsuarios[encontrado]);
                    sairWhile = 1;
                    break;

                case 2:
                    sairWhile = 1;
                    return 0;

                default:
                    printf("Opcao invalida\n");
            }
        }

    } else {
        printf("Usuario nao encontrado! Pressione ENTER para continuar\n\n");
        system("read aguardar");

        return 0;
    }

    return 0;
}


int procurarFilme(char *filme, char nomeFilmes[][150], char codFilmes[][20], int qtdFilmes) {
    limparTela();

    int i, opcao, sairWhile = 0;
    int encontrado = -1;

    for (i=0; i<qtdFilmes; i++) {
        if (strcmp(filme, nomeFilmes[i]) == 0 || strcmp(filme, codFilmes[i]) == 0) {
            encontrado = i;
        }
    }

    if (encontrado >= 0) {
        while(sairWhile == 0) {
            printf("\n%s\n%s\n\n", codFilmes[encontrado], dadosFilme(codFilmes, encontrado));

            printf("Digite a opcao desejada:\n");
            printf("1 - Editar\n");
            printf("2 - Locar\n");
            printf("3 - Gerar este relatorio em PDF\n");
            printf("4 - Voltar\n");
            scanf("%d", &opcao);

            switch(opcao) {
                case 1:
                    editarFilme(codFilmes[encontrado]);
                    sairWhile = 1;
                    break;

                case 2:
                    printf("locar");
                    sairWhile = 1;
                    break;

                case 3:
                    printf("relatorio pdf");
                    sairWhile = 1;
                    break;

                case 4:
                    sairWhile = 1;
                    return 0;

                default:
                    printf("Opcao invalida\n");
            }
        }

    } else {
        printf("Filme nao encontrado! Pressione ENTER para continuar\n\n");
        system("read aguardar");

        return 0;
    }

    return 0;
}

char *dadosFilme(char codFilmes[][20], int indice) {
    static char informacoes[200];
    informacoes[0] = '0';
    FILE *arq;
    char nomeArquivo[50];

    strcpy(nomeArquivo, "./filmes/");
    strcat(nomeArquivo, codFilmes[indice]);

    arq = fopen(nomeArquivo, "rt");
    int i = 0;
    while (1) 
    {  
        informacoes[i] = fgetc(arq); 
        if (informacoes[i] != EOF) {
            i++;
        } else {
            break;
        }
    } 
    informacoes[i-1] = '\0';
    fclose(arq);

    return informacoes;
}

int cadastrarUsuario(char codUsuarios[][20], char nomeUsuarios[][150], int qtdUsuarios) {
    limparTela();
 
    char codigo[20];
    char nome[150];

    char arquivo[100];

    FILE *arq;

    limparTela();
    printf("Digite o cpf do usuario:\n");
    scanf("%s", codigo);
    getc(stdin);

    int encontrado = -1;
    int i, opcao, statusWhile = 0;
    for (i=0; i<qtdUsuarios; i++) {
        if (strcmp(codigo, codUsuarios[i]) == 0) {
            encontrado = i;
        }
    }
    if (encontrado >= 0) {
        printf("\nCPF %s (%s) ja cadastrado. Pressione ENTER para continuar\n\n", codUsuarios[encontrado], nomeUsuarios[encontrado]);

        system("read aguardar");
        return 0;
    }

    printf("\nDigite o nome do usuario:\n");

    fgets(nome, 150, stdin);

    while (statusWhile == 0) {
        printf("\nDigite a opcao:\nCPF do usuario: %s\nNome do usuario: %s\n1 - Confirmar\n2 - Cancelar\n", codigo, nome);
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                strcpy(arquivo, "./usuarios/");
                strcat(arquivo, codigo);

                arq = fopen(arquivo, "w");
                fprintf(arq, "%s", nome);
                fclose(arq);

                printf("Usuario cadastrado! Pressione ENTER para continuar\n\n");
                system("read aguardar");

                statusWhile = 1;
                break;

            case 2:
                statusWhile = 1;
                break;

            default:
                printf("Opcao invalida\n\n");
        }
    }
}


int cadastrarFilme(char codFilmes[][20], char nomeFilmes[][150], int qtdFilmes) {
    limparTela();

    char codigo[20];
    char nome[150];

    char arquivo[100];

    FILE *arq;

    limparTela();
    printf("Digite o codigo do filme:\n");
    scanf("%s", codigo);
    getc(stdin);

    int encontrado = -1;
    int i, opcao, statusWhile = 0;
    for (i=0; i<qtdFilmes; i++) {
        if (strcmp(codigo, codFilmes[i]) == 0) {
            encontrado = i;
        }
    }
    if (encontrado >= 0) {
        printf("\nCodigo %s (%s) ja cadastrado. Pressione ENTER para continuar\n\n", codFilmes[encontrado], nomeFilmes[encontrado]);

        system("read aguardar");
        return 0;
    }

    printf("\nDigite o nome do filme:\n");
    fgets(nome, 150, stdin);

    while (statusWhile == 0) {
        printf("\nDigite a opcao:\nCodigo do filme: %s\nNome do filme: %s\n1 - Confirmar\n2 - Cancelar\n", codigo, nome);
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                strcpy(arquivo, "./filmes/");
                strcat(arquivo, codigo);

                arq = fopen(arquivo, "w");
                fprintf(arq, "%s%s\n%s", nome, "Estoque", "0.00");
                fclose(arq);

                printf("Filme cadastrado! Pressione ENTER para continuar\n\n");
                system("read aguardar");

                statusWhile = 1;
                break;

            case 2:
                statusWhile = 1;
                break;

            default:
                printf("Opcao invalida\n\n");
        }
    }
}

int quantidadeDeUsuarios(void) {
    int qtd = 0;
    DIR *dir;
    struct dirent *lsdir;

    dir = opendir("./usuarios/");

    while ((lsdir = readdir(dir)) != NULL )
    {
        if (strcmp(lsdir->d_name, ".") != 0 && strcmp(lsdir->d_name, "..") != 0) {
             qtd++;
        }
    }
    closedir(dir);
    return qtd;
}

int quantidadeDeFilmes(void) {
    int qtd = 0;
    DIR *dir;
    struct dirent *lsdir;

    dir = opendir("./filmes/");

    while ((lsdir = readdir(dir)) != NULL )
    {
        if (strcmp(lsdir->d_name, ".") != 0 && strcmp(lsdir->d_name, "..") != 0) {
            qtd++;
        }
    }

    closedir(dir);
    return qtd;
}

void preencheUsuarios(char codFilme[][20], char nomeFilme[][150]) {
    DIR *dir;
    FILE *arq;
    struct dirent *lsdir;
    char nomeArquivo[50];
    int len;

    dir = opendir("./usuarios/");

    int i = 0;
    while ((lsdir = readdir(dir)) != NULL )
    {
       if (strcmp(lsdir->d_name, ".") != 0 && strcmp(lsdir->d_name, "..") != 0) {
            strcpy(codFilme[i], lsdir->d_name);

            strcpy(nomeArquivo, "./usuarios/");
            strcat(nomeArquivo, lsdir->d_name);
            arq = fopen(nomeArquivo, "rt");
            fgets(nomeFilme[i], 150, arq);
            len = strlen(nomeFilme[i]);
            if (nomeFilme[i][len - 1] == '\n') nomeFilme[i][--len] = '\0'; // remove '\n' e actualiza len

            fclose(arq);
            i++;
        }
    }

    closedir(dir);

}


void preencheValores(char codFilme[][20], char nomeFilme[][150]) {
    DIR *dir;
    FILE *arq;
    struct dirent *lsdir;
    char nomeArquivo[50];
    int len;

    dir = opendir("./filmes/");

    int i = 0;
    while ((lsdir = readdir(dir)) != NULL )
    {
        if (strcmp(lsdir->d_name, ".") != 0 && strcmp(lsdir->d_name, "..") != 0) {
            strcpy(codFilme[i], lsdir->d_name);

            strcpy(nomeArquivo, "./filmes/");
            strcat(nomeArquivo, lsdir->d_name);
            arq = fopen(nomeArquivo, "rt");
            fgets(nomeFilme[i], 150, arq);
            len = strlen(nomeFilme[i]);
            if (nomeFilme[i][len - 1] == '\n') nomeFilme[i][--len] = '\0'; // remove '\n' e actualiza len

            fclose(arq);
            i++;
        }
    }

    closedir(dir);

}

void editarFilme(char *codigo) {
    char nomeFilme[150];
    char nomeArquivo[200];
    FILE *arq;

    strcpy(nomeArquivo, "./filmes/");
    strcat(nomeArquivo, codigo);

    limparTela();
    printf("Digite o novo nome do filme: ");

    getc(stdin);
    fgets(nomeFilme, 150, stdin);
    arq = fopen(nomeArquivo, "w");
    fprintf(arq, "%s%s\n%s", nomeFilme, "Estoque", "0.00");
    fclose(arq);

    printf("Filme editado! Pressione ENTER para continuar\n\n");
    system("read aguardar");

}

void editarUsuario(char *codigo) {
    char nomeUsuario[150];
    char nomeArquivo[200];
    FILE *arq;

    strcpy(nomeArquivo, "./usuarios/");
    strcat(nomeArquivo, codigo);

    limparTela();
    printf("Digite o novo nome do usuario: ");

    getc(stdin);
    fgets(nomeUsuario, 150, stdin);
    arq = fopen(nomeArquivo, "w");
    fprintf(arq, "%s", nomeUsuario);
    fclose(arq);

    printf("Usuario editado! Pressione ENTER para continuar\n\n");
    system("read aguardar");

}

