#include "zhush.h"

int main(int argc, char** argv){
	
	(void)argc;
	(void)argv;

	zhstart();

        char user_input[BUFSIZ];

        while(1){
		printf(CYAN"zhush$> "RST);
		fflush(stdout);
		// readline
                scanf(" %255[^\n]", user_input);
                printf("Duke evaluu: %s\n\n", user_input);
		evaluate(user_input);
        }

        return 0;
}

int evaluate(char *line){
        pid_t child_pid = fork();

        if (child_pid == 0){
                printf("---CHILD-PROCESS---\n");
		printf("PID:%d,\t CHILD_PID:%d\n\n", getpid(), child_pid);
        	
		char **argv = tokenize(line);
		
		//printoj args-at
		printf("Tu provu me ekzekutu: { ");
		for(int i = 0; argv[i] != NULL; i++){
			printf("%s, ", argv[i]);
		}
		printf("}\n\n");

                execvp(argv[0], argv);

                _exit(0); // qikjo s'ka mu ekzekutu kurr
        }
        else {
                int child_status;
                waitpid(child_pid, &child_status, 0);
                printf("\n\n---PARENT-PROCESS---\n");
		printf("PID:%d,\t CHILD_PID:%d\t CHILD_STATUS: %d\n\n", 
				getpid(), child_pid, child_status);
        }

        return 0;
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

void *Malloc(size_t size){

	if (size == 0) return NULL;

	void *memory = malloc(size);

	if (!memory){
		perror(RED"!!MALLOC FAILED!!"RST);
		exit(EXIT_FAILURE);
	}

	return memory;
}
