connectn.out: Connect_N.o ConnectSupport.o
	gcc -g -Wall -Werror -o connectn.out Connect_N.o ConnectSupport.o

Connect_N.o: Connect_N.c ConnectSupport.h
	gcc -g -Wall -Werror -c -o Connect_N.o Connect_N.c

ConnectSupport.o: ConnectSupport.c ConnectSupport.h
	gcc -g -Wall -Werror -c -o ConnectSupport.o ConnectSupport.c

clean:
	rm -f *.o *.out
