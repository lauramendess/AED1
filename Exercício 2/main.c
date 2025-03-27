#include <stdio.h>
#include <stdlib.h>

 /* 
    Faça uma função que receba a data atual (dia, mês e ano em inteiro) e exiba-a na tela
    no formato textual por extenso. Exemplo: Data: 01/01/2000, Imprimir: 1 de janeiro de
    2000.   
 */

int main()
{
    int dia, mes, ano;

    printf("Digite a data no formato dd/mm/aaaa:\n");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    imprimeExtenso2(dia, mes, ano);

    return 0;
}
