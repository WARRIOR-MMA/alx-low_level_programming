#include "main.h"
#include <unistd.h>
/**
 * _putchar - Writes Char c to stdout
 * @c: character to print
 * Return: Success 1.
 * On Error, -1 required, error is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
