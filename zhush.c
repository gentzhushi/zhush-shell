#include "zhush.h"

int main(int argc, char** argv){
	
	(void)argc;
	(void)argv;
		
	zhstart();

        char user_input[BUFSIZ];

        while(1){
		// bone me load prej ~/.zhushrc
		printf(CYAN"zhush$> "RST); 
		fflush(stdout);
		
		// perdor getline() ma von, veq si ka ardh reni me ndreq.
                scanf(" %1023[^\n]", user_input);

		evaluate(user_input);
        }

        return 0;
}
