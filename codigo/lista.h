#ifndef LISTA_H
#define LISTA_H

#include "pacote.h"

typedef struct celula{
    pacote p;
    struct celula* prox;
} celula;

typedef struct {
    celula* primeiro;
    celula* ultimo;
} lista;

void inicializarlista(lista* l);
void insercaolista(lista* l, pacote* p);
void remocaolista(lista* l, pacote* p);
void imprimirlista(lista* l);
/*TP2*/
int contarpacotes(lista* l);
void listaparaarray(lista* l, pacote* vetor);
void removerpacote(lista* l, pacote p);

#endif