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

/**
 * _strtok - splits a string and returns an array of each word of the string
 * @str: string to be parsed
 * @delim: specifies a set of bytes that delimit the tokens in str
 *
 * Return: A null-terminated string containing the next token or NULL on error
 **/
char *_strtok(char *str, const char *delim)
{
	static char *static_str;
	char *token_end;

	if (str != NULL)
		static_str = str;
	else
		str = static_str;
	if (str == NULL || *static_str == '\0')
		return (NULL);

	token_end = str;
	while (*token_end != '\0' && _strchr(delim, *token_end) == NULL)
		token_end++;

	*token_end = '\0';
	token_end++;
	static_str = token_end;
	return (str);
}
