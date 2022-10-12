#include "3-calc.h"

/**
 * op_add-calculates two integer sum
 * @a: integer first
 * @b: inteer second
 *
 * Return: sum of two integers
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub-calculates diff of two integers
 * @a:integer one
 * @b:integer two
 *
 * Return:difference of two integers
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul-calculates product of two integers
 * @a:integer one
 * @b:integer two
 *
 * Return:product of two integers
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div-divides two integers
 * @a:first integer
 * @b:second integer
 *
 * Return:a/b result
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod-computes the remainder of division of two integers
 * @a:first integer
 * @b:second integer
 *
 * Return:division remainder
 */
int op_mod(int a, int b)
{
	return (a % b);
}
