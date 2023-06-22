#include "monty.h"

/**
 * opera_call - function that executes called instructios
 * @stack: pointer to top node
 * @opera: strings of copy of the stack
 * @l: the file line number
 */

void opera_call(stack_t **stack, char *opera, unsigned int l)
{
int chr;
instruction_t operas[] = {
{"push", get_push},
{"pall", get_printall},
{"pint", get_printtop},
{"pop", get_pop},
{"swap", get_swap},
{"add", get_add},
{"nop", get_nop},
{"sub", get_sub},
{"div", get_div},
{"mul", get_mul},
{"mod", get_mod},
{"pchar", get_char},
{"pstr", get_str},
{"rotl", get_rotl},
{"rotr", get_rotr},
{"stack", stack_setter},
{"queue", queue_setter},
{NULL, NULL}
};

for (chr = 0; operas[chr].opcode != NULL; chr++)
{
if (strcmp(opera, operas[chr].opcode) == 0)
{
operas[chr].f(stack, l);
return;
}
}
fprintf(stderr, "L%u: unknown instruction %s\n", l, opera);
exit(EXIT_FAILURE);
}
