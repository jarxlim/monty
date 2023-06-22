#include "monty.h"

/**
  * selectors - Select the operation
  * @str: The instruction
  * Return: Pointer to the function to be executed or
  */

void (*selectors(char *str))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{ "push_queue", push_queue },
		{ "pchar", pchar },
		{ "div", divide },
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "swap", swap },
		{ "pstr", pstr },
		{ "rotl", rotl },
		{ "rotr", rotr },
		{ "pop", pop },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "mul", mul },
		{ "mod", mod },
		{ NULL, NULL }
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(str, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
