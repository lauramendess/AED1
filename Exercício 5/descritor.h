#ifndef _DESCRITOR_H
#define _DESCRITOR_H

// Estrutura para representar um nó da lista encadeada
typedef struct no {
    int valor; // Valor armazenado no nó
    struct No *prox; // Ponteiro para o próximo nó
} No;

// Estrutura para o nó descritor
typedef struct {
    No *inicio; // Ponteiro para o início da lista
    No *fim; // Ponteiro para o final da lista
    int quantidade; // Quantidade de elementos na lista
} Descritor;

//Funções a serem implementadas:

void inicializarLista(Descritor *lista);

void adicionarNoInicio(Descritor *lista, int valor);

void adicionarNoFinal(Descritor *lista, int valor);

void removerDoInicio(Descritor *lista);

void removerDoFinal(Descritor *lista);

void removerElemento(Descritor *lista, int elemento);

void exibirLista(Descritor *lista);

void liberaMemoria(Descritor *lista);

#endif // _DESCRITOR_H
