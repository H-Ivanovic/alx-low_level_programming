#include "main.h"

/**
 * leet:function that encodes a string into 1337
 *
 * return nothing
 */
char *leet(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		str[i] = transform(str[i]);
		i++;
	}
	return (str);
}


/**
 * transform-function that maps a letter to its encoding
 * char: ecodded character
 *
 * return: character encoded
 */
char transform(char y)
{
	char mapping_low[8] = {'o', 'l', '\0', 'e', 'a', '\0', '\0', 't'};
	char mapping_upper[8] = {'O', 'L', '\0', 'E', 'A', '\0', '\0', 'T'};
	int i = 0;
	char replacement = y;

	while (i < 8)
	{
		if (y == mapping_low[i] || y == mapping_upper[i])
		{
			replacement = i + '0';
			break;
		}
		i++;
	}
	return (replacement);
}
