# Generic makefile

nodes_add_to_first: nodes_add_to_first.c
	gcc -Wall -Wextra -Wpedantic -ggdb -std=c99 -o nodes_add_to_first nodes_add_to_first.c
clean:
	rm nodes_add_to_first
