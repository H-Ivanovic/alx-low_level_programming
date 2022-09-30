#include "main.h"

/**
 * is_palindrome - check if a string is a palindrome
 *
 * Return: 1 if palindrome, and 0 if otherwise
 */
int is_palindrome(char *s)
{
	int length;

	length = get_length(s) - 1;

	return (my_pal(s, --length));
}

/**
 * get_length - gets length of string
 *
 * Return: return length of string
 */
int get_length(char *s)
{
	if (*s == '\0')
		return (1);
	else
		return (1 + get_length(++s));
}

/**
 * my_pal - recursive check of palindrome
 *
 * Return: 1 if palindrome, 0 if not
 */
int my_pal(char *s, int l)
{
	if (*s == *(s + l))
	{
		if (l <= 0)
			return (1);
		else
			return (my_pal(++s, l - 2));
	}
	else
		return (0);
}
