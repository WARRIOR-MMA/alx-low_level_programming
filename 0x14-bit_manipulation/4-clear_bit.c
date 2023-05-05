#include "main.h"

/**
 * clear_bit - Value of a given bit sets to 0
 * @index: Shows the index of the bit to be cleared
 * @n: Is the pointer to num that will change
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	mask = 1 << index;
	*n &= ~mask;

	return (1);
}
