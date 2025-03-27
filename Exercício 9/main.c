#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "roleta.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista *romana;
    criar_Lista_vazia(&romana);

    int N, K;
    srand(time(NULL));

    printf("Quantas pessoas você deseja inserir na lista?\n");
    scanf("%d", &N);

    printf("\nInserindo as pessoas...\n");
    for(int i = 1; i <= N; i++){
        inserirInicio(&romana, i);
    }

    exibirPessoas(romana);

    int inicio;
    printf("\nQual pessoa deve receber a caixa primeiro?\n");
    scanf("%d", &inicio);

    while(inicio <= 0 || inicio > N){
        printf("\nOpção inválida! Deve ser escolhido uma pessoa válida dentre as exibidas anteriormente!\n");
        printf("\nQual pessoa deve receber a caixa primeiro?\n");
        scanf("%d", &inicio);
    }

    K = rand() % 10 + 2; // sorteando um número K entre 2 e 10 para não ficar tão grande quando testar.
    printf("\nK = %d\n", K);

    percursoFrente(&romana);
    printf("\n");
    percursoTras(&romana);
    printf("\n");
    escolhaLider(romana, K, inicio);

    return 0;
}
