//  LandList.c
//
//  Created by MengCheng on 24/1/18.
//  Copyright © 2018 MengCheng. All rights reserved.

#include "LandList.h"
#include <string.h>
#include <math.h>

typedef struct landmark{
    char name[MAX_NAME_LEN];
    float coordinate_x;
    float coordinate_y;
    int index;
    int TotalNum;
}Location;



landList newLandList(int size){
    int idx = 0;
    landList l = (landList) malloc(size * sizeof(Location));
    assert(l != NULL);
    for(idx = 0; idx < size; idx ++){
        strcpy(l[idx].name, " ");
        l[idx].coordinate_x = 0.0;
        l[idx].coordinate_y = 0.0;
        l[idx].index = UNSET;
        l[idx].TotalNum = size;
    }
    return l;
}

void setting_Building(landList l, char * name, int idx, int x, int y){
    l[idx].coordinate_x = x;
    l[idx].coordinate_y = y;
    l[idx].index = idx;
    strcpy(l[idx].name, name);
}


int find_Building_by_name(landList l, char * name){
    int idx = 0;
    int size = l[idx].TotalNum;
    for (idx = 0; idx < size; idx ++){
        if(strcmp(l[idx].name, name) == 0){
            return idx;
        }
    }
    return ERROR;
}

int find_Building_by_coord(landList l, float x, float y){
    int idx = 0;
    int size = l[idx].TotalNum;
    for (idx = 0; idx < size; idx ++){
        if( (fabs(l[idx].coordinate_x - x) < 1e-3) && ( fabs(l[idx].coordinate_y - y) < 1e-3) ){
            return idx;
        }
    }
    return ERROR;
}

void getName(landList l, int index, char *name){
    strcpy(name, l[index].name);
}

void print_Building(landList l, int index){
    printf("*****************the Location info*********************\n");
    printf("the Location name is %s\n", l[index].name);
    printf("the coordinate is (%.2f, %.2f)\n", l[index].coordinate_x, l[index].coordinate_y);
    printf("************************End****************************\n");
}


void print_list(landList l){
    int idx = 0;
    int size = l[idx].TotalNum;
    printf("This is the list of Buildings:\n");
    for(idx = 0; idx < size; idx ++){
        printf("the coordinate of %s is (%.2f, %.2f) --------------- %d (index of list)\n\n", l[idx].name, l[idx].coordinate_x, l[idx].coordinate_y, l[idx].index);
    }
}


void deleteLandList(landList l){
    free(l);
}



