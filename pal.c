#include "monty.h"

/**
 * pall - Prints all the values starting from the top of the stack.
 * @stack: The head of the stack
 * @num_line: Line number of the command
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int num_line)
{
	stack_t *current = NULL;
	(void) num_line;

	if (*stack)
	{
		current = *stack;
		while (current)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
