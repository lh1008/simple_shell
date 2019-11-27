#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

/* Headers used by the shell program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Functions used by the shell program */
void parser(char *input, size_t size);
char *_strcpy(char *dest, char *src);
char *_getenv(char *argv);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(const char *s);

#endif
