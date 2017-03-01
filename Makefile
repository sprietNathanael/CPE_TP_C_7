CC=gcc
CFLAGS=-W -Wall -g -Wextra
EXEC=hanoi binaryTree
LDFLAGS=

all: $(EXEC)

hanoi: main_hanoi.o log.o hanoi.o
	$(CC) -o hanoi main_hanoi.o log.o hanoi.o $(LDFLAGS)

main_hanoi.o: main_hanoi.c log.h hanoi.h
	$(CC) -o main_hanoi.o -c main_hanoi.c $(LDFLAGS) $(CFLAGS)

hanoi.o: hanoi.c log.h
	$(CC) -o hanoi.o -c hanoi.c $(LDFLAGS) $(CFLAGS)

binaryTree: main_binary.o log.o binaryTree.o file.o
		$(CC) -o binaryTree main_binary.o log.o binaryTree.o file.o $(LDFLAGS)

main_binary.o: main_binary.c log.h binaryTree.h
	$(CC) -o main_binary.o -c main_binary.c $(LDFLAGS) $(CFLAGS)

binaryTree.o: binaryTree.c log.h file.h
	$(CC) -o binaryTree.o -c binaryTree.c $(LDFLAGS) $(CFLAGS)

file.o: file.c log.h
	$(CC) -o file.o -c file.c $(LDFLAGS) $(CFLAGS)

log.o: log.c
	$(CC) -o log.o -c log.c $(LDFLAGS) $(CFLAGS)

mrproper: clean
	rm -rf $(EXEC)

clean:
	rm -rf *.o *.h.gch
