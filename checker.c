#include "monty.h"

/**
  * args_checker - Check the arguments passed
  * @agc: Number of arguements
  * Return: Nothing
  */

void args_checker(int agc)
{
	if (agc != MINI_ARG)
		error_handler(ERROR_USE, NULL, 0, NULL);
}

/**
  * permission_reader - Checks for user permission
  * @fd: The path
  * Return: Nothing
  */

void permission_reader(char *fd)
{
	if (access(fd, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fd);
		exit(EXIT_FAILURE);
	}
}

/**
  * data_checker - Check the data of the push instruction
  * @data: The parameter to be validated.
  *
  * Return: 0 if data is valid or errcode if is invalid.
  */
int data_checker(char *data)
{
	if (data == NULL || digits_checker(data) == 0)
		return (ERROR_PUSH);

	return (VAL_DATA);
}

/**
  * digits_checker - Checks for didgts in char
  * @str: The string to be used
  * Return: 1 or zero on failure
  */

int digits_checker(char *str)
{
	while (*str != '\0')
	{
		if (str[0] == '-')
		{
			str++;
			continue;
		}

		if (isdigit(*str) == 0)
			return (0);

		str++;
	}

	return (1);
}
