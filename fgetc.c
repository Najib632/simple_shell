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
		return (-1);
	if (read(fd, &c, 1) == -1)
		return (EOF);
	return (c);
}
