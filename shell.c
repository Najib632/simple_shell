#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - entry point
 * 
 * Return: Always 0 (SUCCESS)
 **/
int main(void)
{
	pid_t child_pid;
	char *line = NULL;
	size_t len = 0;
	int nread = 0;
	char *argv[] = {"/bin/ls", NULL};

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}
		nread = _getline(&line, &len, stdin);
		if (nread == EOF)
			break;
		child_pid = fork();
		if (child_pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			line[_strcspn(line, "\n")] = '\0';
			if (execve(line, argv, environ) < 0)
			{
				free(line);
				exit(EXIT_FAILURE);
			}
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);
	return (0);
}
