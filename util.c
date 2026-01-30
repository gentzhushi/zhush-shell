/**
 * THIS FILE CONTAINS:
 *	- SHELL UTILITIES
 * 	- SYSTEM CALL WRAPPERS
 */

#include "zhush.h"

/*
 * SHELL UTILITIES
 */

builtin_t builtins[] = {
	{.name="source",.funct=source_f},
	{.name="echo", 	.funct=echo_f},
	{.name="exit", 	.funct=exit_f},
	{.name="pwd", 	.funct=pwd_f},
	{.name="cd", 	.funct=cd_f},
};

int evaluate(char *line){
	
	char **argv = tokenize(line);
       
	int builtin_status;
	if ((builtin_status = try_builtin(argv)) != -1) // osht builtin
		return builtin_status;

	if (Fork() == 0)
                execvp(argv[0], argv);
	else
                wait(NULL);

	free(argv);
        return EXIT_SUCCESS;
}

char** tokenize(char* line){
	size_t bufsize = BUFSIZE;
	char **tokens = Malloc(bufsize * sizeof(char*));
	
	int i = 0;
	for (char *token = strtok(line, SPACE); token; 
			token = strtok(NULL, SPACE))
	{
		tokens[i++] = token;
	}

	tokens[i] = NULL;

	return tokens;
}

int	try_builtin(char** argv){
	
	for (int i = 0; builtins[i].name != NULL; i++){
		if (strcmp(builtins[i].name, argv[0]) == 0){
			return builtins[i].funct(argv);
		}
	}

	return -1;
}

void zhstart(void){
	printf(CYAN" ________  __    __  __    __   ______   __    __ \n");
	printf("/        |/  |  /  |/  |  /  | /      \\ /  |  /  |\n");
	printf("$$$$$$$$/ $$ |  $$ |$$ |  $$ |/$$$$$$  |$$ |  $$ |\n");
	printf("    /$$/  $$ |__$$ |$$ |  $$ |$$ \\__$$/ $$ |__$$ |\n");
	printf("   /$$/   $$    $$ |$$ |  $$ |$$      \\ $$    $$ |\n");
	printf("  /$$/    $$$$$$$$ |$$ |  $$ | $$$$$$  |$$$$$$$$ |\n");
	printf(" /$$/____ $$ |  $$ |$$ \\__$$ |/  \\__$$ |$$ |  $$ |\n");
	printf("/$$      |$$ |  $$ |$$    $$/ $$    $$/ $$ |  $$ |\n");
	printf("$$$$$$$$/ $$/   $$/  $$$$$$/   $$$$$$/  $$/   $$/ \n\n\n"RST);
}

/*
 * SYSTEM CALL WRAPPERS
 */

void *Malloc(size_t size){

	if (size == 0) return NULL;

	void *memory = malloc(size);

	if (!memory){
		perror(RED"!!MALLOC FAILED!!"RST);
		exit(EXIT_FAILURE);
	}

	return memory;
}

pid_t Fork(void){
	pid_t pid = fork();

	if (pid < 0){
		perror(RED"Fork failed!\n"RST);
		exit(EX_OSERR);
	}

	return pid;
}
