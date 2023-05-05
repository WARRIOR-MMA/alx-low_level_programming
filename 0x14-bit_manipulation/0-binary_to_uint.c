#include "main.h"

/**
 * binary_to_uint - The binary value will be converted to unsigned int
 * @b: The binary number will be stored in this string
 * Return: Converted value
 */
unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (j = 0; b[j]; j++)
	{
		if (b[j] < '0' || b[j] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[j] - '0');
	}

	return (dec_val);
}
