#include "headers.h"
/**
 * main - Entry point. Where the shell runs
 * Return: 0 on success, anything else on failure
 */

int main(int ac, char **av, char **env)
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
