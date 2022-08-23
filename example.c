#include <stdio.h>
#include <stdlib.h>

#include "argv.h"

int main(int argc, char **argv)
{
    assert(argv != NULL);
    num_args(2, argc);
    args_type(argv, argc, "int", "str");

    printf("Compiled Successfully\n");

    return 0;
}
