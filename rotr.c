#include "monty.h"

/**
  * rotr - Rotates the stack to the bottom
  * @stack: The head of the stack
  * @num_line: Line number of the command in the bytecode file
  * Return: Nothing
  */
void rotr(stack_t **stack, unsigned int num_line)
{
	stack_t *last = NULL;
	(void) num_line;

	if (*stack && (*stack)->next)
	{
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		last->prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

/**
  * rotl - Rotates the stack to the top
  * @stack: The head of the stack
  * @num_line: Line number of the command in the bytecode file
  * Return: Nothing
  */
void rotl(stack_t **stack, unsigned int num_line)
{
	unsigned int tmp = 0;
	stack_t *current = *stack;
	(void) num_line;

	if (current && current->next)
	{
		while (current->next)
		{
			tmp = current->n;
			current->n = current->next->n;
			current->next->n = tmp;
			current = current->next;
		}
	}
}
