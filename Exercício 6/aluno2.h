#ifndef _ALUNO2_H
#define _ALUNO2_H

struct lista_alunos {
    char nome[50];
    float nota_pratica, nota_teorica;
    struct lista_alunos *prox;
};

typedef struct lista_alunos Student;

// prototipo da funcao que cria uma lista vazia:
Student* listaVazia();

// prototipo da funcao que insere as informacoes do aluno:
Student* insereAluno(Student* lista, Student aluno);

// prototipo da funcao que encontra as notas de um determinado aluno:
int encontraEstudante(Student *lista, Student *aluno, int posicao);

// prototipo da funcao para retornar os alunos com media superior a 70 em uma nova lista:
Student* alunosSuperior70(Student *lista);

// prototipo da funcao que remove um aluno e as suas notas pela sua posicao:
Student* removendoAluno(Student *lista, int posicao);

// prototipo da funcao que imprime a lista na tela para o usuario:
void imprimirLista(Student* lista);

// prototipo da funcao que libera a memoria ao final do programa:
void freeMemory(Student* lista);

#endif
