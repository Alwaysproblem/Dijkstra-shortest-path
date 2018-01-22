// Graph ADT
// Adjacency Matrix Representation ... COMP9024 17s2
#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct GraphRep {
   int  **edges;    //adjacency matrix
   int    nV;       //#vertices
   int    nE;       //#edges
} GraphRep;

Graph newGraph(int V) {
   assert(V >= 0);
   int i;

   Graph g = malloc(sizeof(GraphRep));
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
bool validV(Graph g, Vertex v) {
   return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e) {
   assert(g != NULL && validV(g,e.v) && validV(g,e.w));

   if (!g->edges[e.v][e.w]) {  // edge e not in graph
      g->edges[e.v][e.w] = 1;
      //g->edges[e.w][e.v] = 1;
      g->nE++;
   }
}

void removeEdge(Graph g, Edge e) {
   assert(g != NULL && validV(g,e.v) && validV(g,e.w));

   if (g->edges[e.v][e.w]) {   // edge e in graph
      g->edges[e.v][e.w] = 0;
      //g->edges[e.w][e.v] = 0;
      g->nE--;
   }
}

bool adjacent(Graph g, Vertex v, Vertex w) {
   assert(g != NULL && validV(g,v) && validV(g,w));

   return (g->edges[v][w] != 0);
}

void showGraph(Graph g) {
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++)
       for (j = i+1; j < g->nV; j++)
	  if (g->edges[i][j])
	      printf("Edge %d - %d\n", i, j);
}

void freeGraph(Graph g) {
   assert(g != NULL);

   int i;
   for (i = 0; i < g->nV; i++)
      free(g->edges[i]);
   free(g->edges);
   free(g);
}

/*****************Added*********************/

/*
void del_index_str(char *s, int pos, char *New_s){
	// the pos must be smaller than the length of s
	int k = 0;
	int j = 0;
	for(k = 0; s[k]!='\0'; k++){
		if(k == pos){
			New_s[j] = s[k+1];
			k += 1;
		}
		else{
			New_s[j] = s[k];	
		}
		j++;
	}
	New_s[k] = '\0';
}

unsigned char check_byte(char *parent, char *sucessor){
	int diff = 0;
	int k = 0;
	for(k=0;parent[k]!='\0';k++){
		if (parent[k] != sucessor[k]){
			diff += 1;
		}
	}
	if (diff == 1){
		return True;
	}
	else{
		return False;
	}
}

unsigned char del_byte(char *parent, char *sucessor){
	int k=0;
	int ans = False;
	char *new_parent = NULL;
	for(k=0;parent[k]!='\0';k++){
		new_parent = (char *)malloc(sizeof(char) * LEN_WORD);
		del_index_str(parent, k, new_parent);
		if (!strcmp(new_parent, sucessor) == True){
			ans = True;
			free(new_parent);
			return ans;
		}
		free(new_parent);
	}
	return ans;
}

unsigned char check_sucessor(char *parent, char *sucessor){
	int ans = False;
	if (strlen(parent) == strlen(sucessor)){
		ans = check_byte(parent, sucessor);
	}
	else if (strlen(parent) > strlen(sucessor)){
		ans = del_byte(parent, sucessor);
	}
	else{
		ans = del_byte(sucessor, parent);
	}
	return ans;
}



void find_sucessor(Graph g, char node[][LEN_WORD], int node_len){
	int i = 0, j = 0;
	for(i=0;i<node_len;i++){
		printf("%s:", node[i]);
		for(j=i;j<node_len;j++){
			if (check_sucessor(node[i], node[j]) == True){
				printf("%s  ", node[j]);
			}
		}
		printf("\n");
	}
}*/
