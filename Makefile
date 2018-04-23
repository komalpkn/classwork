# Generic makefile

func_ptr: func_ptr.c
	gcc -Wall -Wextra -Wpedantic -ggdb -std=c99 -o func_ptr func_ptr.c
clean:
	rm func_ptr
