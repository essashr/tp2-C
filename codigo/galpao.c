#include "galpao.h"

void inicializargalpao(galpao* g) {
    inicializarlista(&(g->l)); 
}

void receberpacote(galpao* g, pacote* p) {
    insercaolista(&(g->l), p); 
}

/*agora alterada para remover pacotes específicos*/
void carregarpacotes(galpao* g, drone* d) {
    marker escolhidos = carregamentopacote(d, &(g->l));
    if (!escolhidos) return;

    int n = contarpacotes(&(g->l));
    pacote vet[n];
    listaparaarray(&(g->l), vet);

    // Remove do galpão os pacotes que foram carregados
    for (int i = 0; i < n; i++) {
        if (escolhidos & (one << i)) {
            removerpacote(&(g->l), vet[i]);
        }
    }
}

void imprimirgalpao(galpao* g) {
    printf("Pacotes restantes no galpão:\n");
    celula* c = g->l.primeiro;
    while(c != NULL) {
        printf("%s para %s, peso: %.2lfkg, distância: %.0lfkm\n",
               c->p.conteudo, c->p.destinatario, c->p.peso, c->p.distancia_km);
        c = c->prox;
    }
}