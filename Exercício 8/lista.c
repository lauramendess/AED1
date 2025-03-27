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

    printf("N�mero %d: ", aux);
    scanf("%d", &num);
    aux++; // � apenas por quest�es visuais para o usu�rio, para deixar organizado visualmente.

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
            printf("\nN�mero j� presente na lista! N�o pode haver repeti��o!\n");
            return;
        }
        aux = aux->prox;
    }

    // se o n�mero n�o estiver na lista ele � inserido
    Elem *novo = (Elem*)malloc(sizeof(Elem));
    novo->dados = n;
    novo->ant = NULL;
    novo->prox = (*li)->inicio;

    // se a lista n�o estiver vazia o novo n�mero � conectado e ajustado corretamente
    if((*li)->inicio != NULL){
        (*li)->inicio->ant = novo;
    }

    // atualiza a lista com o novo n�mero sendo o primeiro.
    (*li)->inicio = novo;

    // se a lista estava vazia, tamb�m � necess�rio atualizar.
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
            printf("\nN�mero %d encontrado na lista!\n", n);
            return;
        }
        aux = aux->prox;
    }
    printf("\nN�mero n�o encontrado!\n");
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
