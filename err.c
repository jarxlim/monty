#include "monty.h"

/**
  * error_handler - Handle errors
  * @err: error specifier.
  * @opcode: operation code.
  * @line: line error occurred.
  * @line_reader: reserved error line buffer
  * Return: Nothing
  */

void error_handler(int err, char *opcode, unsigned int line, char *line_reader)
{
	if (err >= 100 && err < 200)
		malloc_handler(err, opcode, line);
	else if (err >= 200 && err <= 210)
		op_handlers(err, line);
	else if (err >= 211 && err <= 220)
		more_handlers(err, line);
	else
		return;

	stackfreed();

	if (line_reader)
		free(line_reader);

	exit(EXIT_FAILURE);
}

/**
  * malloc_handler - Handles errors for mallocs
  * @err: error specifier
  * @opcode: operation code.
  * @line: The line of error
  * Return: Nothing
  */

void malloc_handler(int err, char *opcode, unsigned int line)
{
	switch (err)
	{
		case ERROR_INV:
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			break;
		case ERROR_MALLOC:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}

/**
  * op_handlers - Handles errors for opcode
  * @err: code specifier.
  * @line: The line of error
  * Return: Nothing
  */

void op_handlers(int err, unsigned int line)
{
	switch (err)
	{
		case ERROR_USE:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case ERROR_PUSH:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		case ERROR_PINT:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			break;
		case ERROR_POP:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			break;
		case ERROR_SWAP:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line);
			break;
		case ERROR_ADD:
			fprintf(stderr, "L%d: can't add, stack too short\n", line);
			break;
		case ERROR_SUB:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line);
			break;
		case ERROR_DIV:
			fprintf(stderr, "L%d: can't div, stack too short\n", line);
			break;
		case ERROR_ZDIV:
			fprintf(stderr, "L%d: division by zero\n", line);
			break;
		case ERROR_MUL:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line);
			break;
		case ERROR_MOD:
			fprintf(stderr, "L%d: can't mod, stack too short\n", line);
			break;
		default:
			break;
	}
}

/**
  * more_handlers - Handles errors pchar.
  * @err: Code specifier.
  * @line: the line of erro
  * Return: Nothing
  */
void more_handlers(int err, unsigned int line)
{
	switch (err)
	{
		case ERROR_PCHARF:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
			break;
		case ERROR_PCHARE:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
			break;
		default:
			break;
	}
}
