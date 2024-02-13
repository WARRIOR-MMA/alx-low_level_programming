#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void close_descriptor(int fd);
char *allocate_buffer(char *filename);

/**
 * allocate_buffer - 1024 is alloc. to buffer.
 * @filename: file storing
 * Return: Pointer to the new allocated buffer.
 */
char *allocate_buffer(char *filename)
{
	char *albuff;

	albuff = malloc(sizeof(char) * 1024);

	if (albuff == NULL)
	{
		dprintf(STDERR_FILENO,
		"Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (albuff);
}

/**
 * close_descriptor - shuts down descriptor
 * @fd: what needs to be closed
 */

void close_descriptor(int fd)
{
	int shutdesc;

	shutdesc = close(fd);

	if (shutdesc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - data copied to different file
 * @argv: Array of pointers
 * @argc: Num of arguments
 * Return: 0 on success.
 * Descr: If the number of argument is not the correct one - exit code 97.
 *        If file_from cannot be found or cannot be read - exit code 98.
 *        If you can not create or if write to file_to fails - exit code 99.
 *        If you can not close a file descriptor - exit code 100.
 */
int main(int argc, char *argv[])
{
	int fdes_source, fdes_locat;
	int file_rd, file_wr;
	char *albuff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	albuff = allocate_buffer(argv[2]);
	fdes_source = open(argv[1], O_RDONLY);
	file_rd = read(fdes_source, albuff, 1024);
	fdes_locat = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fdes_source == -1 || file_rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(albuff);
			exit(98);
		}

		file_wr = write(fdes_locat, albuff, file_rd);

		if (fdes_locat == -1 || file_wr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(albuff);
			exit(99);
		}

		file_rd = read(fdes_source, albuff, 1024);
		fdes_locat = open(argv[2], O_WRONLY | O_APPEND);

	} while (file_rd > 0);

	free(albuff);
	close_descriptor(fdes_source);
	close_descriptor(fdes_locat);

	return (0);
}
