#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	char *argv[] = { NULL };
	pid_t child_pid;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		nread = _getline(&line, &len, stdin);
		fflush(stdin);
		if (nread == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		child_pid = fork();
		if (child_pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(line, argv, environ) < 0)
			{
				perror("./shell");
			}
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
