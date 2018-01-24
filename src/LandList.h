#ifndef LandList_h
#define LandList_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define UNSET   -1
#define ERROR   -1

typedef struct landmark * landList;


landList newLandList(int size);

void print_Building(landList l, int index);

void print_list(landList l);

void deleteLandList(landList l);

#endif /* LandList_h */
