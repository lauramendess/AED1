#include "data2.h"

   Mes meses[] = {
      {1, "janeiro"}, {2, "fevereiro"}, {3, "marco"}, {4, "abril"},
      {5, "maio"}, {6, "junho"}, {7, "julho"}, {8, "agosto"},
      {9, "setembro"}, {10, "outubro"}, {11, "novembro"}, {12, "dezembro"}
  };

const char* nomeDoMes(int mes){
    int numMeses = sizeof(meses) / sizeof(meses[0]);

    for (int i = 0; i < numMeses; i++) {
        if (meses[i].numeroMes == mes) {
            return meses[i].nomeMes;
        }
    }
    return "mes invalido";
}

void imprimeExtenso2(int dia, int mes, int ano){
    int diasmes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
		diasmes[2] = 29;
		printf("Ano bissexto!\n");
    }

    if (ano < 1 || mes < 1 || mes > 12 || dia < 1 || dia > diasmes[mes]){
           printf("A data nao eh valida!\n");
           return 1;
    }

    else {
		printf("Data: %d de %s de %d\n", dia, nomeDoMes(mes), ano);
    }

    return 0;
}
