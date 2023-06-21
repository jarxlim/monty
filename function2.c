#include "monty.h"

/**
 * get_add - func that adds the top two elements
 * @stack: pointer to the node
 * @line: file line number
 */
void get_add(stack_t **stack, unsigned int l)
{
int n = 0;
if (dive.stack_size < 2)
{
fprintf(stderr, "L%u: can't add, stack too short\n", l);
exit(EXIT_FAILURE);
}
n += (*stack)->n;
instruct_pop(stack, l);
(*stack)->n += n;
}

/**
 * get_nop - func of nop that does nothing
 * @stack: pointer to the node
 * @line: file line number
 */
void get_nop(stack_t **stack __attribute__ ((unused)), unsigned int l)
{
(void) l;
}

/**
 * get_sub - subtracts the top from the second top
 * @stack: pointer to the node top
 * @l: file line number
 */
void get_sub(stack_t **stack, unsigned int l)
{
int n;
if (dive.stack_size < 2)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", l);
exit(EXIT_FAILURE);
}
n = (*stack)->n;
get_pop(stack, l);
(*stack)->n -= n;
}

/**
 * get_div - func that divides the second top by the top element
 * @stack: pointer to the top node 
 * @l: the file line number
 */
void get_div(stack_t **stack, unsigned int l)
{
int n;
if (dive.stack_size < 2)
{
fprintf(stderr, "L%u: can't div, stack too short\n", l);
exit(EXIT_FAILURE);
}
n = (*stack)->n;
get_pop(stack, l);
if (n == 0)
{
fprintf(stderr, "L%u: division by zero\n", l);
exit(EXIT_FAILURE);
}
(*stack)->n /= n;
}

/**
 * get_mul - func that multiplies the second top with the top element
 * @stack: pointer to the top node
 * @l: file line number
 */
void get_mul(stack_t **stack, unsigned int l)
{
int n;
if (dive.stack_size < 2)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", l);
exit(EXIT_FAILURE);
}
n = (*stack)->n;
get_pop(stack, l);
(*stack)->n *= n;
}
