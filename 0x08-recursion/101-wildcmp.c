#include "main.h"

/**
 * wildcmp:-function that compares two strings
 * @s1:string one
 * @s2:string two
 *
 * returns:1 for identical strings and 0 if otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
		return (*s1 == '\0');
	if (*s2 == *s1)
		return (*s1 != '\0' && wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || (*s2 != '\0' && wildcmp(s1 + 1, s2)));
	return (0);
}
