#include "main.h"
#include <stdio.h>

/**
 *print_array-prints n elements of array of integers
 *@a-pointer to array
 *@n-number of array of elements
 *
 * return;void
 */
void print_array(int *a, int n)
{
	int k;

	for (k = 0; k < n; k++)
	{
		printf("%d", a[k]);
		if (k != n - 1)
		{
			printf(",");
			printf(" ");
		}
	}
	printf("\n");
}


