#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno2.h"

// criando uma lista vazia:
Student* listaVazia(){
    return NULL;
}

// funcao que insere um novo aluno na lista:
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

// funcao que encontra as notas de um determinado aluno pela posicao:
int encontraEstudante(Student *lista, Student *aluno, int posicao){
    if (lista == NULL || posicao < 0)
        return 0;

    Student* aux = lista;
    int achou = 0;

    while(aux != NULL){
        if(achou == posicao){
            *aluno = *aux;
            return 1;
        }
        else{
            aux = aux->prox;
            achou++;
        }
    }
     return 0;
}

// funcao para retornar os alunos com media superior a 70 em uma nova lista:
Student* alunosSuperior70(Student *lista){
    if(lista == NULL)
        return 0;

    Student* nova_lista = NULL;
    Student* aux = lista;
    Student* aluno_NaMedia; // para servir como auxiliar da nova_lista.

    while(aux != NULL){
        float mediaSuperior = (aux->nota_pratica + aux->nota_teorica);

        if(mediaSuperior > 70){
            aluno_NaMedia = (Student*)malloc(sizeof(Student));

            if(aluno_NaMedia == NULL){
                return 0;
            }

            *aluno_NaMedia = *aux;
            aluno_NaMedia->prox = nova_lista;
            nova_lista = aluno_NaMedia;
        }
        aux = aux->prox;
    }

    return nova_lista;
}

// funcao que remove um aluno e as suas notas pela sua posicao:
Student* removendoAluno(Student *lista, int posicao){
    if (lista == NULL || posicao < 0)
        return lista;

    Student* aux = lista;
    Student* ant = NULL;
    int achou = 0;

    while(aux != NULL){
        if(achou == posicao){

            if(ant == NULL)
                lista = aux->prox;

            else
                ant->prox = aux->prox;

            free(aux);
            return lista;
        }
        else{
            ant = aux;
            aux = aux->prox;
            achou++;
        }
    }
    return lista;
}

// funcao que imprime a lista na tela para o usuario:
void imprimirLista(Student* lista){
    if(lista == NULL){
        printf("\nNao ha mais nada aqui!\n");
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

// funcao que libera a memoria ao final do programa:
void freeMemory(Student* lista){
    Student* aux;

    while(lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

    imprimirLista(lista); // apenas para visualizar que a memoria foi liberada!
}
