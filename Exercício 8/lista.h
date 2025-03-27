#ifndef _LISTA_H
#define _LISTA_H

struct elemento{
    int dados;
    struct elemento *ant;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct lista{
    Elem *inicio;
    Elem *fim;
    int qnt;
};
typedef struct lista Lista;

// prot�tipos das fun��es utilizadas:
void criaListaVazia(Lista **li);
void insereDadosListas(Lista **li, int n, int aux);
void insercaoInicio(Lista **A, Lista **B);
void insercaoInicio2(Lista **li, int n); // nova fun��o de inser��o no in�cio que impede a inser��o de um elemento que j� exista na lista.
void insercaoFim(Lista **li, int n);
void remocaoInicio(Lista **li);
void remocaoFinal(Lista **li);
void busca(Lista **li, int n);
void exibirLista(Lista *li);

#endif // _LISTA_H
