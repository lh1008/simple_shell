#include "headers.h"
/**
 * n_interactive - Shell's non interactive mode
 * @in: typedef struct
 * @env: env variable
 * Return: Nothing
 */

void n_interactive(input in, char **env)
{
	char **argv, *f_path;
	int exec_val, status;
	struct stat check;
	pid_t child;

	argv = parser(in);

	child = fork();
	if (child == 0)
	{
		if (stat(argv[0], &check) == -1)
			f_path = _getenv(argv[0], env);
		else
			f_path = argv[0];
		exec_val = execve(f_path, argv, NULL);
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
 * @env: env variable
 * Return: Nothing
 */

void interactive(input in, char **env)
{
	char **argv, *f_path;
	int exec_val, status;
	pid_t child;
	ssize_t gl_check;
	struct stat check;

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
			if (stat(argv[0], &check) == -1)
				f_path = _getenv(argv[0], env);
			else
				f_path = argv[0];
			printf("f_path: %s\n", f_path);
			exec_val = execve(f_path, argv, NULL);
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
 * Desc: main function
 * @ac: int type
 * @av: char array type
 * @env: env variable
 * Return: 0 on success, anything else on failure
 */
int main(int ac, char *av[], char **env)
{
	input in;

	in.sh_name = av[0];
	in.buffer = NULL;
	in.size = 0;
	if (isatty(STDIN_FILENO) == 0)
	{
		getline(&in.buffer, &in.size, stdin);
		n_interactive(in, env);
	}
	else
	{
		interactive(in, env);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
