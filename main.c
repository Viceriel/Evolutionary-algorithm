/* 
 * File:   main.c
 * Author: Babka
 *
 * Created on Utorok, 2013, november 5, 19:32
 */
    
#include <stdio.h>
#include <stdlib.h>
#include"challenge.h"

/*
 * 
 */
int main() {
    int i,j,g=1;
    char **c;
    char **b;
    INPUT *p;
    
    p=input();
    b=generatorik(p);
    getchar();
    FILE *fw;
    fw=fopen("data.txt", "w");
    
    printf( "\n 0. generation");
        for(i=0; i<p->count; i++){
            printf("\n");
            for(j=0; j<=p->number; j++){
                printf("%c", b[i][j]);}}
    while(1){
        
        for(i=0; i<p->count; i++){
            if(b[i][p->number]>100){
                printf("done");
                getchar();
                return (EXIT_SUCCESS);}}
        
        c=natural_selection(p,b);
        b=natural_selection_time_to_die(p,b,c);
        
        fprintf(fw, "\n %d. generation",g);
        for(i=0; i<p->count; i++){
            fprintf(fw, "\n");
            for(j=0; j<=p->number; j++){
                fprintf(fw, "%c", b[i][j]);}}
    g++;}
    getchar();
    getchar();
    return (EXIT_SUCCESS);

}

