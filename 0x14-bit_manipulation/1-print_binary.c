#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i;
	int found_first_one = 0;

	for (i = 63; i >= 0; i--)
	{
		unsigned long int mask = 1UL << i;
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
