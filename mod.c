#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 * @stack: The head of the stack
 * @num_line: Line number of the command in the bytecode file
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int num_line)
{
	stack_t *tmp = *stack;
	unsigned int a = 0, b = 0, len = 0;

	len = stack_size(*stack);

	if (len < 2)
		error_handler(ERROR_MOD, NULL, num_line, NULL);

	a = tmp->n;

	if (a == 0)
		error_handler(ERROR_ZDIV, NULL, num_line, NULL);

	b = tmp->next->n;
	tmp->next->n = b % a;
	*stack = tmp->next;
	free(tmp);
}
