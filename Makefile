flags := -Wall -Wextra -Wpedantic -I include -std=c17

sources := zhush.c builtin.c util.c

executable := zhush

compile:
	cc $(flags) $(sources) -o $(executable)

clean: 
	rm -f $(object)
