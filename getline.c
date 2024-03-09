#include "simple_shell.h"

/**
 * _fileno - returns the integer file descriptor used to implement this stream
 * @stream: FILE type pointer
 *
 * Return: fd (SUCCESS), -1 (FAIL)
 **/
int _fileno(FILE *stream)
{
	int fd = stream->_fileno;

	if (fd < 0)
	{
		perror("Invalid stream");
		return (-1);
	}
	return (fd);
}

/**
 * _fgetc - reads the next character from stream and returns it
 * @stream: pointer to FILE type
 *
 * Return: unsigned char cast to an int, or EOF on end of file or error
 **/
int _fgetc(FILE *stream)
{
	int c;
	int fd = _fileno(stream);

	if (fd == -1)
	{
		perror("file descriptor");
		return (-1);
	}
	if (read(fd, &c, 1) != 1)
	{
		return (-1);
	}
	return (c);
}

/**
 * _getline - my own getline function
 * @lineptr: stores the address of the pointer to write to
 * @n: number of chars to write
 * @stream: I/O channel to write to
 *
 * Return: number of characters read,
 *         but not including the terminating null byte ('\0') (SUCCESS)
 *         -1 on failure to read a line (including EOF condition)
 **/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t read_chars = 0, size = 128;
	char *buffer = *lineptr;
	char c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL && *n == 0)
	{
		buffer = malloc(sizeof(char) * size);
		if (buffer == NULL)
		{
			return (-1);
		}
		*lineptr = buffer, *n = 0;
	}
	while ((c = _fgetc(stream)) != EOF)
	{
		*n += read_chars;
		buffer[read_chars++] = c;
		if (c == '\n')
		{
			buffer[read_chars] = '\0';
			return (read_chars);
		}
		if (read_chars == size)
		{
			size *= 2;
			buffer = realloc(buffer, size);
			if (buffer == NULL)
			{
				free(*lineptr);
				return (-1);
			}
		}
	}
	buffer[read_chars] = '\0';
	return (-1);
}
