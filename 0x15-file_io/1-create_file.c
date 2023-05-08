#include "main.h"

/**
 * create_file - Creates a file.
 *
 * @filename: The name of the file to create.
 * @text_content: The string to write to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor;                 /* File descriptor */
	ssize_t wr;              /* Number of bytes written */
	size_t length = 0;         /* Length of text_content */

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
			length++;
	}

	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_descriptor == -1)
		return (-1);

	wr = write(file_descriptor, text_content, length);

	if (wr == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);
	return (1);
}
