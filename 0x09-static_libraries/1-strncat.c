#include "main.h"

/**
 * _strncat-function concatenates two strings
 * @src:string to be completed at the end of dest
 * @dest:string to be appended upon
 *
 * return pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int index = 0, dest_len = 0;
	
	while (dest[index++])
		dest_len++;

	for (index = 0; src[index] && index < n; index++)
		dest[dest_len++] = src[index];

	return (dest);
}

