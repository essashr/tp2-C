#include "pacote.h"

void inicializarpacote(pacote* p, char* conteudo, char* destinatario, double peso, double distancia_km, int prioridade) {
    strcpy(p->conteudo, conteudo);
    strcpy(p->destinatario, destinatario);
    p->peso = peso;
    p->distancia_km = distancia_km;
    p->prioridade = prioridade;
}

char* getconteudo(pacote* p) {
    return p->conteudo;
}

void setconteudo(pacote* p, char* conteudo){
    strcpy(p->conteudo, conteudo);
}

char* getdestinatario(pacote* p) {
    return p->destinatario;
}

void setdestinatario(pacote* p, char* destinatario){
    strcpy(p->destinatario, destinatario);
}

double getpeso(pacote* p){
    return p->peso;
}

void setpeso(pacote *p, double peso){
    p->peso = peso;
}

double getdistancia_km(pacote* p){
    return p->distancia_km;
}

void setdistancia_km(pacote *p, double distancia_km){
    p->distancia_km = distancia_km;
}

int getprioridade(pacote* p){
    return p->prioridade;
}

void setprioridade(pacote *p, int prioridade){
    p->prioridade = prioridade;
}