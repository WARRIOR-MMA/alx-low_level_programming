#include "main.h"

/**
 * create_file - File will be made
 * @filename: Name of file to make
 * @text_content: the str to write
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t writes;
	int fd;
	size_t slen = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[slen])
			slen++;
	}

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	writes = write(fd, text_content, slen);

	if (writes == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
