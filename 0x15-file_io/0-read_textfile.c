#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Reads a text file and prints it to POSIX stdout.
 * @filename: The File containing Text being read
 * @letters: The amount of number of letters should read and print
 * Return: wr- actual amount of bytes read and printed
 * 0 if function fail or the filename == NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_descriptor;
	ssize_t wr;
	ssize_t rd;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	rd = read(file_descriptor, buffer, letters);
	wr = write(STDOUT_FILENO, buffer, rd);

	free(buffer);
	close(file_descriptor);
	return (wr);
}
