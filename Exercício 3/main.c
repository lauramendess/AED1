#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "aluno.h"

/*
  Usando estrutura de nós encadeados, defina uma estrutura para a organização das informações de um aluno, contando com
  seu nome, nota prática (até 50) e nota teórica (até 50) de uma disciplina. Organize o código para que se possa:

    - encontrar as notas de um determinado aluno
    - retornar os alunos com média superior a 70 em uma nova lista
    - remover um aluno (e suas notas)
*/

int main()
{
    Student *lista;
    lista = listaVazia();
    int n;

    printf("Quantos alunos deseja inserir?\n");
    scanf("%d", &n);

    printf("Insira os dados do(s) aluno(s):\n");
    for(int i = 0; i < n; i++){
        Student aluno;

        printf("\nNome do aluno: ");
        scanf("%s", aluno.nome);

        printf("Nota pratica (ate 50): ");
        scanf("%f", &aluno.nota_pratica);



        printf("Nota teorica (ate 50): ");
        scanf("%f", &aluno.nota_teorica);

        lista = insereAluno(lista, aluno);
    }

    printf("\n--------------Imprimindo lista:--------------\n");
    imprimirLista(lista);
    printf("\n---------------------------------------------\n");

    return 0;
}
