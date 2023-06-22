#include "monty.h"

/**
 * node_added - func that add a new node to the list
 * @stack: pointer to the beginning of the list
 * @n: value to add to the new node
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *node_added(stack_t **stack, const int n)
{
stack_t *add;

if (stack == NULL)
{
	return (NULL);
}
add = malloc(sizeof(stack_t));
if (add == NULL)
{
	return (NULL);
}
add->n = n;
if (*stack == NULL)
{
add->prev = add;
add->next = add;
}
else
{
(*stack)->prev->next = add;
add->prev = (*stack)->prev;
(*stack)->prev = add;
add->next = *stack;
}
if (dive.queue_size == STACKS || dive.stack_size == 0)
*stack = add;
return (add);
}
