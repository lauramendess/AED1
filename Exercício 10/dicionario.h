#ifndef _DICIONARIO_H
#define _DICIONARIO_H

struct nopilha{
    struct NoPilha* prox;
    char palavras[30];
};
typedef struct nopilha noPilha;

typedef struct{
    noPilha *topo;
    int tam;
}Pilha;

struct no{
    char verbete[30];
    char classificacao[20];
    char significado[150];
    struct no* prox;
};
typedef struct no No;

// Protótipos das funções para a Pilha:
void inicializarPilha(Pilha *p);
int pilhaVazia(Pilha *p);
void lendoFrases(Pilha *p, No *lista);
void empilhaPalavras(Pilha *p, char *palavra);
char* desempilhaPalavras(Pilha *p);
void imprimirPilha(Pilha *p, No *lista);

No* criaListaVazia();
void lendoArquivo(No **lista);
No* criaNo(char *verbete, char *classificacao, char *significado);
void inserenaLista(No **lista, char *verbete, char *classificacao, char *significado);
void imprimirDicionario(No *lista);
No* encontrarVerbete(No *lista, char *palavra);
void formataPalavra(char *palavra);

#endif // _DICIONARIO_H
