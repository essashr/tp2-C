#ifndef PACOTE_H
#define PACOTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char conteudo[30];
    char destinatario[30];
    double peso;
    double distancia_km;
    int prioridade;
} pacote;

void inicializarpacote(pacote* p, char* conteudo, char* destinatario, double peso, double distancia_km, int prioridade);

char* getconteudo(pacote* p);
void setconteudo(pacote* p, char* conteudo);

char* getdestinatario(pacote* p);
void setdestinatario(pacote* p, char* destinatario);

double getpeso(pacote* p);
void setpeso(pacote *p, double peso);

double getdistancia_km(pacote* p);
void setdistancia_km(pacote *p, double distancia_km);

int getprioridade(pacote* p);
void setprioridade(pacote* p, int prioridade);

#endif