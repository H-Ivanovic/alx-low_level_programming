#include "main.h"

/**
 * reverse_array-reverses the array content
 * @n:number of elements
 * @:array
 *
 * return:0
 */
void reverse_array(int *a, int n)
{
	int tmp, index;
	for (index = n - 1; index > n / 2; index--)
	{
		tmp = a[n - 1 - index];
		a[n - 1 - index] = a[index];
		a[index] = tmp;

	}
}
