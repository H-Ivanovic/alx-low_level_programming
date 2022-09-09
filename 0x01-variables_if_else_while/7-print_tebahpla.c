#include <stdio.h>

/**
 * main - print
 *
 * description: lowercase
 * this program prints lowercase in reverse
 */
int main(void)
{
char c;
for (c = 'z'; c >= 'a'; c--)
{
putchar(c);
}
putchar('\n');
return (0);
}
