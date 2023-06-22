#include "monty.h"

/**
 * pop - func that removes the top element of the stack
 * @stack: The head of the stack
 * @num_line: Line number of the command in the bytecode file
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int num_line)
{
	stack_t *current = *stack, *tmp = NULL;

	if (*stack == NULL)
		error_handler(ERROR_POP, NULL, num_line, NULL);

	tmp = current;
	if (current->next)
	{
		current = current->next;
		current->prev = tmp->prev;
		*stack = current;
	}
	else
	{
		*stack = NULL;
	}

	free(tmp);
}
