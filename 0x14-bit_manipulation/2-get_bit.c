#include "main.h"

/**
 * get_bit-returns the value of a bit at a given index.
 * @n:nummber
 * @index:index, starting from 0
 * Return:nothing
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 0))
		return (-1);

	if ((n & (1 << index)) == 0)
		return (0);

	return (1);
}
