#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "naves.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista *nave;
    criaLista(&nave);

    int qntInicial, qntMax, qntCiclo, qntNaves, opcao;

    printf("Quantas naves voce deseja inserir?\n");
    scanf("%d", &qntNaves);
    printf("\nQual a quantidade de combustivel por ciclo que sera distribuida entre as naves?\n");
    scanf("%d", &qntCiclo);

    for(int i = 0; i < qntNaves; i++){
        entradaUsuario(&qntInicial, &qntMax, i);

        printf("\nEscolha aonde deseja inserir a Nave %d:\n", i);
        printf("\n1 - Inicio\n");
        printf("2 - Final\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                inserirInicio(&nave, &qntMax, &qntInicial, &i);
                break;
            case 2:
                inserirFinal(&nave, &qntMax, &qntInicial, &i);
                break;
            default:
                printf("\nOpcao Invalida!\n");
                break;
        }
    }

    abastecerNaves(&nave, &qntCiclo);

    printf("\nFim do programa!");

    return 0;
}
