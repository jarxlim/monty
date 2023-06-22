#include "monty.h"
#include <ctype.h>
/**
 * get_mod - funct that rest the division of the second top by the top
 * @stack: pointer to the top node
 * @l: the current file line number
 */
void instruct_mod(stack_t **stack, unsigned int l)
{
int n;
if (dive.stack_size < 2)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", l);
exit(EXIT_FAILURE);
}
n = (*stack)->n;
get_pop(stack, l);
if (n == 0)
{
fprintf(stderr, "L%u: division by zero\n", l);
exit(EXIT_FAILURE);
}
(*stack)->n %= n;
}

/**
 * get_char - func that gets the char at tihe top
 * @stack: pointer to the top node
 * @l: file line number
 */
void get_char(stack_t **stack, unsigned int l)
{
int c;
if (dive.stack_size < 1)
{
fprintf(stderr, "L%u: can't pchar, stack empty\n", l);
exit(EXIT_FAILURE);
}
c = (*stack)->n;
if (!isascii(c))
{
fprintf(stderr, "L%u: can't pchar, value out of range\n", l);
exit(EXIT_FAILURE);
}
printf("%c\n", c);
}

/**
 * get_str - func dat prints the string starting at the top
 * @stack: pointer to the top node
 * @l: file line number
 */
void get_str(stack_t **stack, unsigned int l __attribute__ ((unused)))
{
stack_t *temp;
int c;
temp = *stack;
while (temp != NULL)
{
c = temp->n;
if (!isascii(c) || c == 0)
break;
putchar(c);
temp = temp->next;
if (temp == *stack)
break;
}
putchar('\n');
}

/**
 * get_rotl - rotates the stack to the top
 * @stack: pointer to the top node
 * @line: file line number
 */
void get_rotl(stack_t **stack, unsigned int l __attribute__ ((unused)))
{
if (*stack)
*stack = (*stack)->next;
}

/**
 * get_rotr - rotates the stack to the bottom
 * @stack: pointer to the top node
 * @l: file line number
 */ 
void get_rotr(stack_t **stack, unsigned int l __attribute__ ((unused)))
{
if (*stack)
*stack = (*stack)->prev;
}
