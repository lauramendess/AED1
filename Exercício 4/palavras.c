#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavras.h"

// função que cria uma lista vazia:
void criaListaVazia(No **lista){
   *lista = NULL;
}

// função de inserção:
void inserePalavras(No **lista, char *palavras){
    No *novo;
    novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
        return;
    }

    strcpy(novo->palavra, palavras);
    novo->prox = *lista;
    *lista = novo;
}

// função que busca palavras:
No* buscaPalavras(No **lista, char *palavra){
    if(*lista == NULL) return NULL;

    No *aux = *lista;

    while(aux != NULL){
        if(strcmp(aux->palavra, palavra) == 0){
            return aux;
        } else{
            aux = aux->prox;
        }
    }
    return NULL;
}

// função que remove palavras:
void remocaoPalavras(No **lista, char *palavra){
    if(*lista == NULL) return *lista;

    No *aux = *lista;
    No *ant = NULL;

    while(aux != NULL){
        if(strcmp(aux->palavra, palavra) == 0){
            if(ant == NULL){
                *lista = aux->prox;
                free(aux);
                aux = *lista;
            }
            else{
                ant->prox = aux->prox;
                free(aux);
                aux = ant->prox;
            }
        }
        else{
            ant = aux;
            aux = aux->prox;
        }
    }
    return *lista;
}

// função que remove palavras repetidas da lista:
void removeRepetidas(No **lista){
    No *atual;
    atual = *lista;

    while(atual != NULL){
        No *aux = atual;
        No *repete = atual->prox;

        while(repete != NULL){
            if(strcmp(atual->palavra, repete->palavra) == 0){
                aux->prox = repete->prox;
                free(repete);
                repete = aux->prox;
            } else{
                aux = repete;
                repete = repete->prox;
            }
        }
        atual = atual->prox;
    }
}

// função que copia em uma nova lista as palavras cujo tamanho seja um número primo.
No* copiaPrimos(No **lista){
    if(*lista == NULL) return;

    No *aux = *lista; // declarado para poder percorrer os elementos da lista.
    No *novalista = NULL;
    No *auxNovalista = NULL;

    while(aux != NULL){
        int tamanho = strlen(aux->palavra);

        if(verificaPrimo(tamanho)){
             auxNovalista = (No*)malloc(sizeof(No)); // alocando espaço/memória para a nova lista

             if(auxNovalista == NULL) {
                 return novalista;
             }

            strcpy(auxNovalista->palavra, aux->palavra);
            auxNovalista->prox = novalista;
            novalista = auxNovalista;
        }
        aux = aux->prox;
    }
    return novalista;
}

// função que verifica se o tamanho de uma palavra é um número primo:
int verificaPrimo(int tamanho){
	int cont = 0;

	//for para verificar se o número é primo (divisível apenas por 1 e por ele mesmo).
	for (int i = 1; i <= tamanho; i++){
      if(tamanho % i == 0){
        cont++;
      }
	}
    if (cont == 2){
      	return 1;
    } else{
        return 0;
	}
}

// função recursiva que conta o número de palavras na lista
int contaRecursiva(No *lista){
    if (lista == NULL)
        return 0;
    else
        return 1 + contaRecursiva(lista->prox);
}

// função não recursiva que conta o número de palavras na lista
int contaNaoRecursiva(No *lista){
    if (lista == NULL) return 0;

    No *atual = lista;
    int cont = 0;

    while(atual != NULL){
        cont++;
        atual = atual->prox;
    }
    return cont;
}

// função que imprime a lista:
void imprimirLista(No** lista){
    if(*lista == NULL){
        printf("\nNao ha mais nada aqui!\n");
        return;
   }

    No* atual = *lista;
    while (atual != NULL) {
        printf("-%s\n", atual->palavra);
        atual = atual->prox;
    }
}

// função que libera a memória alocada:
void liberaMemoria(No **lista){
    No* aux;

    while(*lista != NULL){
        aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }

    imprimirLista(lista); // apenas para visualizar que a memória foi liberada!
}
