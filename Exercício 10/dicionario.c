#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dicionario.h"

No* criaListaVazia(){
   return NULL;
}

void lendoArquivo(No **lista){
   FILE *arquivo = fopen("verbetes.txt", "r");

   if(arquivo == NULL){
        printf("Erro! O arquivo não pode ser aberto.\n\n");
        exit(1);
   } else{
        printf("O arquivo foi aberto com sucesso!\n\n");
   }

   char verbete[30], classificacao[20], significado[150];

   while (fscanf(arquivo, "%[^\n]\n%[^\n]\n %[^\n]\n", verbete, classificacao, significado) != EOF){
        inserenaLista(lista, verbete, classificacao, significado);
   }
   fclose(arquivo);
}

No* criaNo(char *verbete, char *classificacao, char *significado){
    No *novoNo = (No*)malloc(sizeof(No));

    if(novoNo == NULL) return 0;

    strcpy(novoNo->verbete, verbete);
    strcpy(novoNo->classificacao, classificacao);
    strcpy(novoNo->significado, significado);
    novoNo->prox = NULL;

    return novoNo;
}

void inserenaLista(No **lista, char *verbete, char *classificacao, char *significado){
    No *l = criaNo(verbete, classificacao, significado);
    No *aux = *lista;
    No *ant = NULL;

    while(aux != NULL && strcmp(aux->verbete, verbete) < 0){
        ant = aux;
        aux = aux->prox;
    }
    if(ant == NULL){
        l->prox = *lista;
        *lista = l;
    }else{
        ant->prox = l;
        l->prox = aux;
    }
}

void imprimirDicionario(No *lista){
   if(lista == NULL){
        printf("\nNão há mais nada aqui!\n");
        return;
   }

    No *aux = lista;
    while(aux != NULL){
        printf("Verbete: %s\n", aux->verbete);
        printf("Classificação: %s\n", aux->classificacao);
        printf("Significado: %s\n\n", aux->significado);
        aux = aux->prox;
    }
}

No* encontrarVerbete(No *lista, char *palavra){
    if(lista == NULL) return 0;

    No *aux = lista;

    while(aux != NULL){
        if(strcmp(aux->verbete, palavra) == 0){
            return aux;
        } else{
            aux = aux->prox;
        }
    }
    return 0;
}

void formataPalavra(char *palavra){
    int i = 0;

    if (palavra[i] != '\0') {
        palavra[i] = toupper(palavra[i]);
        i++;
    }

    while (palavra[i] != '\0') {
        palavra[i] = tolower(palavra[i]);
        i++;
    }
}

void inicializarPilha(Pilha *p){
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));

    if(pi != NULL){
        pi->topo = NULL;
        pi->tam = 0;
    }
}

int pilhaVazia(Pilha *p){
    return p->topo == NULL;
}

void lendoFrases(Pilha *p, No *lista){
   FILE *arquivo = fopen("frases.txt", "r");
   char buffer[256];

   if(arquivo == NULL){
        printf("Erro! O arquivo não pode ser aberto.\n\n");
        exit(1);
   } else{
        printf("O arquivo foi aberto com sucesso!\n\n");
   }

    while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        char *palavra = strtok(buffer, " ");
        while (palavra != NULL) {
            formataPalavra(palavra);
            empilhaPalavras(p, palavra);
            palavra = strtok(NULL, " ");
        }
    }
    imprimirPilha(p, lista);
    fclose(arquivo);
}

void empilhaPalavras(Pilha *p, char *palavra){
    noPilha *nova = (noPilha*)malloc(sizeof(noPilha));

    if (nova == NULL) return;

    strcpy(nova->palavras, palavra);
    nova->prox = p->topo;
    p->topo = nova;
    p->tam++;
}

char* desempilhaPalavras(Pilha *p){
    noPilha *aux;

    if (pilhaVazia(p)) {
        printf("Não há nada aqui!\n");
        return 0;
    }

    aux = p->topo;
    p->topo = aux->prox;
    char *verbete= strdup(aux->palavras);
    free(aux);
    p->tam--;

    return verbete;
}

void imprimirPilha(Pilha *p, No* lista){
    while (!pilhaVazia(p)) {
        char *palavra = desempilhaPalavras(p);

        if (palavra) {
            No *verbete = encontrarVerbete(lista, palavra);
            if (verbete) {
                printf("Verbete: %s\n", verbete->verbete);
                printf("Classificação: %s\n", verbete->classificacao);
                printf("Significado: %s\n\n", verbete->significado);
            } else {
                printf("Palavra '%s' não encontrada no dicionário.\n\n", palavra);
            }
            free(palavra);
        }
    }
}
