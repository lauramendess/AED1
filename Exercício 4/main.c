#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavras.h"

/*
     Fazer:
     - função de inserção;
     - função de busca;
     - função de remoção;
     - função de remoção de palavras repetidas;
     - função de verificar se o número é primo ou não;
     - função de copiar em uma nova lista as palavras cujo tamanho seja um número primo;
     - função recursiva que conta o número de palavras na lista
     - função não recursiva que conta o número de palavras na lista
*/

int main(){
   No *listinha;
   criaListaVazia(&listinha);

   FILE *arquivo = fopen("palavras.txt", "r");
   if(arquivo == NULL){
        printf("Erro! O arquivo nao pode ser aberto.\n");
        exit(1);
   } else{
        printf("O arquivo foi aberto com sucesso!\n\n");
   }

   char words[30];
   while (fscanf(arquivo, "%s", words) != EOF){
        inserePalavras(&listinha, words);
   }

   fclose(arquivo); // fechando o arquivo que foi utilizado para ler as palavras para a lista.

   printf("Imprimindo lista de palavras lidas do arquivo.txt:\n");
   imprimirLista(&listinha);

   char *palavrinha = "playstation";
   No *busca = buscaPalavras(&listinha, palavrinha);
   // função que busca palavras:
   if(busca != NULL){
        printf("\nA palavra %s esta na lista!\n", busca->palavra);
   } else {
        printf("\nA palavra %s nao esta na lista!\n", palavrinha);
   }

   char *remove = "jogos";
   remocaoPalavras(&listinha, remove);
   printf("\nImprimindo lista de palavras apos a remocao da palavra '%s'.\n", remove);
   imprimirLista(&listinha);

   removeRepetidas(&listinha);

   printf("\nImprimindo lista de palavras apos remocao de palavras repetidas:\n");
   imprimirLista(&listinha);

   No *listinhaprimos = copiaPrimos(&listinha);
   printf("\nImprimindo a nova lista que contém apenas palavras em que o seu tamanho e um numero primo:\n");
   imprimirLista(&listinhaprimos);

   // conta recursiva:
   int numeroPalavras = contaRecursiva(listinha);
   printf("\nNumero de palavras na lista: %d\n", numeroPalavras);

   // conta não recursiva:
   int numeroPalavras2 = contaNaoRecursiva(listinha);
   printf("\nNumero de palavras na lista: %d\n", numeroPalavras2);

   // liberando a memória alocada:
   liberaMemoria(&listinha);

   return 0;
}
