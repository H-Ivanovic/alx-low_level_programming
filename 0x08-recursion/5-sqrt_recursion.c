#include "main.h"

/**
 * _sqrt_recursion-returns the natural square root of a number.
 * @n:number
 *
 * return:-1 i n has no natural square root
 */
int _sqrt_recursion(int n)
{
	if (n == 1 || n == 0)
		return (n);
	return (_sqrt(0, n));
}

/**
 * _sqrt-returns square root of a number
 * @n:number
 * @x: squared number
 *
 * return: square root of n
 */
int _sqrt(int n, int x)
{
	if (n > x / 2)
		return (-1);
	else if (n * n == x)
		return (n);
	return (_sqrt(n + 1, x));
}
