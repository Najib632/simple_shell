#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

size_t _strlen(char *str);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _fgetc(FILE *stream);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *s, int c);

#endif /*_SIMPLE_SHELL_*/
