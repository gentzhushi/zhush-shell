#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int evaluate(char* line);

int main(int argc, char** argv){
      
        printf("Shell started.\n\n");

        char user_input[256];

        while(1){
                scanf(" %255[^\n]", user_input);
                printf("Duke evaluu: %s\n\n", user_input);
                evaluate(user_input);
        }

        return 0;
}

int evaluate(char *line){
        pid_t pid = fork();

        if (pid == 0){
                printf("- Hej babi\n");
                _exit(0);
        }
        else{
                waitpid(pid, 0, 0);
                printf("+ Hë bre djali jem?! A s'pe sheh qe jom nxan tu lu kumor?!?!? AAAA?!!?!?\n");
        }

        return 0;
}
