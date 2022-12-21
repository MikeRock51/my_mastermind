all: my_mastermind

my_mastermind: *.o *.h
	gcc -Wall -Werror -Wextra *.o -o my_mastermind

*.o: *.c
	gcc -c -Wall -Werror -Wextra *.c

clean:
	rm -f *.o

fclean: clean
	rm -f my_mastermind *.o

re fclean: all