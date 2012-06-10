
merge : mergesort.c
	gcc -o merge $(GCCFLAGS) mergesort.c

all : merge

debug : GCCFLAGS += -DDEBUG -g
debug : all

clean :
	rm merge

