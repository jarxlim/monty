#include "monty.h"

/**
 * get_push - helps pushes a item to a stack
 * @stack: pointer to stack
 * @l: the file line number calling
 */
void get_push(stack_t **stack, unsigned int l)
{
char *s;
int n;
s = strtok(NULL, "\n\t\r ");
if (s == NULL || digit_check(s))
{
fprintf(stderr, "L%u: usage: push integer\n", l);
exit(EXIT_FAILURE);
}
n = atoi(s);
if (!node_added(stack, n))
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
dive.stack_size++;
}

/**
 * get_printall - helps to print all of the item in stack
 * @stack: pointer to the stack
 * @l: line number
 */
void get_printall(stack_t **stack, unsigned int l)
{
stack_t *head;
(void) l;
head = *stack;
while (head != NULL)
{
printf("%d\n", head->n);
head = head->next;
if (head == *stack)
return;
}
}

/**
 * get_printtop - prints at the top of the stack
 * @stack: pointer to the stack
 * @line: line number
 */
void get_printtop(stack_t **stack, unsigned int l)
{
stack_t *head = *stack;
if (dive.stack_size == 0)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", l);
exit(EXIT_FAILURE);
}
printf("%d\n", head->n);
}

/**
 * get_pop - func that removes the top element of the stack
 * @stack: pointer to the node
 * @l: line number
 */
void get_pop(stack_t **stack, unsigned int l)
{
stack_t *pop = *stack;
if (dive.stack_size == 0)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", l);
exit(EXIT_FAILURE);
}
(*stack)->next->prev = (*stack)->prev;
(*stack)->prev->next = (*stack)->next;
if (dive.stack_size != 1)
{
*stack = (*stack)->next;
}
else
*stack = NULL;
free(pop);
dive.stack_size--;
}

/**
 * get_swap - func that swaps the top two element
 * @stack: pointer to the top node
 * @l: file line number
 */
void get_swap(stack_t **stack, unsigned int l __attribute__ ((unused)))
{
stack_t *temp;
if (dive.stack_size < 2)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", l);
exit(EXIT_FAILURE);
}
if (dive.stack_size == 2)
{
*stack = (*stack)->next;
return;
}
temp = (*stack)->next;
temp->prev = (*stack)->prev;
(*stack)->prev->next = temp;
(*stack)->prev = temp;
(*stack)->next = temp->next;
temp->next->prev = *stack;
temp->next = *stack;
*stack = temp;
}
