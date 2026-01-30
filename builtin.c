/*
 * BUILT IN FUNCTIONS
 * asd
 */

#include "zhush.h"

int source_f(char** argv){
	// source, doren n'zemër qikjo ka me kan sa me lexu promptin se i ain't
	// doing all that

	(void)argv;
	printf(RED"source_f is not yet implemented.\n"RST);
	return 0;
}

int echo_f(char** argv){

	printf(GREEN"BUILT IN ECHO\n"RST);

	for(int i = 0; argv[i] != NULL; i++)
		printf("%s ", argv[i]);
	printf("\n");

	return 0;
}

int exit_f(char** argv){
	(void)argv;
	printf(GREEN"BUILT IN EXIT\n"RST);
	exit(0);
}

int pwd_f(char** argv){
	// get cwd syscall, edhe printo

	(void)argv;
	printf(RED"pwd_f is not yet implemented.\n"RST);

	return 0;
}

int cd_f(char** argv){
	// chdir syscall qitu, edhe printo ... 
	
	(void)argv;
	printf(RED"cd_f is not yet implemented.\n"RST);

	return 0;
}
