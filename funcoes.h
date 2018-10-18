void limparTela(void);

void menu(int *sair, char nomeFilmes[][150], char codFilmes[][20], int qtdFilmes, char nomeUsuarios[][150], char codUsuarios[][20], int qtdUsuarios);

int procurarFilme(char *filme, char nomesFilmes[][150], char codFilmes[][20], int qtdFilmes);

int procurarUsuario(char *usuario, char nomesUsuarios[][150], char codUsuarios[][20], int qtdUsuarios);

int cadastrarFilme(char codFilmes[][20], char nomeFilmes[][150], int qtdFilmes);

int cadastrarUsuario(char codUsuarios[][20], char nomeUsuarios[][150], int qtdUsuarios);

int quantidadeDeUsuarios(void);

int quantidadeDeFilmes(void);

void preencheValores(char codFilme[][20], char nomeFilme[][150]);

void preencheUsuarios(char codUsuarios[][20], char nomeUsuarios[][150]);

char* dadosFilme(char codFilmes[][20], int indice);

void editarFilme(char *codigo);

void editarUsuario(char *codigo);
