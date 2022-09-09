#include <stdio.h>

/**
 * main - print
 *
 * description: print alphabet
 * this program prints all letters except q and e
 */
int main(void)
{
char ch;
for (ch = 'a' ; ch <= 'z' ; ch++)
{
if (ch != 'q' && ch != 'e')
{
	putchar(ch);
}
}
putchar('\n');
return (0);
}
