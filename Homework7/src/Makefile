all: cell_tester list_tester cell_grid_tester brians_brain_cellular_automata

cell_tester: cell.o
	gcc -g -Wall -Werror cell_tester.c cell.o -o cell_tester -lm

list_tester: cell.o list.o
	gcc -g -Wall -Werror list_tester.c cell.o list.o -o list_tester

cell_grid_tester: cell_grid.o cell.o
	gcc -g -Wall -Werror cell_grid_tester.c cell_grid.o cell.o -o cell_grid_tester

brians_brain_cellular_automata: brians_brain.o cell.o cell_grid.o list.o
	gcc -g -Wall -Werror brians_brain_cellular_automata.c cell.o list.o cell_grid.o brians_brain.o -o brians_brain_cellular_automata

cell.o: cell.c
	gcc -g -Wall -Werror -c cell.c -o cell.o

list.o: list.c
	gcc -g -Wall -Werror -c list.c -o list.o

cell_grid.o: cell_grid.c
	gcc -g -Wall -Werror -c cell_grid.c -o cell_grid.o

brians_brain.o: brians_brain.c cell.o cell_grid.o list.o
	gcc -g -Wall -Werror -c brians_brain.c -o brians_brain.o

clean:
	rm -f *.o brians_brain_cellular_automata cell_grid_tester list_tester cell_tester
