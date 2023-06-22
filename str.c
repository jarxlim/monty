#include "monty.h"

/**
  * pstr - Prints the string starting at the top of the stack,
  * @stack: The head of the stack
  * @num_line: Line number of the command in the bytecode file
  * Return: Nothing
  */
void pstr(stack_t **stack, unsigned int num_line)
{
	stack_t *current = *stack;
	(void) num_line;

	while (current)
	{
		if (current->n == 0 || current->n < 0 || current->n > 127)
			break;

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
