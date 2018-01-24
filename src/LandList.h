#ifndef LandList_h
#define LandList_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define UNSET   -1
#define ERROR   -1
#define MAX_NAME_LEN    256

typedef struct landmark * landList;


landList newLandList(int size);

void setting_Building(landList l, char * name, int idx, int x, int y);

int find_Building_by_name(landList l, char * name);

int find_Building_by_coord(landList l, float x, float y);

void getName(landList l, int index, char *name);

void print_Building(landList l, int index);

void print_list(landList l);

void deleteLandList(landList l);

#endif /* LandList_h */
