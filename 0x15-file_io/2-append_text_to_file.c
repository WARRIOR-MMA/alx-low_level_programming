#include "main.h"

/**
 * append_text_to_file - Appends text at the end of file.
 * @text_content: The NULL terminated string to add to the end of the file.
 * @filename: The Name of the file.
 * Return: If the function fails or filename is NULL: -1.
 * If no file can be found User lacks WR permissions: -1.
 * Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int wr, op, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
			length++;
	}

	op = open(filename, O_WRONLY | O_APPEND);

	if (op == -1)
		return (-1);

	wr = write(op, text_content, length);

	if (wr == -1)
	{
		close(op);
		return (-1);
	}

	close(op);
	return (1);
}
