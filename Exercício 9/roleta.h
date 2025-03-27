#ifndef _ROLETA_H
#define _ROLETA_H

struct roleta{
    int pessoa;
    struct roleta *prox;
    struct roleta *ant;
};
typedef struct roleta Roleta;

struct lista{
    Roleta *inicio;
    Roleta *fim;
};
typedef struct lista Lista;

void criar_Lista_vazia(Lista **l);
void primeiraPessoa(Lista **l, int N);
void inserirInicio(Lista **l, int N);
void remover(Lista *l, Roleta *remover);
void percursoFrente(Lista **l);
void percursoTras(Lista **l);
Roleta* buscarInicio(Lista *l, int inicio);
void escolhaLider(Lista *l, int K, int inicio);
void exibirPessoas(Lista *l);

#endif // _ROLETA_H
