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
    int i,j,n,g=1;
    char **c;
    char **b;
    
    n=input();
    b=generatorik(n);
    FILE *fw;
    fw=fopen("data.txt", "w");
    
    printf( "\n 0. generation");
        for(i=0; i<n; i++){
            printf("\n");
            for(j=0; j<5; j++){
                printf("%c", b[i][j]);}}
    
    while(1){
        
        for(i=0; i<n; i++){
            if(b[i][4]>40){
                printf("done");
                getchar();
                return (EXIT_SUCCESS);}}
        
        c=natural_selection(n,b);
        b=natural_selection_time_to_die(n,b,c);
        
        fprintf(fw, "\n %d. generation",g);
        for(i=0; i<n; i++){
            fprintf(fw, "\n");
            for(j=0; j<5; j++){
                fprintf(fw,"%c", b[i][j]);}}
    g++;}
    getchar();
    getchar();
    return (EXIT_SUCCESS);
}

