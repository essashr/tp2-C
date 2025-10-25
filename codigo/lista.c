#include "pacote.h"
#include "lista.h"

// --- tipos auxiliares para o TP2 ---
/* conta a quantidade de pacotes da lista */
int contarpacotes(lista* l) {
    int count = 0;
    celula *c = l->primeiro;
    while (c != NULL) {
        count++;
        c = c->prox;
    }
    return count;
}

/* transforma lista em array */
void listaparaarray(lista* l, pacote* vetor) {
    int i = 0;
    celula *c = l->primeiro;
    while (c!= NULL) {
        vetor[i++] = c->p;
        c = c->prox;
    }
}

/*remove um pacote específico da lista*/
void removerpacote(lista* l, pacote p) {
    celula* ant = NULL;
    celula* atual = l->primeiro;
    while (atual) {
        if (strcmp(atual->p.conteudo, p.conteudo) == 0 &&
            strcmp(atual->p.destinatario, p.destinatario) == 0 &&
            atual->p.peso == p.peso &&
            atual->p.distancia_km == p.distancia_km &&
            atual->p.prioridade == p.prioridade) {

            if (ant == NULL) {
                l->primeiro = atual->prox;
            } else {
                ant->prox = atual->prox;
            }

            if (atual == l->ultimo)
                l->ultimo = ant;

            free(atual);
            return;
        }
        ant = atual;
        atual = atual->prox;
    }
}


// TP1:
void inicializarlista(lista* l) {
    l->primeiro = NULL;
    l->ultimo = NULL;
}

void insercaolista(lista* l, pacote* p){
    celula* new = malloc(sizeof(*new));
    if (new == NULL) {
        printf("Memória insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    new->p = *p;
    new->prox = NULL;

    if(l->primeiro == NULL){
        l->primeiro = new; 
        l->ultimo = new;
    } else {
        l->ultimo->prox = new;
        l->ultimo = new;
    }
}

void remocaolista(lista* l, pacote* p) {
    if (l->primeiro != NULL) {
        celula* c = l->primeiro;
        *p = c->p;
        l->primeiro = c->prox;
        if (l->primeiro == NULL) {
            l->ultimo = NULL;
        }
        free(c);
    } else {
        printf("Lista vazia.\n");
    }
}

void imprimirlista(lista* l) {
    celula* current = l->primeiro;
    while (current != NULL) {
        printf("Conteudo: %s | Destinatario: %s | Peso: %.2f | Distancia: %.2f\n",
               current->p.conteudo,
               current->p.destinatario,
               current->p.peso,
               current->p.distancia_km);
        current = current->prox;
    }
}
