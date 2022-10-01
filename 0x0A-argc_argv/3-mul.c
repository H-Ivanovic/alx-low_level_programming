#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main-program that multiplies two numbers.
 * @argv:argument
 * @argc:count argument
 *
 * Return: 0 if true and 1 if otherwise
 */
int main(int argc, char *argv[])
{
int a, b;
if (argc == 1)
{
a = atoi(argv[1]);
b = atoi(argv[2]);
printf("%d\n", a *b);
return (0);
}
printf("Error\n");
return (1);
}
