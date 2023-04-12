#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *filename);
void close_descriptor(int fd);

/**
 * allocate_buffer - Allocates 1024 bytes buffer.
 * @filename: Name of the file buffer thats storing chars
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *filename)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
		"Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buf);
}

/**
 * close_descriptor - Closes file descriptors.
 * @fd: File descriptor to be closed.
 */
void close_descriptor(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, n_read, n_written;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = allocate_buffer(argv[2]);
	fd_from = open(argv[1], O_RDONLY);
	n_read = read(fd_from, buf, 1024);
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fd_from == -1 || n_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		n_written = write(fd_to, buf, n_read);

		if (fd_to == -1 || n_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		n_read = read(fd_from, buf, 1024);
		fd_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (n_read > 0);

	free(buf);
	close_descriptor(fd_from);
	close_descriptor(fd_to);

	return (0);
}
