#include "monty.h"

/**
  * exec_handler - Manages the operationsr
  * @_code: The operation code.
  * @data: The data
  * @line: Line number
  * @_stats: Indicator
  *
  * Return: 0 if the operation was successful or errcode if its invalid.
  */

int exec_handler(char *_code, char *data, unsigned int line, int _stats)
{
	int stat_op = 0;
	void (*opcode_func)(stack_t **, unsigned int);

	if (strcmp(_code, "stack") == 0)
		return (M_STACK);
	else if (strcmp(_code, "queue") == 0)
		return (M_QUEUE);

	opcode_func = selectors(_code);
	if (opcode_func)
	{
		if (strcmp(_code, "push") == 0)
		{
			stat_op = data_checker(data);
			if (stat_op == ERROR_PUSH)
				return (ERROR_PUSH);

			if (_stats != 0 && _stats == M_QUEUE)
				opcode_func = selectors("push_queue");

			opcode_func(&head, atoi(data));
		}
		else
			opcode_func(&head, line);

		return (_stats);
	}

	return (ERROR_INV);
}
