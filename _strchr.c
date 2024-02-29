#include "simple_shell.h"

/**
 * _strchr - Locates first occurrence of the character c in the string s
 * @s: delimeter string
 * @c: character
 *
 * Return: Pointer to the matched character, NULL if the character is not found
 **/
char *_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char) c)
		s++;
	return (*s == (char)c ? (char *)s : NULL);
}
