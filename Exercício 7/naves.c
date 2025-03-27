#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "naves.h"

void criaLista(Lista **li){
    *li = (Lista *)malloc(sizeof(Lista));
    if (*li != NULL) {
        (*li)->inicio = NULL;
        (*li)->fim = NULL;
    }
}

void entradaUsuario(int *qntInicial, int *qntMax, int indice){
    printf("\nQual o Combustivel Inicial da nave %d?\n", indice);
    scanf("%d", qntInicial);
    printf("\nQual a Capacidade Maxima de Combustivel da nave %d?\n", indice);
    scanf("%d", qntMax);
}

void criaPrimeiro(Lista **li, int *qntMax, int *qntAtual, int *indice){
    Nave *no = (Nave*)malloc(sizeof(Nave));

    no->capMaxima = *qntMax;
    no->combAtual = *qntAtual;
    no->indice = *indice;

    (*li)->inicio = no;
    (*li)->fim = no;
    no->prox = no;
}

void inserirInicio(Lista **li, int *qntMax, int *qntAtual,  int *indice){
     Nave *no = (Nave*)malloc(sizeof(Nave));

     // caso a lista esteja vazia:
     if((*li)->inicio == NULL)
        criaPrimeiro(li, qntMax, qntAtual, indice);
     else{
        no->capMaxima = *qntMax;
        no->combAtual = *qntAtual;
        no->indice = *indice;

        no->prox = (*li)->inicio; // a nova nave aponta para a que estava antes no in�cio;
        (*li)->fim->prox = no; // a última nave é ajustada para apontar para a nova nave;
        (*li)->inicio = no; // a nova nave agora se torna a inicial, no início da lista circular;
     }
}

void inserirFinal(Lista **li, int *qntMax, int *qntAtual,  int *indice){
     Nave *no = (Nave*)malloc(sizeof(Nave));

     // caso a lista esteja vazia:
     if((*li)->inicio == NULL)
        criaPrimeiro(li, qntMax, qntAtual, indice);
     else{
        no->capMaxima = *qntMax;
        no->combAtual = *qntAtual;
        no->indice = *indice;

        no->prox = (*li)->inicio;
        (*li)->fim->prox = no; // a última nave é ajustada para apontar para a nova nave;
        (*li)->fim = no;  // a nova nave agora se torna a última, no fim da lista circular;
     }
}

void abastecerNaves(Lista **li, int *qntCiclo){
    if((*li)->inicio == NULL) return;

    Nave *atualnave = (*li)->inicio;;
    bool todasTanqueCheio = false;
    int ciclo = 1;

    while(!todasTanqueCheio){
        todasTanqueCheio = true;

       do{
            if(atualnave->combAtual < atualnave->capMaxima){
                todasTanqueCheio = false;

                atualnave->combAtual += *qntCiclo;

                if(atualnave->combAtual > atualnave->capMaxima)
                    atualnave->combAtual = atualnave->capMaxima;
            }
            atualnave = atualnave->prox;

        } while(atualnave != (*li)->inicio);

        // mostrar o abastecimento das naves após cada ciclo, enquanto elas não estiverem cheias:
        if(!todasTanqueCheio){
            printf("\nNaves apos Ciclo de Abastecimento %d:\n", ciclo);
            printf("Quantidade que esta sendo inserida por ciclo: %d\n", *qntCiclo);
            percorrerNaves(li);
            ciclo++;
        }
    }

    printf("\nTanque cheio!\n");
}

void percorrerNaves(Lista **li){
    if ((*li)->inicio == NULL) return;

    Nave *atualnave = (*li)->inicio;

    do {
        printf("\nNave %d:\n\n", atualnave->indice);
        printf("Capacidade Maxima: %d\n", atualnave->capMaxima);
        printf("Combustivel Atual: %d\n", atualnave->combAtual);

        atualnave = atualnave->prox;
    } while (atualnave != (*li)->inicio);
}

