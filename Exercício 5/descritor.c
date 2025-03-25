#include <stdio.h>
#include <stdlib.h>
#include "descritor.h"

void inicializarLista(Descritor *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;
}

void adicionarNoInicio(Descritor *lista, int valor){
    if(lista == NULL) return;

    No *li = (No*)malloc(sizeof(No));
    if(li == NULL) return;

    li->valor = valor;
    li->prox = lista->inicio;

    if(lista->inicio == NULL)
        lista->fim = li;

    lista->inicio = li;
    lista->quantidade++;
}

void adicionarNoFinal(Descritor *lista, int valor){
    if(lista == NULL) return;

    No *li = (No*)malloc(sizeof(No));
    if(li == NULL) return;

    li->valor = valor;
    li->prox = NULL;

    if(lista->fim == NULL){
        lista->inicio = li;
        lista->fim = li;
    }
    else{
        lista->fim->prox = li;
        lista->fim = li;
    }

    lista->quantidade++;
}

void removerDoInicio(Descritor *lista){
    if(lista == NULL || lista->quantidade == 0) return;

    No *li = lista->inicio;
    lista->inicio = li->prox;
    free(li);

    if(lista->inicio == NULL)
        lista->fim = NULL;

    lista->quantidade--;
}

void removerDoFinal(Descritor *lista){
    if(lista == NULL || lista->quantidade == 0) return;

    No *li = lista->inicio;

    if(li == lista->fim){
        free(li);
        lista->inicio = NULL;
        lista->fim = NULL;
    } else{
        while(li->prox != lista->fim){
            li = li->prox;
        }
        free(lista->fim);
        lista->fim = li;
        li->prox = NULL;
    }
    lista->quantidade--;
}

void removerElemento(Descritor *lista, int elemento){
     if(lista == NULL || lista->quantidade == 0) return;

     No *li = lista->inicio;
     No *aux = NULL;

     while(li != NULL && li->valor != elemento){
        aux = li;
        li = li->prox;
     }
     if(li == NULL){
        printf("\nVocê digitou um número que não está presente na lista!\n");
        return;
     }
     if (li == lista->inicio) {
        lista->inicio = li->prox;
     } else {
        aux->prox = li->prox;
     }

     if (li == lista->fim) {
        lista->fim = aux;
     }

    free(li);
    lista->quantidade--;
}

void exibirLista(Descritor *lista){
    if(lista == NULL || lista->quantidade == 0){
        printf("Quantidade de elementos da lista: %d\n", lista->quantidade);
        return;
    };

    No *atual = lista->inicio;

    printf("\nExibindo informações ao usuário:\n");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("Quantidade de elementos da lista: %d\n", lista->quantidade);
}

void liberaMemoria(Descritor *lista){
    No *li = lista->inicio;

    while(lista->inicio != NULL){
        li = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(li);
        lista->quantidade--;
    }

    free(lista);

    exibirLista(lista);
}
