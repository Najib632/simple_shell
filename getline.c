#include "simple_shell.h"

/**
 * _strlen - my own strlen function
 * @str: buffer
 *
 * Return: char length
 **/
size_t _strlen(char *str)
{
	size_t i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * _getline - my own getline function
 * @lineptr: stores the address of the pointer to write to
 * @n: number of chars to write
 * @stream: I/O channel to write to
 *
 * Return: >= 0 (SUCCESS), < 0 (FAIL)
 **/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t read_chars;
	size_t len = 0;
	char *tempbuffer;
	int c;

	if (lineptr == NULL || n == NULL)
		return (-1);
	*lineptr = NULL, *n = 0;
	while ((c = _fgetc(stream)) != '\n')
	{
		if (*n >= len)
		{
			len += 128;
			tempbuffer = realloc(*lineptr, len);
			if (tempbuffer == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = tempbuffer;
		}
		if (c == EOF)
		{
			(*lineptr)[*n] = '\0';
			return (*n);
		}
		(*lineptr)[(*n)++] = c;
	}
	if (*n > 0)
		(*lineptr)[*n] = '\0';
	else
		return (-1);
	read_chars = *n;
	return (read_chars);
}
