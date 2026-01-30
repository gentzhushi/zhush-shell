#ifndef ZHUSH_H
#define ZHUSH_H

// includes
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>
#include<sysexits.h>

// global consts
#define BUFSIZE 1024
#define SPACE 	"\t\n\v\f\r "

// ansi colors
#define RST 	"\033[0m"
#define RED 	"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW 	"\033[1;33m"
#define BLUE 	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN 	"\033[1;36m"
#define WHITE 	"\033[1;37m"

// funksione
void 	zhstart		(void);
int 	evaluate	(char* line);
char** 	tokenize	(char* line);
int 	add_word	(char **parsed_line, char *buff);
int 	try_builtin	(char** argv);

// structure of builtins
typedef struct builtin_s {
	char *name;
	int (*funct)(char **argv);
} builtin_t;

// builtin functs
int 	source_f	(char **argv);
int 	echo_f		(char **argv);
int 	exit_f		(char **argv);
int 	pwd_f		(char **argv);
int 	cd_f		(char **argv);

// syscall wrappers
void 	*Malloc		(size_t size);
pid_t	Fork		(void);

#endif
