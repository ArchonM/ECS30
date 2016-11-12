tic_tac_toe.out: main.o board.o win.o
	gcc -g -Wall -Werror -o tic_tac_toe.out main.o board.o
	
board.o: board.c board.h
	gcc -g -Wall -Werror -c -o board.o board.c
	
main.o: main.c board.h win.h
	gcc -g -Wall -Werror -c -o main.o main.c
	
win.o: win.c win.h 
	gcc -g -Wall -Werror -c -o win.o win.c
	
clean:
	rm -f *.o *.out
