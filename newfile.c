#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"challenge.h"


char **generatorik(int n){
    int i,j,c;
    char **b;
    srand(time(NULL));
    
    b=(char**)malloc(n*sizeof(char*));
    for(i=0; i<n; i++){
        b[i]=(char*)malloc(5*sizeof(char));}
    
    for(i=0; i<n; i++){
        for(j=0; j<5; j++){
           if(j<4){ 
            c=(rand()%26)+1;
            switch(c){
                case 1: b[i][j]='a';
                break;
                
                case 2: b[i][j]='b';
                break;
                
                case 3: b[i][j]='c';
                break;
                
                case 4: b[i][j]='d';
                break;
                
                case 5: b[i][j]='e';
                break;
                
                case 6: b[i][j]='f';
                break;
                
                case 7: b[i][j]='g';
                break;
                
                case 8: b[i][j]='h';
                break;
                
                case 9: b[i][j]='i';
                break;
                
                case 10: b[i][j]='j';
                break;
                
                case 11: b[i][j]='k';
                break;
                
                case 12: b[i][j]='l';
                break;
                
                case 13: b[i][j]='m';
                break;
                
                case 14: b[i][j]='n';
                break;
                
                case 15: b[i][j]='o';
                break;
                
                case 16: b[i][j]='p';
                break;
                
                case 17: b[i][j]='q';
                break;
                
                case 18: b[i][j]='r';
                break;
                
                case 19: b[i][j]='s';
                break;
                
                case 20: b[i][j]='t';
                break;
                
                case 21: b[i][j]='u';
                break;
                
                case 22: b[i][j]='v';
                break;
                
                case 23: b[i][j]='w';
                break;
                
                case 24: b[i][j]='x';
                break;
                
                case 25: b[i][j]='y';
                break;
                
                case 26: b[i][j]='z';
                break;}}
           else b[i][j]=0;}}
    
    fitness(n, b);}

char **fitness(int n, char** population){
    int i,j,a,v=0,g=0;
    char goal[]="pero";
    char protogoal[4];
    
    for(i=0; i<n; i++){
        
        for(j=0; j<4; j++){
            protogoal[j]=goal[j];}
        
        for(j=0; j<4; j++){
            for(a=0; a<4; a++){
                if(population[i][j]==protogoal[a]){
                    protogoal[a]='1';
                    v++;}}}
        
        population[i][4]=v;
        v=0;}
    
    for(i=0; i<n; i++){
        for(j=0; j<4; j++){
            if(population[i][j]==goal[j]){
                g++;}}
        switch(g){
            case 1: population[i][4]+=15;
                    g=0;
                    break;
            case 2: population[i][4]+=25;
                    g=0;
                    break;
            case 3: population[i][4]+=35;
                    g=0;
                    break;
            case 4: population[i][4]+=45;
                    g=0;
                    break;
            default: break;}}
    
    return population;}

char **natural_selection(int n, char** parents){
    srand(time(NULL));
    char **childrens;
    int i=0,j,choose=0,mother,father,s;
    
    childrens=(char**)malloc(n*sizeof(char*));
    for(j=0; j<n; j++){
        childrens[j]=(char*)malloc(5*sizeof(char));}
   
   for(j=0; j<n; j++){
    
    while(1){
        s=(rand()%n);
        choose=(rand()%10)+1;
        if(parents[s][4]>=choose){
            mother=s;
            break;}}
    
    while(1){
        s=(rand()%n);
        choose=(rand()%10)+1;
        if(parents[s][4]>=choose && s!=mother){
            father=s;
            choose=100;
            break;}}
    
    childrens[j][0]=parents[mother][0];
    childrens[j][1]=parents[mother][1];
    childrens[j][2]=parents[father][2];
    childrens[j][3]=parents[father][3];
    childrens[j][4]=0;}
    
    mutation(n, childrens);}

char **mutation(int n, char **childrens){
    int i,j,m1,m2;
    srand(time(NULL));
    for(i=0; i<n; i++){
        m1=(rand()%4);
        m2=(rand()%26)+1;
        
        switch(m2){
                case 1: childrens[i][m1]='a';
                break;
                
                case 2: childrens[i][m1]='b';
                break;
                
                case 3: childrens[i][m1]='c';
                break;
                
                case 4: childrens[i][m1]='d';
                break;
                
                case 5: childrens[i][m1]='e';
                break;
                
                case 6: childrens[i][m1]='f';
                break;
                
                case 7: childrens[i][m1]='g';
                break;
                
                case 8: childrens[i][m1]='h';
                break;
                
                case 9: childrens[i][m1]='i';
                break;
                
                case 10: childrens[i][m1]='j';
                break;
                
                case 11: childrens[i][m1]='k';
                break;
                
                case 12: childrens[i][m1]='l';
                break;
                
                case 13: childrens[i][m1]='m';
                break;
                
                case 14: childrens[i][m1]='n';
                break;
                
                case 15: childrens[i][m1]='o';
                break;
                
                case 16: childrens[i][m1]='p';
                break;
                
                case 17: childrens[i][m1]='q';
                break;
                
                case 18: childrens[i][m1]='r';
                break;
                
                case 19: childrens[i][m1]='s';
                break;
                
                case 20: childrens[i][m1]='t';
                break;
                
                case 21: childrens[i][m1]='u';
                break;
                
                case 22: childrens[i][m1]='v';
                break;
                
                case 23: childrens[i][m1]='w';
                break;
                
                case 24: childrens[i][m1]='x';
                break;
                
                case 25: childrens[i][m1]='y';
                break;
                
                case 26: childrens[i][m1]='z';
                break;}}
    
    fitness(n, childrens);}

char **natural_selection_time_to_die(int n, char **origins, char **newcomers){
    char **new_population;
    int i,choose,s,d,j;
    srand(time(NULL));
    
    new_population=(char**)malloc(n*sizeof(char*));
    for(i=0; i<n; i++){
        new_population[i]=(char*)malloc(5*sizeof(char));}

    for(i=0; i<n; i++){
        
        while(1){
            choose=(rand()%15)+1;
            d=(rand()%n);
            s=(rand()%n);
            if(origins[s][4]>=choose || newcomers[d][4]>=choose){
                
                if(origins[s][4]>newcomers[d][4]){
                    for(j=0; j<5; j++){
                        new_population[i][j]=origins[s][j];}
                    break;}
                
                else if(origins[s][4]==newcomers[d][4]){
                     for(j=0; j<5; j++){
                        new_population[i][j]=origins[s][j];}
                     break;}
             
                else{
                    for(j=0; j<5; j++){
                        new_population[i][j]=newcomers[d][j];}
                    break;}
                }}}
    
    return new_population;}

int input(void){
    int n;
    
    printf("Zadaj pocet jedincov:\n");
    scanf("%d", &n);
    getchar();
    if((n<10) || (n>100)){
        system("cls");
        printf("Nevhodny parameter, opakuj");
        getchar();
        system("cls");
        n=input();}
    
    return n;}


