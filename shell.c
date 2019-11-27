#include "headers.h"
/**
 * n_interactive - Shell's non interactive mode
 * @shell: Name of the shell
 * @input: User input
 * Return: Nothing
 */

void n_interactive(input in)
{
	char **argv;
	int exec_val, status;
	pid_t child;

	argv = parser(in);

	child = fork();
	if (child == 0)
	{
		exec_val = execve(argv[0], argv, NULL);
		if (exec_val == -1)
		{
			perror(in.sh_name);
			_exit(127);
		}
	}
	else
		wait(&status);
	free(argv);
	free(in.buffer);
}

/**
 * interactive - Shell's interactive mode
 * @in: Name of the shell
 * Return: Nothing
 */

void interactive(input in)
{
	char **argv;
	int exec_val, status;
	pid_t child;
	ssize_t gl_check;

	if (write(STDOUT_FILENO, "$ ", 2) == -1)
	{
		perror(in.sh_name);
		exit(98);
	}
	gl_check = getline(&in.buffer, &in.size, stdin);
	while (gl_check != -1)
	{
		argv = parser(in);
		child = fork();
		if (child == 0)
		{
			exec_val = execve(argv[0], argv, NULL);
			if (exec_val == -1)
			{
				perror(in.sh_name);
			        _exit(127);
			}
		}
		else
			wait(&status);
		write(STDOUT_FILENO, "$ ", 2);
		gl_check = getline(&(in.buffer), &(in.size), stdin);
	}
	free(argv);
	free(in.buffer);
}

/**
 * main - Entry point. Where the shell runs
 * Return: 0 on success, anything else on failure
 */
int main(int ac, char *av[])
{
	input in;

	in.sh_name = av[0];
	in.buffer = NULL;
	in.size = 0;
	if (isatty(STDIN_FILENO) == 0)
	{
		getline(&in.buffer, &in.size, stdin);
		n_interactive(in);
	}
	else
	{
		interactive(in);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
