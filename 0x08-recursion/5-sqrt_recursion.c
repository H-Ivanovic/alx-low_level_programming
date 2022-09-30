#include "main.h"

int find_sqrt(int num, int root);
int _sqrt_recursion(int n);

/**
 * _sqrt_recursion-function that returns the natural square root of a number.
 * @n:number
 *
 * return square root of n
 */
int find_sqrt(int num, int root)
{
	if ((root * root) == num)
		return (root);

