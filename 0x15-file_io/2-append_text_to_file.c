#include "main.h"

/**
 * append_text_to_file - Appends txt to EOF
 * @filename: Name of the File
 * @text_content: Str to add to EOF the Null term. str.
 * Return: If function fails or filename is NULL: -1.
 * If no file can be found User lacks WR permissions: -1.
 * Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int infile, twrites, flen = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[flen])
			flen++;
	}

	infile = open(filename, O_WRONLY | O_APPEND);

	if (infile == -1)
		return (-1);

	twrites = write(infile, text_content, flen);

	if (twrites == -1)
	{
		close(infile);
		return (-1);
	}

	close(infile);
	return (1);
}
