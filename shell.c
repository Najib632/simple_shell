#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
	pid_t child_pid;
	char *line = NULL;
	size_t len = 0;
	int nread = 0;
	char *argv[2];

	argv[0] = NULL, argv[1] = NULL;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		fflush(stdout);
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
				perror("./shell");
				exit(EXIT_FAILURE);
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
