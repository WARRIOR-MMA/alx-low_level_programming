#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: The name of the file to read.
 * @letters: The number of characters to read.
 * Return: The actual number of characters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1 || filename == NULL)
	{
		return (0);
	}

	char buf[letters];
	ssize_t bytes_read = read(fd, buf, letters);

	if (bytes_read == -1)
	{
		close(fd);
		return (0);
	}

	ssize_t bytes_written = write(STDOUT_FILENO, buf, bytes_read);

	close(fd);

	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		return (0);
	}

	return (bytes_written);
}
