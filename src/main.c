#include <stdio.h>
#include "WGgraph.h"
#include "Dijkstra.h"
#include "LandList.h"



void print_help(void);

int main(){
    
    char mode = '\0';                                                          // the mode of application.
    char S_mode = '\0';                                                        // the mode for search
    char S_name[MAX_NAME_LEN] = "kkk";                                         // the name for search
    float x = 0;
    float y = 0;                                                                // the coordinate x,y
    int S_idx = 0;                                                             // the index of searching result.
    int nV = 0;                                                                // the number of landmarks.
    int nE = 0;                                                                // the number of road.
    int src = 0;                                                               // the index of source point.
    int dest = 3;                                                              // the index of destination point.
    
    WGraph g = NULL;
    landList l = NULL;
    int * path = NULL;
    
    printf("Hello, Sir, I am always at your service.\n");
    print_help();
    while (True) {
        int i = 0;
        char name[MAX_NAME_LEN];
        float cx = 0.0;
        float cy = 0.0;
        
        
        printf("please select a mode for this application:\n>>> ");
        scanf("%s", &mode);
        
        
        switch (mode) {
            case 'a':
            case 'A':
                if (g == NULL || l == NULL){
                    printf("please input the number of landmarks: ");
                    scanf("%d", &nV);
                }

                if (g == NULL){
                    g = W_newGraph(nV);                                              // a new map.
                }
                if (l == NULL){
                    l  = newLandList(nV);                                            // a new Location list.
                }
                printf("please input all the landmark or Buildings:\n");
                for (i = 0; i < nV; i++){
                    printf("please give me the info for the Location %d:\n", i);
                    printf("the name : ");
                    scanf("%s", name);
                    
                    printf("please, tell me what the coordinate is:\nx is\n>>> ");
                    scanf("%f", &cx);
                    printf("y is \n>>> ");
                    scanf("%f", &cy);
                    
                    setting_Building(l, name, i, cx, cy);
                }
                printf("please input the number of Roads or Streets: ");
                scanf("%d", &nE);
                print_list(l);
                
                printf("According to the list that I give you\n");
                printf("Please offer me the road by the index of list.\nThe example of input is like \"1, 2, 3\". \n");
                printf("It means lcation 1 is connected with location 2.\n");
                printf("The distance between 1 and 2 is 3.\n");
                
                for (i = 0; i < nE; i++){
                    int loc_1 = 0.0;
                    int loc_2 = 0.0;
                    int weight = 0.0;
                    WEdge a;
                    
                    printf(">>> ");
                    scanf("%d, %d, %d", &loc_1, &loc_2, &weight);

                    a.v = loc_1;
                    a.w = loc_2;
                    a.weight = weight;
                    W_insertEdge(g, a);
                }
                
                break;
                
            case 'f':
            case 'F':
                
                if (l != NULL){
                    printf("please tell me which type do you want to search?\n\n");
                    printf("n/N -- name for searching.\n");
                    printf("o/O -- coodinate for searching.\n");
                    printf(">>> ");
                    scanf("%s", &S_mode);
                    
                    switch (S_mode) {
                        case 'n':
                        case 'N':
                            printf("please, tell me what the name is:\n>>> ");
                            scanf("%s", S_name);
                            S_idx = find_Building_by_name(l, S_name);
                            if (S_idx != ERROR){
                                print_Building(l, S_idx);
                            }
                            else{
                                printf("I can't find any info.\n");
                            }
                            break;
                            
                        case 'o':
                        case 'O':
                            printf("please, tell me what the coordinate is:\nx is\n>>> ");
                            scanf("%f", &x);
                            printf("y is \n>>> ");
                            scanf("%f", &y);
                            S_idx = find_Building_by_coord(l, x, y);
                            
                            if (S_idx != ERROR){
                                print_Building(l, S_idx);
                            }
                            else{
                                printf("I can't find any info.\n");
                            }
                            
                            break;
                            
                        default: printf("I think there is something wrong here.\n");
                            break;
                    }
                }
                else{
                    printf("Sorry, I don't think the map or list exsit.");
                }
                
                break;
            
            case 'd':
            case 'D':
                if (g!=NULL){
                    print_list(l);
                    printf("\nThis is the map:\n\n");
                    W_showGraph(g);
                    printf("\n");
                }
                else{
                    printf("There is no map. Please add more information for this map.\n\n");
                }
                break;
                
            case 'h':
            case 'H':
                print_help();
                break;
                
            case 's':
            case 'S':
                if (g != NULL && l != NULL){
                    // need find function for the input
                    printf("Please input name the start point:\n>>> ");
                    scanf("%s", name);
                    src = find_Building_by_name(l, name);
                    
                    printf("Please input name the destination point:\n>>> ");
                    scanf("%s", name);
                    dest = find_Building_by_name(l, name);
                    
                    if(src != ERROR && dest != ERROR){
                        int i = 0;
                        path = Dijkstra_Algorithm(g, src, dest);
                        for(i = 0; i < nV; i++ ){
                            
                            if (path[i] != NOTUSED){
                                getName(l, path[i], name);
                                printf("%s (%d)", name, path[i]);
                                if (i != nV - 1) printf(" -> ");
                            }
                            
                        }
                        printf("\n");
                    }

                }
                else{
                    printf("There is no map. Please add more information for this map.\n\n");
                }
                break;
                
            case 'q':
            case 'Q':
                printf("It is my honor to serve you, Sir.\n");
                if (g != NULL){
                    W_freeGraph(g);                                             // delete a map.
                }
                if (l != NULL){
                    deleteLandList(l);
                }
                if (path != NULL){
                    delet_path(path);
                }
                return 0;
                break;
                
            default:
                printf("Sorry, Sir. There is no mode that can match it.\n");
                print_help();
                break;
        }
    }
    
    return 0;
}

void print_help(void){
    printf("\nHere is some tips for application:\n");
    printf("a/A -- add some information of the map.\n");
    printf("d/D -- display the map.\n");
    printf("f/F -- find some information of the input landmark.\n");
    printf("h/H -- show some help instructions.\n");
    printf("s/S -- shortest path though Dijkstra Algorithm.\n");
    printf("q/Q -- quit.\n");
    printf("\n");
}
