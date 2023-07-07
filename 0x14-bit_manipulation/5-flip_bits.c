#include "main.h"

/**
 * flip_bits - Enumerates number of bits to change
 * to moe from one num to another
 * @n: 1st num
 * @m: 2nd num
 * Return: The amount of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int exclusive = n ^ m;
	unsigned int count = 0;

	while (exclusive != 0)
	{
		count += (exclusive & 1);
		exclusive >>= 1;
	}

	return (count);
}
