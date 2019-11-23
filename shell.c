#include "headers.h"

/**
 * parser - Parses the input into something the executor can understand
 * @input: Raw user input
 * Return: Nothing
 */

void parser(char *input)
{
	const char *delims = " \n\t\r\v\f";
	char *argv[2] = {NULL, NULL};
	int status;
	pid_t child;

	argv[0] = strtok(input, delims);
	child = fork();
	if (child == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			write(STDOUT_FILENO, "Not found\n", 10);
			exit(0);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * main - Entry point. Where the shell runs
 * Return: 0 on success, anything else on failure
 */

int main(void)
{
	ssize_t wr_check, gl_check;
	char *buf = NULL;
	size_t buf_size = 0;

	wr_check = write(STDOUT_FILENO, "$ ", 2);
	if (wr_check == -1)
	{
		write(STDOUT_FILENO, "Error\n", 6);
		exit(1);
	}
	gl_check = getline(&buf, &buf_size, stdin);
	while (gl_check != -1)
	{
		parser(buf);
		write(STDOUT_FILENO, "$ ", 2);
		gl_check = getline(&buf, &buf_size, stdin);
	}
	free(buf);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
