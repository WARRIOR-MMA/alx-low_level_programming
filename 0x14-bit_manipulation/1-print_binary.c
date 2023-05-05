#include "main.h"

/**
 * print_binary - The binary equivalent of the decimal number will be printed
 * @n: The number that will be printed in binary
 */
void print_binary(unsigned long int n)
{
	int j;
	int found_first_one = 0;

	for (j = 63; j >= 0; j--)
	{
		unsigned long int mask = 1UL << j;
		int bit = (n & mask) ? 1 : 0;

		if (bit || found_first_one)
		{
			found_first_one = 1;
			_putchar(bit ? '1' : '0');
		}
	}

	if (!found_first_one)
		_putchar('0');
}
