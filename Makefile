flags := -Wall -Wextra -Wpedantic -I include -std=c17
object := zhush

compile:
	cc $(flags) zhush.c -o $(object)

clean: rm -f $(object)
