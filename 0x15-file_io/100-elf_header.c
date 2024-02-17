#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

void print_magic(const unsigned char *ident)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; ++i)
	{
		printf("%02x ", ident[i]);
	}
	printf("\n");
}

void print_ident_info(const Elf64_Ehdr *header)
{
	printf("  Class:                             %s\n",
			(header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
			(header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
			(header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "UNIX - NetBSD");
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
}

void print_type_info(const Elf64_Ehdr *header)
{
	printf("  Type:                              ");
	switch (header->e_type)
	{
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_type);
			break;
	}
}

void print_elf_header(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		exit(98);
	}

	Elf64_Ehdr header;

	/* Read ELF header */
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		perror("Error reading ELF header");
		close(fd);
		exit(98);
	}

	/* Check if it's an ELF file */
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 ||
		header.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error("Not an ELF file");
	}

	/* Print ELF header information */
	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_ident_info(&header);
	print_type_info(&header);

	/* Use lseek to move to the entry point address */
	if (lseek(fd, (off_t)header.e_entry, SEEK_SET) == -1)
	{
		perror("Error using lseek");
		close(fd);
		exit(98);
	}

	close(fd);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	print_elf_header(argv[1]);

	return (0);
}
