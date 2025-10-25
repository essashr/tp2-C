#ifndef GALPAO_H
#define GALPAO_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "drone.h"

typedef struct {
    lista l;
}galpao;

void inicializargalpao(galpao* g);
void receberpacote(galpao* g, pacote* p);
void carregarpacotes(galpao* g, drone* d);
void imprimirgalpao(galpao* g);

#endif