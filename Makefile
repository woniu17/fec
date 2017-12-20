#CFLAGS=-Wall -Wextra -Werror  -I. -g -O0 -std=c99
CFLAGS=-I. -g -O0 -std=c99

test: test.o fec.o rs.o
	$(CC) $(CFLAGS) -o $@ test.o fec.o rs.o

test.o: test.c
	$(CC) -c $(CFLAGS) -o test.o test.c

fec.o: fec.c fec.h
	$(CC) -c $(CFLAGS) -o fec.o fec.c

rs.o: rs.c rs.h
	$(CC) -c $(CFLAGS) -o rs.o rs.c

clean:
	rm -f *.o
	rm -f test

PHONY: run
