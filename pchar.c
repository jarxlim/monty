#include "monty.h"

/**
  * pchar - Prints the char at the top
  * @stack: The head of the stack
  * @num_line: Line number of the command
  * Return: Nothing
  */
void pchar(stack_t **stack, unsigned int num_line)
{
	if (*stack == NULL)
		error_handler(ERROR_PCHARE, NULL, num_line, NULL);

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
		error_handler(ERROR_PCHARF, NULL, num_line, NULL);
}
