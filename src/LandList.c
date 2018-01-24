//
//  LandList.c
//  Dij
//
//  Created by MengCheng on 24/1/18.
//  Copyright © 2018 MengCheng. All rights reserved.
//

#include "LandList.h"
#include <string.h>

typedef struct landmark{
    char * name;
    float coordinate_x;
    float coordinate_y;
    int index;
    int TotalNum;
}Building;


landList newLandList(int size){
    int idx = 0;
    landList l = (landList) malloc(size * sizeof(Building));
    for(idx = 0; idx < size; idx ++){
        l[idx].name = NULL;
        l[idx].coordinate_x = 0.0;
        l[idx].coordinate_y = 0.0;
        l[idx].index = UNSET;
        l[idx].TotalNum = size;
    }
    return l;
}

void setting_Building(landList l, char * name, int idx, int x, int y){
    l[idx].name = name;
    l[idx].coordinate_x = x;
    l[idx].coordinate_y = y;
    l[idx].index = idx;
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

int find_Building_by_coord(landList l, int x, int y){
    int idx = 0;
    int size = l[idx].TotalNum;
    for (idx = 0; idx < size; idx ++){
        if( (l[idx].coordinate_x == x) && (l[idx].coordinate_y == y) ){
            return idx;
        }
    }
    return ERROR;
}



void print_Building(landList l, int index){
    printf("*****************the Building info*********************\n");
    printf("the Building name is %s\n", l[index].name);
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



