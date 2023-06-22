#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: The head of the stack
 * @num_line: Line number of the command in the bytecode file
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int num_line)
{
	unsigned int len = 0, tmp = 0;

	len = stack_size(*stack);

	if (len < 2)
		error_handler(ERROR_SWAP, NULL, num_line, NULL);

	if (*stack)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
}
