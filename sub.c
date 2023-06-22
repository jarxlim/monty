#include "monty.h"

/**
 * sub - func that subtracts the top element of the stack
 * @stack: The head of the stack
 * @num_line: Line number of the command in the bytecode file
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int num_line)
{
	unsigned int a = 0, b = 0, len = 0;
	stack_t *tmp = *stack;

	len = stack_size(*stack);

	if (len < 2)
		error_handler(ERROR_SUB, NULL, num_line, NULL);

	a = tmp->n;
	b = tmp->next->n;
	tmp->next->n = b - a;
	*stack = tmp->next;
	free(tmp);
}
