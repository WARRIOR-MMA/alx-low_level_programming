#include <stdio.h>

/**
 * main - Prints possible combos of two two-digits, range 0-99
 * Return: Always 0.
 */
int main(void)
{
int a, b;

for (a = 0; a < 100; a++)
{
for (b = 0; b < 100; b++)
{
if (a < b)
{
putchar((a/ 10)
