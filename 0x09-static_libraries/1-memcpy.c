#include "main.h"
#include <stdio.h>
/**
 * *_memcpy - copy memory area to be specified
 * @dest: where memory will be stored
 * @src:  source of memory
 * @n:   number of bytes
 * Return: pointer to destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
