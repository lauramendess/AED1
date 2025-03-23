#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

// criando uma lista vazia:
Student* listaVazia(){
    return NULL;
}

// função que insere um novo aluno na lista:
Student* insereAluno(Student* lista, Student aluno){
    Student* novo;
    novo = (Student*)malloc(sizeof(Student));

    if(novo == NULL){
        return 0;
    }

    strcpy(novo->nome, aluno.nome);
    novo->nota_pratica = aluno.nota_pratica;
    novo->nota_teorica = aluno.nota_teorica;
    novo->prox = lista;
    lista = novo;

    return lista;
}

// função que imprime a lista na tela para o usuário:
void imprimirLista(Student* lista){
    if(lista == NULL){
        return;
   }

    Student* atual = lista;
    while (atual != NULL) {
        printf("\nNome do Aluno(a): %s\n", atual->nome);
        printf("Nota Pratica: %.1f\n", atual->nota_pratica);
        printf("Nota Teorica: %.1f\n", atual->nota_teorica);

        atual = atual->prox;
    }
}