#include <stdio.h>
#include "WGgraph.h"
#include "Dijkstra.h"

int main(){
//    int nV = 0;
//    printf("please input the number of landmark in the map:\n");
//    scanf("%d", &nV);
//    if (nV < 1 || nV > 10000){                                              // limited the number of landmark because of the memory size.
//        printf("There is no map on my memory, Sorry Sir.\n");
//        return 0;
//    }
    /* just for test */
    int nV = 6;
    WEdge e[9];
    e[0].v = 0;
    e[0].w = 1;
    e[0].weight = 14;
    e[1].v = 0;
    e[1].w = 2;
    e[1].weight = 9;
    e[2].v = 0;
    e[2].w = 3;
    e[2].weight = 7;
    e[3].v = 1;
    e[3].w = 2;
    e[3].weight = 4;
    e[4].v = 2;
    e[4].w = 3;
    e[4].weight = 10;
    e[5].v = 1;
    e[5].w = 4;
    e[5].weight = 5;
    e[6].v = 2;
    e[6].w = 5;
    e[6].weight = 3;
    e[7].v = 3;
    e[7].w = 5;
    e[7].weight = 15;
    e[8].v = 4;
    e[8].w = 5;
    e[8].weight = 8;
    /* ******end***** */
    
    WGraph g = W_newGraph(nV);                                              // a new map.
    int idx = 0;
    for(idx = 0; idx < 9; idx ++){
        W_insertEdge(g, e[idx]);
    }
    
    W_showGraph(g);
    
    Dijkstra_Algorithm(g, 2, 4);
    
    W_freeGraph(g);                                                         //delete the map.
    return 0;
}

