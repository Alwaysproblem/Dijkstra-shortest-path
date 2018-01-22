// Weighted Graph ADT interface

#include <stdbool.h> 
// this header file is included so that the boolean type can be used.

typedef struct WGraphRep *WGraph;
// new type called Weighted Graph

// vertices are ints
typedef int W_Vertex;

// edges are pairs of vertices (end-points)
typedef struct WEdge {
   W_Vertex v;
   W_Vertex w;
   int    weight;
} WEdge;


bool W_validV(WGraph, W_Vertex);
// check if the Vertex is the valid number.

WGraph W_newGraph(int);
// return a new weight Graph.

void  W_insertEdge(WGraph, WEdge);
// insert a Edge into a newgraph

void  W_removeEdge(WGraph, WEdge);
// delete a exist Edge 

int   W_adjacent(WGraph, W_Vertex, W_Vertex);  
// returns weight, or 0 if not adjacent

void  W_showGraph(WGraph);
// show a weight Graph

void  W_freeGraph(WGraph);
// release a weight Graph
