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
 * _strcspn - get length of a prefix substring
 * @s: string to scan for reject
 * @reject: char being scanned for in s
 *
 * Return: number of bytes in the initial segment of s
 *         which are not in the string reject.
 **/
size_t _strcspn(const char *s, const char *reject)
{
	size_t i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; reject[j]; j++)
		{
			if (s[i] == reject[j])
				return (i);
		}
	}
	return (i);
}
