#ifndef ARGV_H_
#define ARGV_H_
#pragma once

#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#endif // ARGV_H_

void error(int index, char *value, char *type)
{
    fprintf(stderr, "error: argument %d -> (%s) is invalid: must be an %s\n", index, value, type);
    exit(1);
}

int compare(char *value, char *s)
{
    return strcmp(value, s);
}

void check_type(char *type, char *value, int index)
{
    if (compare(type, "int") == 0) {
        for (size_t i = 0; i < strlen(value); i++) {
            if (isdigit(value[i]) == 0) {
                goto error;
            }
        }

        return;
    }

    if (compare(type, "str") == 0) {
        for (size_t i = 0; i <= strlen(value); i++) {
            if (isdigit(value[i]) != 0) {
                goto error;
            }
        }

        return;
    }

    fprintf(stderr, "error: argument %d -> (%s) to function check_type is invalid: must be either int or str\n", index, type);
    exit(1);
    
error:
    error(index, value, type);    
}

void num_args(int no, int argc)
{
    argc--;

    if (no < 1) {
        fprintf(stderr, "error: invalid usage of no_args function: no must be greater than 1: %d is invalid\n", no);
        exit(1);
    }

    if (no != argc) {
        fprintf(stderr, "error: invalid number of arguments: expected %d got %d\n", no, argc);
        exit(1);
    }
}

void args_type(char **argv, int argc, ...)
{
    va_list args;
    
    va_start(args, argc);

    for (int i = 1; i < argc; i++) {
        char *type = va_arg(args, char *);
        check_type(type, argv[i], i);
    }
    
    va_end(args);
}
