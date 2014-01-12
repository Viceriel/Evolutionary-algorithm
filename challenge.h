/* 
 * File:   challenge.h
 * Author: Babka
 *
 * Created on Utorok, 2013, november 5, 19:38
 */

#ifndef CHALLENGE_H
#define	CHALLENGE_H
typedef struct
{   
    int count;
    int number;
    char *word;
}INPUT;
INPUT *input(void);
char **generatorik(INPUT*);
char **fitness(INPUT*, char**);
char **natural_selection(INPUT*, char**);
char **mutation(INPUT*, char**);
char **natural_selection_time_to_die(INPUT*, char **, char**);


#endif	/* CHALLENGE_H */

