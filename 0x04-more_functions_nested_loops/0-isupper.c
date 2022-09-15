#include "main.h"

/**
 * main - function that checks for uppercase
 *
 * description: _isupper prints a number
 * return 1 if upercase else 0
 */
int _isupper(int c)
{
       	if (c > 64 && c < 91)
		return (1);

	return (0);
}
