#include "main.h"

/**
 * set_bit - The bit at a given index will be set to 1
 * @n: It points to the value to change
 * @index: index set to 1 for the bit
 * Return: 1 success, -1 failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n |= (1UL << index);
	return (1);
}
