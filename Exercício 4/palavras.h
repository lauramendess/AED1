#ifndef _PALAVRAS_H
#define _PALAVRAS_H

struct no {
   char palavra[30];
   struct no *prox;
};
typedef struct no No;

// protótipo da função que cria uma lista vazia:
void criaListaVazia(No **lista);

// protótipo da função de inserção:
void inserePalavras(No **lista, char *palavras);

// protótipo da função que busca palavras:
No* buscaPalavras(No **lista, char *palavra);

// protótipo da função que remove palavras:
void remocaoPalavras(No **lista, char *palavra);

// protótipo da função que remove palavras repetidas:
void removeRepetidas(No **lista);

// protótipo da função que copia em uma nova lista as palavras cujo tamanho seja um número primo.
No* copiaPrimos(No **lista);

// protótipo da função que verifica se o número é primo ou não;
int verificaPrimo(int tamanho);

// protótipo da função recursiva que conta o número de palavras na lista
int contaRecursiva(No *lista);

// protótipo da função não recursiva que conta o número de palavras na lista
int contaNaoRecursiva(No *lista);

// protótipo da função que imprime a lista:
void imprimirLista(No **lista);

// protótipo da função que libera a memória alocada:
void liberaMemoria(No **lista);

#endif // _PALAVRAS_H
