#include "monty.h"

stack_t *head = NULL;

/**
  * main - Entry point
  * @argc: Number of arguments
  * @argv: the arguments passed.
  *
  * Return: Always 0.
  */

int main(int argc, char *argv[])
{
	FILE *m_files = NULL;
	size_t cmd_size = 0;
	unsigned int num_line = 0;
	int cmd = 0, status = 0;
	char *fd = NULL, *opcode = NULL, *data = NULL, *line_reader = NULL;

	fd = argv[1];
	args_checker(argc);
	m_files = file_opener(fd);

	while ((cmd = getline(&line_reader, &cmd_size, m_files)) != -1)
	{
		num_line++;
		opcode = strtok(line_reader, " \t\n");
		if (opcode)
		{
			if (opcode[0] == '#')
				continue;

			data = strtok(NULL, " \t\n");
			status = exec_handler(opcode, data, num_line, status);

			if (status >= 100 && status < 300)
			{
				fclose(m_files);
				error_handler(status, opcode, num_line, line_reader);
			}
		}

	}

	stackfreed();
	free(line_reader);
	fclose(m_files);
	return (0);
}
