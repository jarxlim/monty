#include "monty.h"

/**
  * file_opener - Opens a file
  * @fd: File to open
  * Return: File descriptor of the opened file
  */
FILE *file_opener(char *fd)
{
	FILE *file = NULL;

	permission_reader(fd);

	file = fopen(fd, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fd);
		exit(EXIT_FAILURE);
	}

	return (file);
}
