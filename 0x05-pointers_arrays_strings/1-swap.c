#include "main.h"

/**
 * swap int - swaps two integers
 *
 * @: first
 * @: second
 * return: 0/
 */

void swap_int(int *a, int *b);
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
