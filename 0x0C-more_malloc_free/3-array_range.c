#include "main.h"

/**
 * array_range-function that creates an array of integers.
 * @min:minimum values
 * @max:maximum values
 *
 * Return:min > max, return NULL
 */
int *array_range(int min, int max)
{
	int *arr, i = 0, t = min;

	if (min > max)
		return (0);
	arr = malloc((max - min + 1) * sizeof(int));

	if (!arr)
		return (0);
	while (i <= max - min)
		arr[i++] = t++;
	return (arr);
}
