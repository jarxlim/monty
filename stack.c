#include "monty.h"

/**
 * digit_check - func that checks string is digit
 * @s: string input
 * Return: 0 if digit or 1 not digit
 */

int digit_check(char *s)
{
int chr;
for (chr = 0; s[chr]; chr++)
{
if (s[chr] == '-' && chr == 0)
continue;
if (isdigit(s[chr]) == 0)
return (1);
}
return (0);
}

/**
 * queue_settet - func that sets the format of the data to queue
 * @stack: pointer to the top
 * @l: line number
 */
void queue_setter(stack_t **stack, unsigned int l)
{
(void) stack;
(void) l;
dive.queue_size = QUEUES;
}

/**
 * stack_setter - func that sets the format of the data to a stack
 * @stack: pointer to the top
 * @l: line number
 */
void stack_setter(stack_t **stack, unsigned int l)
{
(void) stack;
(void) l;
dive.queue_size = STACKS;
}
