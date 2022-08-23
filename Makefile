cc=gcc
flags= -Wall -Wextra

argv: example.c
	$(cc) example.c -o argv $(flags)
