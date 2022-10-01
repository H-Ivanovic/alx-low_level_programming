#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * check_num-checks for a number
 * @str:array str
 *
 * Return: always 0
 */
int check_num(char *str)
{
unsigned int count;

count = 0;
while (count < strlen(str))

{
if (!isdigit(str[count]))
{
return (0);
}

count++;
}
return (1);
}
