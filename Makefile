CC=gcc
CFLAGS=-W -Wall -g -Wextra
EXEC=hanoi
LDFLAGS=

all: $(EXEC)

hanoi: main_hanoi.o log.o hanoi.o
	$(CC) -o hanoi main_hanoi.o log.o $(LDFLAGS)

main_hanoi.o: main_hanoi.c log.h hanoi.h
	$(CC) -o main_hanoi.o -c main_hanoi.c $(LDFLAGS) $(CFLAGS)

hanoi.o: hanoi.c log.h
	$(CC) -o hanoi.o -c hanoi.c $(LDFLAGS) $(CFLAGS)

log.o: log.c
	$(CC) -o log.o -c log.c $(LDFLAGS) $(CFLAGS)

mrproper: clean
	rm -rf $(EXEC)

clean:
	rm -rf *.o *.h.gch
