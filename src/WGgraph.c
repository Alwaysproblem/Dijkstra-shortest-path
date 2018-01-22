// Weighted Graph ADT
// Adjacency Matrix Representation
#include "WGgraph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct WGraphRep {
   int **edges;  // adjacency matrix storing positive weights
                // 0 if nodes not adjacent
   int nV;       // #vertices
   int nE;       // #edges
} WGraphRep;


WGraph W_newGraph(int V){
   assert(V >= 0);
   int i;

   WGraph g = malloc(sizeof(WGraphRep));
   assert(g != NULL);
   g->nV = V;
   g->nE = 0;

   // allocate memory for each row
   g->edges = malloc(V * sizeof(int *));
   assert(g->edges != NULL);
   // allocate memory for each column and initialise with 0
   for (i = 0; i < V; i++) {
      g->edges[i] = calloc(V, sizeof(int));
      assert(g->edges[i] != NULL);
   }

   return g;
}

// check if vertex is valid in a graph
bool W_validV(WGraph g, W_Vertex v) {
   return (g != NULL && v >= 0 && v < g->nV);
}

void W_insertEdge(WGraph g, WEdge e) {
   assert(g != NULL && W_validV(g,e.v) && W_validV(g,e.w));

   if (g->edges[e.v][e.w] == 0) {   // edge e not in graph
      g->edges[e.v][e.w] = e.weight;
      g->edges[e.w][e.v] = e.weight;
      g->nE++;
   }
}

void W_removeEdge(WGraph g, WEdge e) {
   assert(g != NULL && W_validV(g,e.v) && W_validV(g,e.w));

   if (g->edges[e.v][e.w] != 0) {   // edge e in graph
      g->edges[e.v][e.w] = 0;
      g->edges[e.w][e.v] = 0;
      g->nE--;
   }
}

int W_adjacent(WGraph g, W_Vertex v, W_Vertex w) {
   assert(g != NULL && W_validV(g,v) && W_validV(g,w));

   return g->edges[v][w];
}

void W_showGraph(WGraph g) {
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++){
        for (j = i+1; j < g->nV; j++){
            if (g->edges[i][j] != 0){
                printf("WEdge %d - %d: %d\n", i, j, g->edges[i][j]);
            }
        }
    }
}

void W_freeGraph(WGraph g) {
   assert(g != NULL);

   int i;
   for (i = 0; i < g->nV; i++){
        free(g->edges[i]); 
   }
   free(g->edges);
   free(g);
}
