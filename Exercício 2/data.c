#include "data.h"

const char* mesExtenso(int mes){
    switch(mes){
        case 1: return "janeiro";
        case 2: return "fevereiro";
        case 3: return "marco";
        case 4: return "abril";
        case 5: return "maio";
        case 6: return "junho";
        case 7: return "julho";
        case 8: return "agosto";
        case 9: return "setembro";
        case 10: return "outubro";
        case 11: return "novembro";
        case 12: return "dezembro";
        default: return "mes invalido";
    }
}

void imprimeExtenso(int dia, int mes, int ano){
    const char* nomeMes = mesExtenso(mes);
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
		printf("Data: %d de %s de %d\n", dia, nomeMes, ano);
    }

    return 0;
}
