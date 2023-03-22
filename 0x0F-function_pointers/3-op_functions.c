#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
/**
 * op_add - Sum of Two values will be returned
 * @a: First number.
 * @b: Second number.
 * Return: sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - Diff. of two values will be returned
 * @a: first number.
 * @b: second number.
 * Return: Diff. of a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - Product of two values will be returned
 * @a: first number.
 * @b: second number.
 * Return: Product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - Division of two values will be returned
 * @a: first number.
 * @b: second number.
 * Return: Quotient of a and b.
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - remainder of the division of two values is returned
 * @a: first number.
 * @b: second number.
 * Return: The remainder of the division of a by b.
 */
int op_mod(int a, int b)
{
	return (a % b);
}
