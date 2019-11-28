#include <stdio.h>
/**
 * _puts - entry
 * Desc: _puts function
 * @str: char type pointer to string
 * Return: Print a string
 **/
void _puts(char *str)
{

	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

/**
 * _env - Entry
 * Desc: _env function
 * @argc: int type
 * @argv: char pointer to pointer type
 * @env: char pointer to pointer type to env
 * Return: Print the env list
 **/
int _env(int argc, char *argv[], char *env[])
{
	int counter;

	for (counter = 0; env[counter] != NULL; counter++)
	{
		_puts(env[counter]);
	}
	return (0);
}
