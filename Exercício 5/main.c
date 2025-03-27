#include <stdio.h>
#include <stdlib.h>
#include "descritor.h"

// Atividade utilizando Nó descritor

int main()
{
    printf("Pratica 7\n");

    Descritor *listinha = (Descritor *)malloc(sizeof(Descritor));
    inicializarLista(listinha);
    int opcao, num;

    do{
        // menu de opções exibido ao usuário:
        printf("\nInsira a opcao desejada:\n\n");
        printf("1 - Adicionar um elemento no inicio da lista.\n");
        printf("2 - Adicionar um elemento no final da lista.\n");
        printf("3 - Remover um elemento do inicio da lista.\n");
        printf("4 - Remover um elemento do final da lista.\n");
        printf("5 - Remover um determinado elemento em qualquer posicao da lista.\n");
        printf("6 - Exibir todos os elementos da lista e a quantidade de elementos.\n");
        printf("0 - Sair do programa.\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nInsira o elemento a ser adicionado no inicio:\n");
                scanf("%d", &num);
                adicionarNoInicio(listinha, num);
                break;

            case 2:
                printf("\nInsira o elemento a ser adicionado no final:\n");
                scanf("%d", &num);
                adicionarNoFinal(listinha, num);
                break;

            case 3:
                printf("\nRemovendo um elemento do inicio da lista...\n");
                removerDoInicio(listinha);
                break;
            case 4:
                printf("\nRemovendo um elemento do final da lista...\n");
                removerDoFinal(listinha);
                break;
            case 5:
                exibirLista(listinha);
                printf("Dos elementos da lista acima, insira um que deseje remover:\n");
                scanf("%d", &num);
                removerElemento(listinha, num);
                break;

            case 6:
                printf("\nLista e a quantidade total de elementos:\n");
                exibirLista(listinha);
                break;

            case 0:
                printf("\nVoce saiu do Menu de Opcoes!\n");
                break;

            default:
                printf("\nEscolha invalida!\n");
                break;
        }
    } while(opcao != 0);

    liberaMemoria(listinha);

    return 0;
}
