#include "main.h"

/**
 * get_endianness - ascertains if machine is big endian or little
 * Return: 0 big, 1 little
 */
int get_endianness(void)
{
	unsigned int n = 1;
	char *c = (char *) &n;

	return (*c);
}
