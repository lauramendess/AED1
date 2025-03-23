#ifndef _ALUNO_H
#define _ALUNO_H

struct lista_alunos{
    char nome[50];
    float nota_pratica, nota_teorica;
    struct lista_alunos *prox;
};

typedef struct lista_alunos Student;

// protótipo da função que cria uma lista vazia:
Student* listaVazia();

// protótipo da função que insere as informações do aluno:
Student* insereAluno(Student* lista, Student aluno);

// protótipo da função que imprime a lista na tela para o usuário:
void imprimirLista(Student* lista);

#endif // _ALUNO_H