#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: The head of the stack
 * @num_line: Line number of the command in the bytecode file
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int num_line)
{
	stack_t *tmp = *stack;
	unsigned int a = 0, b = 0, len = 0;

	len = stack_size(*stack);

	if (len < 2)
		error_handler(ERROR_ADD, NULL, num_line, NULL);

	a = tmp->n;
	b = tmp->next->n;
	tmp->next->n = a + b;
	*stack = tmp->next;
	free(tmp);
}
