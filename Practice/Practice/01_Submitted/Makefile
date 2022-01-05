CC=gcc
SOURCES=sources/trie.c sources/sort.c sources/binary_tree.c
EXE=main

all:
	@$(CC) -o $(EXE) main.c $(SOURCES) -I sources/ -lm
run:
	@./$(EXE)
debug:
	$(CC) -o $(EXE) main.c $(SOURCES) -I sources/ -lm -g
run_debug:
	valgrind ./$(EXE)
clean:
	@rm $(EXE)
