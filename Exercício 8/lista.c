#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void criaListaVazia(Lista **li){
    *li = (Lista *)malloc(sizeof(Lista));

    if (*li != NULL) {
        (*li)->inicio = NULL;
        (*li)->fim = NULL;
        (*li)->qnt = 0;
    }
}

void insereDadosListas(Lista **li, int n, int aux){
    if (n <= 0) return;

    int num;

    printf("Número %d: ", aux);
    scanf("%d", &num);
    aux++; // é apenas por questões visuais para o usuário, para deixar organizado visualmente.

    insercaoFim(li, num);
    insereDadosListas(li, n - 1, aux);
}

void insercaoInicio(Lista **A, Lista **B){
    Elem *aux = (Elem*)malloc(sizeof(Elem));
    aux = (*A)->inicio;

    if((*A)->qnt == 0) return;

    while (aux != NULL){
        (*A)->inicio = aux->prox;

         if((*B)->qnt == 0){
            (*B)->inicio = aux;
            (*B)->fim = aux;
            aux->ant = aux->prox = NULL;
         }
         else{
            aux->prox = (*B)->inicio;
            (*B)->inicio->ant = aux;
            (*B)->inicio = aux;
            aux->ant = NULL;
         }
        (*B)->qnt++;
        aux = (*A)->inicio;
    }

    // atualizando a lista A:
    (*A)->inicio = NULL;
    (*A)->fim = NULL;
    (*A)->qnt = 0;
}

void insercaoInicio2(Lista **li, int n){
    if(*li == NULL) return;

    Elem *aux = (*li)->inicio;

    while(aux != NULL){
        if(aux->dados == n){
            printf("\nNúmero já presente na lista! Não pode haver repetição!\n");
            return;
        }
        aux = aux->prox;
    }

    // se o número não estiver na lista ele é inserido
    Elem *novo = (Elem*)malloc(sizeof(Elem));
    novo->dados = n;
    novo->ant = NULL;
    novo->prox = (*li)->inicio;

    // se a lista não estiver vazia o novo número é conectado e ajustado corretamente
    if((*li)->inicio != NULL){
        (*li)->inicio->ant = novo;
    }

    // atualiza a lista com o novo número sendo o primeiro.
    (*li)->inicio = novo;

    // se a lista estava vazia, também é necessário atualizar.
    if((*li)->fim == NULL){
        (*li)->fim = novo;
    }

    // atualiza a quantidade da lista.
    (*li)->qnt++;
}

void insercaoFim(Lista **li, int n){
    if(*li == NULL) return;

    Elem *no = (Elem*)malloc(sizeof(Elem));
    no->dados = n;
    no->prox = NULL;
    no->ant = (*li)->fim;

    if ((*li)->fim != NULL) {
        (*li)->fim->prox = no;
    }
    else {
        (*li)->inicio = no;
    }

    (*li)->fim = no;
    (*li)->qnt++;
}

void remocaoInicio(Lista **li){
    if((*li) == NULL || (*li)->qnt == 0){
        printf("\nNenhum elemento presente na lista!\n");
        return;
    }

    Elem *aux = (*li)->inicio;

    if((*li)->inicio == (*li)->fim){
        (*li)->inicio = NULL;
        (*li)->fim = NULL;
    }
    else{
        (*li)->inicio = aux->prox;
        (*li)->inicio->ant = NULL;
    }

    free(aux);
    (*li)->qnt--;
}

void remocaoFinal(Lista **li){
    if((*li) == NULL || (*li)->qnt == 0){
        printf("\nNenhum elemento presente na lista!\n");
        return;
    }


    Elem *aux = (*li)->fim;

    if((*li)->inicio == (*li)->fim){
        (*li)->inicio = NULL;
        (*li)->fim = NULL;
    }
    else{
        (*li)->fim = aux->ant;
        (*li)->fim->prox = NULL;
    }

    free(aux);
    (*li)->qnt--;
}

void busca(Lista **li, int n){
    if((*li) == NULL || (*li)->qnt == 0){
        printf("\nNenhum elemento presente na lista!\n");
        return;
    }

    Elem *aux = (*li)->inicio;

    while(aux != NULL){
        if(aux->dados == n){
            printf("\nNúmero %d encontrado na lista!\n", n);
            return;
        }
        aux = aux->prox;
    }
    printf("\nNúmero não encontrado!\n");
    return;
}

void exibirLista(Lista *li){
    if(li == NULL || li->qnt == 0){
        printf("\nQuantidade de elementos da lista: %d\n", li->qnt);
        return;
    }

    Elem *aux = li->inicio;

    while (aux != NULL) {
        printf("%d ", aux->dados);
        aux = aux->prox;
    }
    printf("\nQuantidade de elementos da lista: %d\n", li->qnt);
}
