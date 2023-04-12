#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads file and prints it to POSIX stdout.
 * @filename: Pointer to the name of file.
 * @letters: Number of letters function will read and print.
 * Return: If function fails or filename is NULL - 0.
 * O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t c, r, w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	c = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (c == -1 || r == -1 || w == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(c);

	return (w);
}

