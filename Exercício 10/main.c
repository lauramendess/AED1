#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "dicionario.h"

int main(){
    setlocale(LC_ALL, "Portuguese");

    No *lista;
    lista = criaListaVazia();
    lendoArquivo(&lista);

    Pilha *p;
    inicializarPilha(p);

    int op;
    char palavra[30];
    do{
        printf("MENU DE OPÇÕES");
        printf("\n1 - Procurar por um verbete e seus respectivos dados (classificação e significado).\n");
        printf("2 - Ver dicionário completo de palavras.\n");
        printf("3 - Ler frases e imprimir palavras com seus respectivos dados (classificação e significado).\n");
        printf("0 - Fechar Menu.\n");
        scanf("%d", &op);

        switch (op){
            case 1:
                printf("\nPor qual palavra você deseja procurar?\n");
                scanf("%s", palavra);
                formataPalavra(palavra);

                No *encontrado = encontrarVerbete(lista, palavra);
                if(encontrado){
                    printf("\nA palavra '%s' foi encontrada no dicionário!\n", encontrado->verbete);
                    printf("Verbete: %s\n", encontrado->verbete);
                    printf("Classificação: %s\n", encontrado->classificacao);
                    printf("Significado: %s\n\n", encontrado->significado);
                }
                else
                    printf("\nA palavra '%s' não foi encontrada no dicionário!\n\n", palavra);

                break;

            case 2:
                imprimirDicionario(lista);
                break;

            case 3:
                lendoFrases(&p, lista);
                break;

            case 0:
                printf("\nVocê encerrou o menu de opções!\n");
                break;

            default:
                printf("\nOpção Inválida!\n");
                break;
        }

    }while(op != 0);

    return 0;
}
