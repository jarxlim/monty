#include "monty.h"

/**
  * stackfreed - Frees all nodes
  * Return: Nothing
  */

void stackfreed(void)
{
	stack_t *current = NULL;

	if (head)
	{
		current = head;

		while (current)
		{
			head = head->next;
			free(current);
			current = head;
		}
	}
}

/**
  * stack_size - Counts the number of element
  * @stack: Head of the stack to number
  * Return: Number of elements in the stack
  */

unsigned int stack_size(stack_t *stack)
{
	stack_t *current = stack;
	unsigned int length = 0;

	while (current)
	{
		length++;
		current = current->next;
	}

	return (length);
}
