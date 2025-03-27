#include <stdio.h>
#include <locale.h>
#include "inteiro.h"

// Crie uma função que recebe como parâmetro um nÚmero inteiro e devolve o seu dobro.

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int num;

    printf("Insira um n�mero inteiro:\n");
    scanf("%d", &num);

    int dobro = calculaDobro(num);

    printf("O dobro de %d eh d\n", num, dobro);

    return 0;
}
