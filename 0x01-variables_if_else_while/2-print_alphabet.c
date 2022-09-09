#include <stdio.h>

/**
 * main - prints
 *
 * Description:lowercase
 * this program prints alphabet in lowercase
 */
int main(void)
{
char ch;
for (ch = 'a' ; ch <= 'z' ; ch++)
{
	putchar(ch);
}
putchar('\n');
return (0);
}
