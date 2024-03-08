CC=gcc
CFLAGS=-W -Wall -ansi -std=c99
LDFLAGS=
EXEC=pedaling_speed
SRC="../src"

all: $(EXEC)

pedaling_speed: pedaling_mgt.o time_mgt.o main.o
	$(CC) -o pedaling_speed time_mgt.o pedaling_mgt.o main.o $(LDFLAGS)

pedaling_mgt.o: pedaling_mgt.c
	$(CC) -o pedaling_mgt.o -c pedaling_mgt.c $(CFLAGS)

time_mgt.o: time_mgt.c
	$(CC) -o time_mgt.o -c time_mgt.c $(CFLAGS)

main.o: main.c time_mgt.h pedaling_mgt.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)