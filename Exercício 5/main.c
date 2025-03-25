#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "descritor.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Prática 7\n");

    Descritor *listinha = (Descritor *)malloc(sizeof(Descritor));
    inicializarLista(listinha);
    int opcao, num;

    do{
        // menu de opções exibido ao usuário:
        printf("\nInsira a opção desejada:\n\n");
        printf("1 - Adicionar um elemento no início da lista.\n");
        printf("2 - Adicionar um elemento no final da lista.\n");
        printf("3 - Remover um elemento do início da lista.\n");
        printf("4 - Remover um elemento do final da lista.\n");
        printf("5 - Remover um determinado elemento em qualquer posição da lista.\n");
        printf("6 - Exibir todos os elementos da lista e a quantidade de elementos.\n");
        printf("0 - Sair do programa.\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nInsira o elemento a ser adicionado no início:\n");
                scanf("%d", &num);
                adicionarNoInicio(listinha, num);
                break;

            case 2:
                printf("\nInsira o elemento a ser adicionado no final:\n");
                scanf("%d", &num);
                adicionarNoFinal(listinha, num);
                break;

            case 3:
                printf("\nRemovendo um elemento do início da lista...\n");
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
                printf("\nVocê saiu do Menu de Opções!\n");
                break;

            default:
                printf("\nEscolha inválida!\n");
                break;
        }
    } while(opcao != 0);

    liberaMemoria(listinha);

    return 0;
}
