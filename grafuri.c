#include <stdlib.h>
#include <stdio.h>
#include "grafuri.h"

Graph *create(){
    int i, j;
    Graph *g =(Graph*)malloc(sizeof(Graph));
    g->V=32;
    g->a = (int**)malloc(g->V * sizeof(int*));
    for(i=0; i< g->V; i++)
        g->a[i] = (int*)calloc(g->V, sizeof(int));

    g->E = 0;
    //este orientat

    return g;
}

void printGraph(Graph *g, FILE*graf){
    int i, j;
    for(i=0; i<g->V; i++){
        for(j=0; j<g->V; j++)
        fprintf(graf, "%d ", g->a[i][j]);
        fprintf(graf, "\n");
    }
}