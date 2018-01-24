#include "WGgraph.h"
#include "Dijkstra.h"
#include <stdlib.h>

int all_visited(int * visit, int size){
    int idx = 0;
    for(;idx < size; idx ++){
        if(visit[idx] != VISITED){
            return False;
        }
    }
    return True;
}


void init_D_para(WGraph g, int * dist, int * prev, int* visit, int * path){
    int idx = 0;
    for(idx = 0; idx < get_nV(g); idx ++){
        dist[idx] = INF;
        prev[idx] = None;
        visit[idx] = False;
        path[idx] = NOTUSED;
    }
}

void relax_along(WGraph g, int cur_node, int next_node, int* dist, int* prev){
    int alter = 0;
    if (W_adjacent(g, cur_node, next_node) != False){
        alter = dist[cur_node] + W_adjacent(g, cur_node, next_node);
        if (alter < dist[next_node]){
            dist[next_node] = alter;
            prev[next_node] = cur_node;
        }
    }
    
}


void showPath(WGraph g, int * prev, int * path, int src, int dest, int mode, int n){
    
    if (dest == src){
        if (mode == DDEBUG) printf("%d\n", src);
        path[n - 1] = src;
        return;
    }
    else{
        if (mode == DDEBUG) printf("%d <- ", dest);
        path[n - 1] = dest;
        showPath(g, prev, path, src, prev[dest], mode, n - 1);
    }
    
}


int * Dijkstra_Algorithm(WGraph g, int src, int dest){
    int idx = 0;
    int nV = get_nV(g);
    int * path = (int *) malloc(nV * sizeof(int));
    int * visit = (int *) malloc(nV * sizeof(int));
    int * dist = (int *) malloc(nV * sizeof(int));
    int * prev = (int *) malloc(nV * sizeof(int));
    
    int mini = INF;
    int idx_m = src;
    
    // initial the array.
    init_D_para(g, dist, prev, visit, path);
    
    while(all_visited(visit, nV) != True){
        mini = INF;
        idx_m = src;
        // this part mean to find node index of the minium distance.
        for(idx = 0; idx < nV; idx ++){
            if(visit[idx] == False){
                if (dist[idx] < mini){
                    mini = dist[idx];
                    idx_m = idx;
                }
            }
        }
        // relax along the distance.
        for(idx = 0; idx < nV; idx ++){
            if(visit[idx] == False){
                relax_along(g, idx_m, idx, dist, prev);
            }
        }
        
        visit[idx_m] = True;
    }
    
    showPath(g, prev, path, src, dest, NORMAL, nV);
    free(visit);
    free(dist);
    free(prev);
    
//    free(path);
    
    return path;
}

void delet_path(int * path){
    free(path);
}


