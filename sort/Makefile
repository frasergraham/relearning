
all : quick merge

merge : mergesort.c sort_helpers.c sort_helpers.h
	gcc -o merge $(GCCFLAGS) mergesort.c sort_helpers.c

quick : quicksort.c sort_helpers.c sort_helpers.h
	gcc -o quick $(GCCFLAGS) quicksort.c sort_helpers.c

debug : GCCFLAGS += -DDEBUG -g
debug : all

clean :
	rm merge quick

