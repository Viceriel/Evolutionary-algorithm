#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"challenge.h"


char **generatorik(INPUT *p){
    int i,j,c;
    char **b;
    srand(time(NULL));
    
    b=(char**)malloc(p->count*sizeof(char*));
    for(i=0; i<p->count; i++){
        b[i]=(char*)malloc((p->number+1)*sizeof(char));}
    
    for(i=0; i<p->count; i++){
        for(j=0; j<p->number; j++){
           if(j<p->number){ 
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
    
    fitness(p, b);}

char **fitness(INPUT *p, char** population){

    int i,j,a,v=0,g=0;
    char *protogoal;
    protogoal=(char*)malloc(p->number*sizeof(char));
    
    for(i=0; i<p->count; i++){
        
        for(j=0; j<p->number; j++){
            protogoal[j]=p->word[j];}
        
        for(j=0; j<p->number; j++){
            for(a=0; a<p->number; a++){
                if(population[i][j]==protogoal[a]){
                    protogoal[a]='1';
                    v++;}}}
        
        population[i][p->number]=v;
        v=0;}
    
    for(i=0; i<p->count; i++){
        g=0;
        for(j=0; j<p->number; j++){
            if(population[i][j]==p->word[j]){
                g++;}}
                if(g<p->number)
                {
                population[i][p->number]+=g*3;
                }
                else
                {
                population[i][p->number]+=100;
                break;
                }
    }
    
    return population;}


char **natural_selection(INPUT *p, char** parents){
    srand(time(NULL));
    char **childrens;
    int i=0,j,choose=0,mother,father,s;
    
    childrens=(char**)malloc(p->count*sizeof(char*));
    for(j=0; j<p->count; j++){
        childrens[j]=(char*)malloc((p->number+1)*sizeof(char));}
   
   for(j=0; j<p->count; j++){
    
     while(1){
        s=(rand()%p->count);
        choose=(rand()%10)+1;
        if(parents[s][p->number]>=choose){
            mother=s;
            break;}}
    
     while(1){
        s=(rand()%p->count);
        choose=(rand()%10)+1;
        if(parents[s][p->number]>=choose && s!=mother){
            father=s;
            break;}}
    
     for(i=0; i<p->number; i++)
     {
         if(i%2==0)
         {
             childrens[j][i]=parents[mother][i];
         }
         else
         {
             childrens[j][i]=parents[father][i];
         }
     }
    childrens[j][p->number]=0;}
    
    mutation(p, childrens);}

char **mutation(INPUT *p, char **childrens){
    int i,j,m1,m2;
    srand(time(NULL));
    for(i=0; i<p->count; i++){
        m1=(rand()%p->number);
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
    
    fitness(p, childrens);}

char **natural_selection_time_to_die(INPUT *p, char **origins, char **newcomers){
    char **new_population;
    int i,choose,s,d,j;
    srand(time(NULL));
    
    new_population=(char**)malloc(p->count*sizeof(char*));
    for(i=0; i<p->count; i++){
        new_population[i]=(char*)malloc((p->number+1)*sizeof(char));}

    for(i=0; i<p->count; i++){
        
        while(1){
            choose=(rand()%15)+1;
            d=(rand()%p->count);
            s=(rand()%p->count);
            if(origins[s][p->number]>=choose || newcomers[d][p->number]>=choose){
                
                if(origins[s][p->number]>newcomers[d][p->number]){
                    for(j=0; j<=p->number; j++){
                        new_population[i][j]=origins[s][j];}
                    break;}
                
                else if(origins[s][p->number]==newcomers[d][p->number]){
                     for(j=0; j<=p->number; j++){
                        new_population[i][j]=origins[s][j];}
                     break;}
             
                else{
                    for(j=0; j<=p->number; j++){
                        new_population[i][j]=newcomers[d][j];}
                    break;}
                }}}
    
    return new_population;}



INPUT *input(void)
{
    char *word;
    int i=0,n;
    INPUT *p;
    p=(INPUT*)malloc(sizeof(INPUT));
    
    printf("Zadaj pocet jedincov:\n");
    scanf("%d", &n);
    getchar();
    if((n<10) && (n>100))
    {
        system("cls");
        printf("Nevhodny parameter, opakuj");
        getchar();
        exit (EXIT_FAILURE); 
    }
    p->count=n;
    
    word=(char*)malloc(23*sizeof(char));
    printf("Zadaj slovo: \n");
    while(1)
    {
       scanf("%c", &word[i]);
       if(word[i]=='\n')
       {
           break;
       }
       if(i>22)
       {
         exit (EXIT_FAILURE);  
       }
       i++;
    }
    printf("\n");
    p->number=i;
    p->word=word;
    return p;
 }


