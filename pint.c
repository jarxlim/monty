#include "monty.h"

/**
 * pint - Prints the value at the top of the stack,
 * @stack: The head of the stack
 * @num_line: Line number of the command in the bytecode file
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int num_line)
{
	if (*stack == NULL)
		error_handler(ERROR_PINT, NULL, num_line, NULL);

	printf("%d\n", (*stack)->n);
}
