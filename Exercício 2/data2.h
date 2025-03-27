#ifndef _DATA2_H
#define _DATA2_H

  typedef struct{
    int numeroMes;
    const char* nomeMes;
  } Mes;

  const char* nomeDoMes(int mes);
  void imprimeExtenso2(int dia, int mes, int ano);

#endif
