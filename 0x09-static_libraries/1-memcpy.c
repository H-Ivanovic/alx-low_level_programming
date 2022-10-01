#include "main.h"

/**
 * _memcpy-function that coies a memory area
 * @dest:mmemory area to be copied to
 * @src:memory area to be copied from
 *
 * return ointer to memory block
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	for (; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
