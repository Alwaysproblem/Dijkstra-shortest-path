#include <stdio.h>
#include "WGgraph.h"
#include "Dijkstra.h"
#include "LandList.h"



void print_help(void);

int main(){
    
    char mode = '\0';                                                          // the mode of application.
    int nV = 0;                                                                // the number of landmarks.
    int src = 0;                                                               // the index of source point.
    int dest = 3;                                                              // the index of destination point.
    
    printf("Hello, Sir, I am always at your service.\n");
    print_help();
    while (True) {
        WGraph g = NULL;
        landList l = NULL;
        
        printf("please select a mode for this application:\n>>> ");
        scanf("%s", &mode);
        
        
        switch (mode) {
            case 'a':
            case 'A':

                printf("please input the number of landmarks: ");
                scanf("%d", &nV);
                g = W_newGraph(nV);                                              // a new map.
                
                break;
                
            case 'f':
            case 'F':
//                l = newLandList(10);
//                print_Building(l, 0);
//                print_list(l);
//                deleteLandList(l);
                break;
            
            case 'd':
            case 'D':
                if (g!=NULL){
                    printf("This is the map:\n\n");
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
                if (g!=NULL){
                    // need find function for the input
                    Dijkstra_Algorithm(g, src, dest);
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
//    printf("c/C -- clear command window screen.\n");                         // need to code this part when other parts have already completed.
    printf("d/D -- display the map.\n");
    printf("f/F -- find some information of the input landmark.\n");
    printf("h/H -- show some help instructions.\n");
    printf("s/S -- shortest path though Dijkstra Algorithm.\n");
    printf("q/Q -- quit.\n");
    printf("\n");
}
