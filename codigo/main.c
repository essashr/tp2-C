#include "pacote.h"
#include "lista.h"
#include "drone.h"
#include "galpao.h"
#include <stdlib.h>
#include <time.h>

/* argumentos pra ler o arquivo na linha de comando e otimizar a execução*/
int main(int argc, char* argv[]) {
    FILE* arq = NULL;
    if (argc >= 2) {
        arq = fopen(argv[1], "r");
        if (!arq) {
            printf("Erro ao abrir o arquivo %s\n", argv[1]);
            return 1;
        }
    } else {
        // sem argumento: usa stdin (modo teclado)
        arq = stdin;
    }
    double pesoTEMP;
    int numTEMP;

    fscanf(arq, "%lf", &pesoTEMP);
    fscanf(arq, "%d", &numTEMP); 

    const double pesoMAX = pesoTEMP;
    const int numPacotes = numTEMP;

    galpao meuGalpao;
    drone meuDrone;
    int id_viagem = 1;
    inicializargalpao(&meuGalpao);
    inicializardrone(&meuDrone, pesoMAX);

    for(int i = 0; i < numPacotes; i++) {
        char conteudo[30], destinatario[30];
        double peso, distancia;
        int prioridade;
        fscanf(arq, "%s %s %lf %lf %d", conteudo, destinatario, &peso, &distancia, &prioridade);
        pacote p;
        inicializarpacote(&p, conteudo, destinatario, peso, distancia, prioridade);
        receberpacote(&meuGalpao, &p);
    }

    if (arq != stdin){
        fclose(arq);
    } else {
        /* Apenas por formatação */
        printf("\n");
    }

    /* Medição de tempo: */
    clock_t tempo_inicio, tempo_final;
    double tempo_total;
    tempo_inicio = clock();

    while(meuGalpao.l.primeiro != NULL) {
        carregarpacotes(&meuGalpao, &meuDrone);

        realizarentrega(&meuDrone, id_viagem);

        id_viagem++;
    }
    tempo_final = clock();
    tempo_total = ((double)(tempo_final - tempo_inicio)) / CLOCKS_PER_SEC;

    printf("Total de Quilômetros Percorridos no Dia: %.0lfkm.\n", meuDrone.dist_total);
    printf("Tempo de execução do algoritmo: %.6lfs\n", tempo_total);
    return 0;
}
