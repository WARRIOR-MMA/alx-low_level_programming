#include "main.h"

/**
 * get_bit - The value of a bit will be returned with index in dec. number
 * @n: value to search
 * @index: The index of bit
 * Return: The bits value at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);

	return ((n >> index) & 1);
}
