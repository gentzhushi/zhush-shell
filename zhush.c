#include "zhush.h"

int main(int argc, char** argv){
	
	(void)argc;
	(void)argv;

	zhstart();

        char user_input[BUFSIZ];

        while(1){
		printf("zhush$>");
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
                printf(YELLOW"---CHILD-PROCESS---\n");
		printf("PID:%d,\t CHILD_PID:%d\n\n", getpid(), child_pid);
                printf("Arguments: %s\n", line);
        	
                //char **args = {"ls", "-lha", "--color=always", NULL};
		char **argv;
		int argc;

		tokenize(line, argv, &argc);
		printf("Tu provu me ekzekutu [ls -lha]\n");
                execvp(argv[0], argv);

                _exit(0); // qikjo s'ka mu ekzekutu kurr
        }
        else {
                int child_status;
                waitpid(child_pid, &child_status, 0);
                printf(BLUE"---PARENT-PROCESS---\n");
		printf("PID:%d,\t CHILD_PID:%d"RST"\n\n", getpid(), child_pid);
        }

        return 0;
}

char** tokenize(char* line, char **argv, int *argc){
        
        int line_length;
        for (line_length = 0; line[line_length] != '\0'; line_length++);
        
        char** parsed_line = NULL;
        for (int i = 0, buff_ptr = 0; i < line_length; i++, buff_ptr++){

                char buff[BUFSIZ];
                bool q_flag = false;
                
                if ((line[i] == ' ' && !q_flag) || (line[i] == '\"' && q_flag)){
                        //add_word(parsed_line, buff);
                        buff_ptr = 0;
                } 

                if (line[i] == '\"'){
                        q_flag = !q_flag;
                }

                buff[buff_ptr] = line[i];
        }

        return parsed_line;
}

void zhstart(void){
	printf(" ________  __    __  __    __   ______   __    __ \n");
	printf("/        |/  |  /  |/  |  /  | /      \\ /  |  /  |\n");
	printf("$$$$$$$$/ $$ |  $$ |$$ |  $$ |/$$$$$$  |$$ |  $$ |\n");
	printf("    /$$/  $$ |__$$ |$$ |  $$ |$$ \\__$$/ $$ |__$$ |\n");
	printf("   /$$/   $$    $$ |$$ |  $$ |$$      \\ $$    $$ |\n");
	printf("  /$$/    $$$$$$$$ |$$ |  $$ | $$$$$$  |$$$$$$$$ |\n");
	printf(" /$$/____ $$ |  $$ |$$ \\__$$ |/  \\__$$ |$$ |  $$ |\n");
	printf("/$$      |$$ |  $$ |$$    $$/ $$    $$/ $$ |  $$ |\n");
	printf("$$$$$$$$/ $$/   $$/  $$$$$$/   $$$$$$/  $$/   $$/ \n\n\n");
}
