#include "headers.h"
/**
 * main - Entry point. Where the shell runs
 * Return: 0 on success, anything else on failure
 */

int main(void)
{
	char *argv[] = {NULL, NULL};
	ssize_t gl_check, wr_check;
	char *buf = NULL;
	size_t buf_size = 0;

	wr_check = write(STDOUT_FILENO, "$ ", 2);
	if (wr_check == -1)
	{
		write(STDOUT_FILENO, "Error\n", 6);
		exit(1);
	}

	while (getline(&buf, &buf_size, stdin) != -1)
	{
		printf("I've read: %s", buf);
		write(STDOUT_FILENO, "$ ", 2);
	}
	free(buf);
	write(STDOUT_FILENO, "Bye\n", 4);
	return (0);
}
