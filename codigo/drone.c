#include "drone.h"

const marker one = 1;

/*Abaixo o algoritmo de combinação, onde alteramos apenas o 
  comportamento quando os subconjuntos são criados*/
void comb(int pool, int need, marker chosen, int at, pacote* vet, double pesoMAX, combinacao* com) {
    if (pool < need + at) return; /* not enough bits left */

    /* got all we needed; */
    /* subconjunto de pacotes pronto para calcular*/
    if (!need) {
        double pesoT = 0.0, prioT = 0.0;
        for (int i = 0; i < pool; i++) { /* 1 */
            if (chosen & (one << i)) {
                pesoT += vet[i].peso; /* peso da combinação atual */
                prioT += vet[i].prioridade; /* prioridade da combinação atual */
            }
        }

        /* verifica e guarda a nova prioridade, além de marcar essa combinação
           (subconjunto) utilizando o chosen pra nova recursiva */
        if (pesoT <= pesoMAX && prioT > com->melhor_prioridade) { 
            com->melhor_prioridade = prioT;
            com->melhor_comb = chosen;
        }
        return;
    }
    /* if we choose the current item, "or" (|) the bit to mark it so. */
    comb(pool, need - 1, chosen | (one << at), at + 1, vet, pesoMAX, com);
    comb(pool, need, chosen, at + 1, vet, pesoMAX, com); /* or don't choose it, go to next */
}

/* Encontra o melhor subconjunto (maior soma de prioridade)
   que respeita o limite de peso do drone.
   Retorna um marker indicando os pacotes escolhidos. */
marker carregamentopacote(drone* d, lista* l) {
    int n = contarpacotes(l);
    if (n == 0) return 0;

    pacote vet[n];
    listaparaarray(l, vet);

    combinacao com;
    com.melhor_prioridade = -1;
    com.melhor_comb = 0;

    for (int k = 1; k <= n; k++) {
        comb(n, k, 0, 0, vet, d->pesoMAX, &com);
    }

    // Carrega no drone os pacotes da melhor combinação
    for (int i = 0; i < n; i++) {
        if (com.melhor_comb & (one << i)) {
            insercaolista(&(d->l), &(vet[i]));
            d->peso_carregado += vet[i].peso;
        }
    }

    return com.melhor_comb;
}

/*Operações do TP1 abaixo*/
void inicializardrone(drone* d, double pesoMAX) {
    d->pesoMAX = pesoMAX;
    d->peso_carregado = 0;
    d->dist_total = 0;
    inicializarlista(&(d->l)); 
}

double realizarentrega(drone* d, int idViagem) {
    celula* c = d->l.primeiro;
    double dist_viagem = 0.0;
    double pos_atual = 0.0;
    while (c != NULL) {
        dist_viagem += fabs(c->p.distancia_km - pos_atual);
        pos_atual = c->p.distancia_km;
        c = c->prox;
    }
    dist_viagem += pos_atual;
    d->dist_total += dist_viagem;

    imprimirdrone(d, dist_viagem, idViagem);

    while (d->l.primeiro != NULL) {
        pacote tmp;
        remocaolista(&(d->l), &tmp);
    }
    d->peso_carregado = 0;

    return dist_viagem;
}

void imprimirdrone(drone* d, double dist_viagem, int id) {
    int prioridades = 0;
    printf("Viagem %d\n", id);
    celula* c = d->l.primeiro;
    while(c != NULL) {
        printf("%s %s %.0lfkm - peso: %.0lfkg - prioridade: %d\n", c->p.conteudo, c->p.destinatario, c->p.distancia_km, c->p.peso, c->p.prioridade);
        prioridades += c->p.prioridade;
        c = c->prox;
    }
    printf("Prioridade de entrega: %d\n", prioridades);
    printf("Distância Total: %.0lfkm\n\n", dist_viagem);
}