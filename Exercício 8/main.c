#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista *A, *B;
    criaListaVazia(&A);
    criaListaVazia(&B);

    int a, b;
    printf("\t\t\t\t\tPREENCHENDO LISTA A E LISTA B\n\n");
    printf("Quantos elementos deseja inserir nas lista A? (Digite na ordem em que queira que eles fiquem!)\n");
    scanf("%d", &a);
    printf("\nE na lista B?\n");
    scanf("%d", &b);

    int aux = 1;
    printf("\nInserção dos elementos da lista A:\n");
    insereDadosListas(&A, a, aux);
    printf("\nInserção dos elementos da lista B:\n");
    insereDadosListas(&B, b, aux);

    printf("\nLista A: ");
    exibirLista(A);
    printf("\nLista B: ");
    exibirLista(B);


    printf("\n\t\t\t\t\tINSERÇÃO DE CADA ELEMENTO DA LISTA A EM B\n\n");
    insercaoInicio(&A, &B);

    printf("\nLista A: ");
    exibirLista(A);
    printf("\nLista B: ");
    exibirLista(B);

    int escolha;
    do{
        int op, num;
        // menu de opções:
        printf("\nEscolha a opção desejada:\n");
        printf("\n1 - Inserir no início da Lista\n");
        printf("\n2 - Inserir no final da Lista\n");
        printf("\n3 - Remover elemento no início da Lista\n");
        printf("\n4 - Remover elemento no final da Lista\n");
        printf("\n5 - Buscar elemento na Lista\n");
        printf("\n6 - Exibir Listas\n");
        printf("\n0 - Sair\n");
        scanf("%d", &escolha);

        if(escolha == 1 || escolha == 2 || escolha == 3 || escolha == 4 || escolha == 5){
            printf("\nEm qual lista desejar executar a operação escolhida?:\n1 - Lista A\n2 - Lista B\n");
            scanf("%d", &op);
        }

        switch(escolha){
            case 1:
                if (op == 1) {
                    printf("\nQual número deseja inserir?\n");
                    scanf("%d", &num);
                    printf("\nInserindo no início da Lista A...\n");
                    insercaoInicio2(&A, num);
                }
                else if (op == 2) {
                    printf("\nQual número deseja inserir?\n");
                    scanf("%d", &num);
                    printf("\nInserindo no início da Lista B...\n");
                    insercaoInicio2(&B, num);
                }
                else {
                    printf("\nOpção inválida!\n");
                }
                break;

            case 2:
                if (op == 1) {
                    printf("\nQual número deseja inserir?\n");
                    scanf("%d", &num);
                    printf("\nInserindo no final da Lista A...\n");
                    insercaoFim(&A, num);
                }
                else if (op == 2) {
                    printf("\nQual número deseja inserir?\n");
                    scanf("%d", &num);
                    printf("\nInserindo no final da Lista B...\n");
                    insercaoFim(&B, num);
                }
                else {
                    printf("\nOpção inválida!\n");
                }
                break;

            case 3:
                if (op == 1) {
                    printf("\nRemovendo no início da Lista A...\n");
                    remocaoInicio(&A);
                }
                else if (op == 2) {
                    printf("\nRemovendo no início da Lista B...\n");
                    remocaoInicio(&B);
                }
                else {
                    printf("\nOpção inválida!\n");
                }
                break;

             case 4:
                if (op == 1) {
                    printf("\nRemovendo no final da Lista A...\n");
                    remocaoFinal(&A);
                }
                else if (op == 2) {
                    printf("\nRemovendo no final da Lista B...\n");
                    remocaoFinal(&B);
                }
                else {
                    printf("\nOpção inválida!\n");
                }
                break;

            case 5:
                if (op == 1) {
                    printf("\nQual número deseja buscar?\n");
                    scanf("%d", &num);
                    printf("\nBuscando na Lista A...\n");
                    busca(&A, num);
                }
                else if (op == 2) {
                    printf("\nQual número deseja buscar?\n");
                    scanf("%d", &num);
                    printf("\nBuscando na Lista B...\n");
                    busca(&B, num);
                }
                else {
                    printf("\nOpção inválida!\n");
                }
                break;

            case 6:
                printf("\nLista A: ");
                exibirLista(A);
                printf("\nLista B: ");
                exibirLista(B);

                break;

            case 0:
                printf("\nSaindo do menu de opções!\n");
                break;

            default:
                printf("\nOpção inválida!\n");
                break;
        }
    } while(escolha != 0);


    printf("\nLista A: ");
    exibirLista(A);
    printf("\nLista B: ");
    exibirLista(B);

    printf("\nPrograma Finalizado!\n");

    return 0;
}
