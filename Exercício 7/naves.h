#ifndef _NAVES_H
#define _NAVES_H

struct no{
    int capMaxima; // Capacidade máxima de combustível;
    int combAtual; // Combustível atual;
    int indice; // Índice para identificação da nave;
    struct no *prox; // Ponteiro para a próxima nave;
};
typedef struct no Nave;

struct lista{
    Nave *inicio; // Ponteiro para o início da lista;
    Nave *fim;  // Ponteiro para o fim da lista;
};
typedef struct lista Lista;

void criaLista(Lista **li);
void entradaUsuario(int *qntInicial, int *qntMax, int indice);
void criaPrimeiro(Lista **li, int *qntMax, int *qntAtual, int *indice);
void inserirInicio(Lista **li, int *qntMax, int *qntAtual, int *indice);
void inserirFinal(Lista **li, int *qntMax, int *qntAtual, int *indice);
void abastecerNaves(Lista **li, int *qntCiclo);
void percorrerNaves(Lista **li);

#endif // _NAVES_H

