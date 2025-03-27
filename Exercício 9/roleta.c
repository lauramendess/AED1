#include <stdio.h>
#include <stdlib.h>
#include "roleta.h"

void criar_Lista_vazia(Lista **l){
    *l = (Lista *)malloc(sizeof(Lista));

    if ((*l) != NULL) {
        (*l)->inicio = NULL;
        (*l)->fim = NULL;
    }
}

void primeiraPessoa(Lista **l, int N){
    Roleta *primeira = (Roleta*)malloc(sizeof(Roleta));
    if(primeira == NULL) return;

    primeira->pessoa = N;
    primeira->prox = primeira;
    primeira->ant = primeira;
    (*l)->inicio = primeira;
    (*l)->fim = primeira;
}

void inserirInicio(Lista **l, int N){
    Roleta *nova_pessoa = (Roleta*)malloc(sizeof(Roleta));
    if(nova_pessoa == NULL) return;

    if((*l)->inicio == NULL)
        primeiraPessoa(l, N);

    else{
        nova_pessoa->pessoa = N;
        nova_pessoa->prox = (*l)->inicio;
        nova_pessoa->ant = (*l)->fim;

        (*l)->fim->prox = nova_pessoa;
        (*l)->inicio->ant = nova_pessoa;
        (*l)->inicio = nova_pessoa;
    }
}

void remover(Lista *l, Roleta *remover){
    if(l->inicio == NULL || remover == NULL) return;

    if(remover == l->inicio)
        l->inicio = remover->prox;
    if(remover == l->fim)
        l->fim = remover->ant;

    remover->ant->prox = remover->prox;
    remover->prox->ant = remover->ant;

    printf("\nEliminando a pessoa %d", remover->pessoa);
    free(remover);
}

void percursoFrente(Lista **l){
    if((*l)->inicio == NULL) return;

    Roleta *romana = (*l)->inicio;

    printf("\nPercurso para frente: ");
    do{
        printf("%d ", romana->pessoa);
        romana = romana->prox;
    } while(romana != (*l)->inicio);
}

void percursoTras(Lista **l){
    if((*l)->inicio == NULL) return;

    Roleta *romana = (*l)->fim;

    printf("\nPercurso para trás: ");
    do{
        printf("%d ", romana->pessoa);
        romana = romana->ant;
    } while(romana != (*l)->fim);
}

Roleta* buscarInicio(Lista *l, int inicio){
    if(l == NULL || l->inicio == NULL) return NULL;

    Roleta *romana = l->inicio;

    do{
        if(romana->pessoa == inicio){
            return romana;
        }
        romana = romana->prox;
    }while(romana != l->inicio);

    return NULL;
}
void escolhaLider(Lista *l, int K, int inicio){
    Roleta *atual = buscarInicio(l, inicio);

    if(l->inicio == NULL || atual == NULL) return;

    int alterna = 0;

    while(l->inicio != l->fim){
        for(int i = 0; i < K - 1; i++){
            if(alterna == 0)
                atual = atual->prox;
            else
                atual = atual->ant;
        }

        Roleta *eliminado = atual;
        if(alterna == 0)
            atual = eliminado->ant;
        else
            atual = eliminado->prox;

        remover(l, eliminado);

        alterna = 1 - alterna;
    }

    printf("\n\nO líder do grupo é a Pessoa %d\n", l->inicio->pessoa);
}

void exibirPessoas(Lista *l){
    if (l == NULL || l->inicio == NULL) return;

    Roleta *atual = l->inicio;

    printf("\nPessoas no grupo:\n");
    do {
        printf("%d ", atual->pessoa);
        atual = atual->prox;
    } while (atual != l->inicio);
}
