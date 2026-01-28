#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>

#define BUFF_SIZE 256

int evaluate(char* line);
char** parse_line(char* line);
int add_word(char **parsed_line, char *buff);

int main(int argc, char** argv){
      
        printf("Shell started.\n\n");

        char user_input[BUFF_SIZE];

        while(1){
                scanf(" %255[^\n]", user_input);
                printf("Duke evaluu: %s\n\n", user_input);
                evaluate(user_input);
        }

        return 0;
}

int evaluate(char *line){
        pid_t child_pid = fork();

        if (child_pid == 0){
                printf("---CHILD-PROCESS---\nPID:%d,\t CHILD_PID:%d\n\n", getpid(), child_pid);
                printf("Arguments: %s\n", line);
                
                char *args[] = {"ls", "-lha", "--color=always", NULL};
		printf("Tu provu me ekzekutu [ls -lha]\n");
                execvp(args[0], args);

                _exit(0); // qikjo s'ka mu ekzekutu kurr
        }
        else {
                int child_status;
                waitpid(child_pid, &child_status, 0);
                printf("---PARENT-PROCESS---\nPID:%d,\t CHILD_PID:%d\n\n", getpid(), child_pid);
        }

        return 0;
}

char** parse_line(char* line){
        
        int line_length;
        for (line_length = 0; line[line_length] != '\0'; line_length++);
        
        char** parsed_line;
        for (int i = 0, buff_ptr = 0; i < line_length; i++, buff_ptr++){

                char buff[BUFF_SIZE];
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
