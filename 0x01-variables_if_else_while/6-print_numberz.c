#include <stdio.h>

/**
 * main - print
 * this program prints numbers of base ten
 * return: 0
 */
int main (void)
{
int i;
for (i = 0; i < 10; i++)
{
	putchar("%i", i);
}
putchar('\n');
return (0);
}
