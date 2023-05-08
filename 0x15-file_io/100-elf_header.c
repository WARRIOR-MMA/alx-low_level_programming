#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - To See if file is ELF File
 * @e_ident: An array with pointer containing the ELF magic numbers.
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int info;

	for (info = 0; info < 4; info++)
	{
		if (e_ident[info] != 127 &&
		    e_ident[info] != 'E' &&
		    e_ident[info] != 'L' &&
		    e_ident[info] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - The ELF header magic numbers will be printed
 * @e_ident: An array that has a pointer containing ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int info;

	printf("  Magic:   ");

	for (info = 0; info < EI_NIDENT; info++)
	{
		printf("%02x", e_ident[info]);

		if (info == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

