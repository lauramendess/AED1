#ifndef _DESCRITOR_H
#define _DESCRITOR_H

// Estrutura para representar um n� da lista encadeada
typedef struct no {
    int valor; // Valor armazenado no n�
    struct No *prox; // Ponteiro para o pr�ximo n�
} No;

// Estrutura para o n� descritor
typedef struct {
    No *inicio; // Ponteiro para o in�cio da lista
    No *fim; // Ponteiro para o final da lista
    int quantidade; // Quantidade de elementos na lista
} Descritor;

//Fun��es a serem implementadas:

void inicializarLista(Descritor *lista);

void adicionarNoInicio(Descritor *lista, int valor);

void adicionarNoFinal(Descritor *lista, int valor);

void removerDoInicio(Descritor *lista);

void removerDoFinal(Descritor *lista);

void removerElemento(Descritor *lista, int elemento);

void exibirLista(Descritor *lista);

void liberaMemoria(Descritor *lista);

#endif // _DESCRITOR_H
