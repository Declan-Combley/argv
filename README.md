# Argv Header

A simple way to ensure that your command line arguments are what you expect.



# Quickstart

```c
#include <stdio.h>
#include "argv.h"

int main(int argc, char **argv)
{
    num_args(2, argc);
    args_type(argv, argc, "int", "str");

    printf("Compiled Successfully\n");
}


```



# Functions

This header has two functions (they're void so it should be fine convention wise) which are fairly simple.

```c
void num_args(int no, int argc)
void args_type(char **argv, int argc, ...)
```

Just note that the first argument of args_type is argv and not argc, this is because the va_start function expects the final argument to be length.
