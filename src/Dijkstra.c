//#include "WGgraph.h"
//#include "Dijkstra.h"
//
//
//int all_visited(int * visit, int size){
//    int idx = 0;
//    for(;idx < size; idx ++){
//        if(visit[idx] != VISITED){
//            return False;
//        }
//    }
//    return True;
//}
//
//
//void init_D_para(WGraph g, int * dist, int * prev, int* visit, int * path){
//    int idx = 0;
//    for(idx = 0; idx < g->nV; idx ++){
//        dist[idx] = INF;
//        prev[idx] = None;
//        visit[idx] = False;
//        path[idx] = NOTUSED;
//    }
//}
//
//void relax_along(WGraph g, int cur_node, int next_node, int* dist, int* prev){
//    int alter = 0;
//    if (W_adjacent(g, cur_node, next_node) != False){
//        alter = dist[cur_node] + W_adjacent(g, cur_node, next_node);
//        if (alter < dist[next_node]){
//            dist[next_node] = alter;
//            prev[next_node] = cur_node;
//        }
//    }
//    else{
//        
//    }
//    
//}
//
//int * Dijkstra_Algorithm(WGraph g, int src, int dest){
//    int idx = 0;
//    int * path = (int *)malloc(g->nV * sizeof(int));
//    int * visit = (int *)malloc(g->nV * sizeof(int));
//    int * dist = (int *)malloc(g->nV * sizeof(int));
//    int * prev = (int *)malloc(g->nV * sizeof(int));
//    
//    // initial the array.
//    init_D_para(g, dist, prev, visit, path);
//    
//    while(all_visited(visit, g->nV) != True){
//        mini = INF;
//        idx_m = src;
//        // this part mean to find node index of the minium distance.
//        for(idx = 0; idx < g->nV; idx ++){
//            if(visit[idx] == False){
//                if (dest[idx] < mini){
//                    mini = dest[idx];
//                    idx_m = idx;
//                }
//            }
//        }
//        // relax along the distance.
//        for(idx = 0; idx < g->nV; idx ++){
//            if(visit[idx] == False){
//                relax_along(g, idx_m, idx, dist, prev);
//            }
//        }
//    }
//    
//    showPath(g, prev, path, dest);
//    free(visit);
//    free(dist);
//    free(prev);
//}
//
//void showPath(WGraph g, int * prev, int * path, int dest, mode){
//    
//    if (mode == DDEBUG){
//        printf("%d <- ", dest);
//    }
//    
//    if (dest == src){
//        return;
//    }
//    else{
//        showPath(g, prev, path, prev[dest], mode);
//    }
//}

