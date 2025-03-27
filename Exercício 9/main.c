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

    printf("Quantas pessoas voc� deseja inserir na lista?\n");
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
        printf("\nOp��o inv�lida! Deve ser escolhido uma pessoa v�lida dentre as exibidas anteriormente!\n");
        printf("\nQual pessoa deve receber a caixa primeiro?\n");
        scanf("%d", &inicio);
    }

    K = rand() % 10 + 2; // sorteando um n�mero K entre 2 e 10 para n�o ficar t�o grande quando testar.
    printf("\nK = %d\n", K);

    percursoFrente(&romana);
    printf("\n");
    percursoTras(&romana);
    printf("\n");
    escolhaLider(romana, K, inicio);

    return 0;
}
