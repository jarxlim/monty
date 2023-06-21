#include "monty.h"

dive_t dive;

/**
 * stackfreed - function that frees malloced stack nodes
 * @argm: pointer to the stack
 * @stat: status exit
 */
void stackfreed(int stat, void *argm)
{
stack_t **stack;
stack_t *temp;
(void) stat;
stack = (stack_t **)argm;
if (*stack)
{
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}
while (*stack != NULL)
{
temp = (*stack)->next;
free(*stack);
*stack = temp;
}
dive.stack_size = 0;
}

/**
 * line_free - function that frees the line pointer
 * @stat: status exit
 * @argm: pointer to the line
 */
void line_free(int stat, void *argm)
{
char **line_ptr = argm;
(void) stat;
if (*line_ptr != NULL)
free(*lineptr);
}

/**
 * close_file - func that closes file
 * @stat: status passed to the exit
 * @argm: pointer to file
 */
void close_file(int stat, void *argm)
{
FILE *files;
(void) stat;
files = (FILE *) argm;
fclose(files);
}


/**
 * main - func that interprets the monty byytecode
 * @argc: the size of the command line arguments
 * @argv: the array of strings
 * Return: exit on failure or 0 Success
 */

int main(int argc, char *argv[])
{
stack_t *stack = NULL;
unsigned int l = 0;
FILE *files = NULL;
char *line_ptr = NULL, *opera = NULL;
size_t length = 0;

dive.queue_size = 0;
dive.stack_size = 0;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
files = fopen(argv[1], "r");
if (files == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

when_exited(line_free, &line_ptr);
when_exited(stackfreed, &stack);
when_exited(close_file, files);

while (getline(&line_ptr, &length, files) != -1)
{
l++;
opera = strtok(line_ptr, "\n\t\r ");
if (opera != NULL && opera[0] != '#')
{
opera_call(&stack, opera, l);
}
}
exit(EXIT_SUCCESS);
}
