#include "main.h"

/**
 * is_prime_number-returns 1 if n is prime
 * @n:number to be checked
 *
 * return 1 if n is prime and 0 if otherwise
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	if (n < 4)
		return (1);
	return (hai(n, 2));

}

/**
 * is_prime-returns 1 if n is prime
 *
 * return 1 if n is prime andd 0 if otherwise
 */
int _sqrt(int x, int i)
{
	int square;

	square = i * i;
	if (square >= x)
		return (i);
	else
		return (_sqrt(x, i + 1));
}

/**
 * hai - helper function, recursive steps taken
 *
 * Return: 0 if not prime, 1 if prime
 */
int hai(int n, int d)
{
	if (n % d == 0)
		return (0);
	else if (_sqrt(n, 1) < d)
		return (1);
	else
		return (hai(n, d + 1));
}
