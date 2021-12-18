CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_EX3=ex3.o
FLAGS= -Wall -g

all: stringProg libex3.a
stringProg: $(OBJECTS_MAIN) libex3.a
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) libex3.a
libex3.a: $(OBJECTS_EX3)
	$(AR) -rcs libex3.a $(OBJECTS_EX3)
ex3.o: ex3.c ex3.h
	$(CC) $(FLAGS) -c ex3.c
main.o: main.c ex3.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg
