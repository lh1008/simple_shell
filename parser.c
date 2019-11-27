#include "headers.h"
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
	const char *delims = " \n\t\r";
	char *argv[32], *tok, *pad;
	char *bufback = NULL;
	int status, counter = 0, exer, j = 0;
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
	pad = _getenv(argv[0]);
	while (argv[j] != NULL)
	{
		printf("argv[%d]: %s\n", j, argv[j]);
		j++;
	}
	printf("pad: %s\n", pad);
	child = fork();
	if (child == 0)
	{
		exer = execve(pad, argv, NULL);
		if (exer == -1)
		{
			write(STDOUT_FILENO, "Not found\n", 10);
			exit(0);
		}
	}
	else
	{
		wait(&status);
	}
	free(bufback);
}
