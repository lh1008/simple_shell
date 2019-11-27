#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

/* Headers used by the shell program */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Structures used by the shell program */
/**
 * struct u_input - Contains information regarding the input to the shell
 * @sh_name: Name of the shell. Used for executor's error handling
 * @buffer: Buffer containing the input
 * @size: Size of the buffer
 *
 * Description: u_input contains important data regarding the input
 * given to the shell. The sh_name varies according to how the program is
 * compiled.
 */
typedef struct u_input
{
	char *sh_name;
	char *buffer;
	size_t size;
} input;

/* Functions used by the shell program */
char **parser(input in);
char *_strcpy(char *dest, char *src);
void n_interactve(input in);
void interactive(input in);
size_t tok_count(input in, const char *delims);
#endif
