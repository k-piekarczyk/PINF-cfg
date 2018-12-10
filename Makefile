cfg: cfg_linked_list.o cfg_grammar_loading.o cfg_grammar_execution.o main.o
	gcc -o cfg cfg_linked_list.o cfg_grammar_loading.o cfg_grammar_execution.o main.o

cfg_linked_list.o: cfg_linked_list.c cfg_linked_list.h
	gcc -c cfg_linked_list.c

cfg_grammar_loading.o: cfg_grammar_loading.c cfg_grammar_loading.h
	gcc -c cfg_grammar_loading.c

cfg_grammar_execution.o: cfg_grammar_execution.c cfg_grammar_execution.h
	gcc -c cfg_grammar_execution.c

main.o: main.c
	gcc -c main.c