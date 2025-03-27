#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "aluno2.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Student *lista;
    lista = listaVazia();

    Student alunos[5] = {{"Laura", 45.0, 40.5},
                              {"Tainan", 20.0, 47.5},
                              {"Uilgner", 17.1, 24.9},
                              {"Eliane", 49.9, 39.9},
                              {"Geovana", 45.0, 40.5}};

    for(int i = 0; i < 5; i++){
        lista = insereAluno(lista, alunos[i]);
    }

    printf("--------------Imprimindo lista:--------------\n");
    imprimirLista(lista);
    printf("\n---------------------------------------------\n");

    // neste caso, iremos buscar o aluno pela posicao que ele ocupa!
    int buscandoNotas = encontraEstudante(lista, alunos, 3);

    if(buscandoNotas == 1){
         printf("Imprimindo as notas do(a) aluno(a) buscado:\n");
         printf("\nAluno(a) buscado: %s\nSUAS NOTAS:\nNota Pratica = %.1f\nNota Teorica = %.1f", alunos->nome, alunos->nota_pratica, alunos->nota_teorica);
         printf("\n---------------------------------------------\n");
    }
    else{
         printf("\nO aluno e as suas notas nao foram encontrados.\n");
    }

    // verificando se existem alunos com media superior a 70 e retornando caso exista!
    Student *media = alunosSuperior70(lista);
    printf("Estudantes com media superior a 70:\n");
    imprimirLista(media);
    printf("\n---------------------------------------------\n");

    // neste caso, iremos remover o aluno pela posicao que ele ocupa:
    lista = removendoAluno(lista, 0);

    printf("----Imprimindo a lista novamente:----\n");
    imprimirLista(lista);
    printf("\n---------------------------------------------\n");

    freeMemory(lista);

    return 0;
}
