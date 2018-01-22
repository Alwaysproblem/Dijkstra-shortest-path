#ifndef  __DIJKSTRA_H__
#define  __DIJKSTRA_H__

#include <stdio.h>
#include <assert.h>
//#include "WGgraph.h"

#define  INF    0x7fffffff
// define the infinity of int number.
#define  None   -1
// define the previous node is none.

#define DDEBUG      1
#define NORMAL      0

#define VISITED     1
#define UNKNOWN     0

#define True        1
#define False       0

#define NOTUSED     -1
#define USED        0

void init_D_para(WGraph, int *, int *, int *, int *);

void relax_along(WGraph, int, int, int*, int*);

int * Dijkstra_Algorithm(WGraph, int, int);

void showPath(WGraph, int *, int *, int, int, int);

#endif
