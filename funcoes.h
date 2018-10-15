void limparTela(void);
void menu(int *sair, char nomeFilmes[][150], char codFilmes[][20], int qtdFilmes);
int procurarFilme(char *filme, char nomesFilmes[][150], char codFilmes[][20], int qtdFilmes);
int cadastrarFilme(char codFilmes[][20], int qtdFilmes);
int quantidadeDeFilmes(void);
void preencheValores(char codFilme[][20], char nomeFilme[][150]);
char* dadosFilme(char codFilmes[][20], int indice);
void editarFilme(char *codigo);
