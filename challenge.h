/* 
 * File:   challenge.h
 * Author: Babka
 *
 * Created on Utorok, 2013, november 5, 19:38
 */

#ifndef CHALLENGE_H
#define	CHALLENGE_H
char **generatorik(int);
char **fitness(int, char**);
char **natural_selection(int, char**);
char **mutation(int, char**);
char **natural_selection_time_to_die(int, char **, char**);
int input(void);


#endif	/* CHALLENGE_H */

