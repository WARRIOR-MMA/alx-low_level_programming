#include <stdio>

/**
 * print_to_98 - Prints all natural numbers from input to 98
 * seperated by coma followed by space.
 * @n: Beginning count
 */

void print_to_98(int n)
{
	if (n >= 98)
	{
		while (n > 98)
			printf("%d, ", n--);
		printf("%d\n", n);
	}
	else
	{
		while (n < 98)
			printf("%d, ", n++);
		printf("%d\n", n);
	}
}
