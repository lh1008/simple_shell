B#include "headers.h"
/**
 * _strcpy - Entry to copy
 * Desc: _strcpy function
 * @dest: pointer to char type
 * @src: pointer to char type
 * Return: Return copy of src to dest
 **/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (src[i] != '\0')
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			if (src[i + 1] == '\0')
				dest[i + 1] = src[i + 1];
			i++;
		}
	}
	return (dest);
}

/**
 * parser - Parses the input into something the executor can understand
 * Desc: parser function
 * @input: Raw user input
 * @size: Size of bufer
 * Return: Nothing
 */
void parser(char *input, size_t size)
{
	const char *delims = " \n\t\r\v\f";
	char *argv[32], *tok;
	char *bufback = NULL;
	int status, counter = 0;
	pid_t child;

	bufback = malloc(size);
	_strcpy(bufback, input);

	tok = strtok(bufback, delims);
	while (tok != '\0')
	{
		argv[counter] = tok;
		tok = strtok(NULL, delims);
		counter++;
	}
	argv[counter] = NULL;

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
		parser(buf, buf_size);
		write(STDOUT_FILENO, "$ ", 2);
		gl_check = getline(&buf, &buf_size, stdin);
	}
	free(buf);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
