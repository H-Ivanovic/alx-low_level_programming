#include "dog.h"
#include <stdlib.h>

/**
 * _strlen-finds length of the string
 * @str:string
 *
 * Return:length of the string
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * _strcpy-copies astring
 * @src:string source
 * @dest:buffer storing the copy of the string
 *
 * Return:pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int index = 0;

	for (index = 0; src[index]; index++)
		dest[index] = src[index];

	dest[index] = '\0';
	return (dest);
}

/**
 * new_dog-creates a new dog
 * @name:name of the dog
 * @age:age of the dog
 * @owner:owner of the dog
 *
 * Return:NULL if the function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dogie;

	if (name == NULL || age < 0 || owner == NULL)
		return (NULL);

	dogie = malloc(sizeof(dog_t));
	if (dogie == NULL)
		return (NULL);

	dogie->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (dogie->name == NULL)
	{
		free(dogie);
		return (NULL);
	}

	dogie->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (dogie->owner == NULL)
	{

		free(dogie->name);
		free(dogie);
		return (NULL);
	}

	dogie->name = _strcpy(dogie->name, name);
	dogie->age = age;
	dogie->owner = _strcpy(dogie->owner, owner);

	return (dogie);
}
