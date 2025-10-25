#ifndef DRONE_H
#define DRONE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"

typedef struct {
    double pesoMAX;
    double peso_carregado;
    double dist_total;
    lista l;
} drone;

// --- tipos auxiliares para o TP2 ---
typedef unsigned long marker;
extern const marker one;  /* será definido em drone.c */

typedef struct {
    double melhor_prioridade;
    marker melhor_comb;
} combinacao;

/* mudanças TP2 */
marker carregamentopacote(drone* d, lista* l); /* agora retorna um marker*/
void comb(int pool, int need, marker chosen, int at, pacote* vet, double pesoMAX, combinacao* com);

void inicializardrone(drone* d, double pesoMAX);
double realizarentrega(drone* d, int id);
void imprimirdrone(drone* d, double dist_viagem, int id);

#endif