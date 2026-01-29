#ifndef ZHUSH_H
#define ZHUSH_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>

#define RST 	"\033[0m"

#define RED 	"\033[1;31"
#define YELLOW 	"\033[1;33"
#define BLUE 	"\033[1;34"

void zhstart(void);

int evaluate(char* line);
char** tokenize(char* line, char **argv, int *argc);
int add_word(char **parsed_line, char *buff);


#endif
