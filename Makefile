cc=gcc
flags= -Wall -Wextra

argv: main.c
	$(cc) main.c -o argv $(flags)
