#include "monty.h"

/**
  * push - Adds a new node at the beginning of the stack
  * @stack: The head of the stack
  * @data: The data to push on the stack
  * Return: Nothing
  */
void push(stack_t **stack, unsigned int data)
{
	stack_t *newnode = NULL;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
		error_handler(ERROR_MALLOC, NULL, 0, NULL);

	newnode->n = data;
	if (*stack)
	{
		newnode->next = *stack;
		newnode->prev = (*stack)->prev;
		(*stack)->prev = newnode;
		*stack = newnode;
		return;
	}

	newnode->next = *stack;
	newnode->prev = NULL;
	*stack = newnode;
}

/**
  * push_queue - Adds a new node at the end of the stack
  * @stack: The head of the stack
  * @data: The value to push on the stack
  *
  * Return: Nothing
  */
void push_queue(stack_t **stack, unsigned int data)
{
	stack_t *current = NULL, *newnode = NULL;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
		error_handler(ERROR_MALLOC, NULL, 0, NULL);

	newnode->n = data;
	if (*stack)
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;

		newnode->next = NULL;
		newnode->prev = current;
		current->next = newnode;
		return;
	}

	newnode->next = *stack;
	newnode->prev = NULL;
	*stack = newnode;
}
