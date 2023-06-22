#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#define STACKS 0
#define QUEUES 1

/**
 * struct dive_s - a struct contains main variables
 * @queue_size: flag 0: stack, 1: queue
 * @stack_size: length of the stack
 */
typedef struct dive_s
{
int queue_size;
size_t stack_size;
} dive_t;

/* global flag contains queue and stack length */
extern dive_t dive;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *node_added(stack_t **, const int);
void stackfreed(int, void *);
void line_free(int, void *);
void close_file(int, void *);
void opera_call(stack_t **, char *, unsigned int);

void get_push(stack_t **, unsigned int);
void get_printall(stack_t **, unsigned int);
void get_printtop(stack_t **stack, unsigned int);
void get_pop(stack_t **stack, unsigned int);
void get_swap(stack_t **stack, unsigned int);
void get_add(stack_t **stack, unsigned int);
void get_nop(stack_t **stack, unsigned int);
void get_sub(stack_t **stack, unsigned int);
void get_div(stack_t **stack, unsigned int);
void get_mul(stack_t **stack, unsigned int);
void get_mod(stack_t **stack, unsigned int);
void get_char(stack_t **stack, unsigned int);
void get_str(stack_t **stack, unsigned int);
void get_rotl(stack_t **stack, unsigned int);
void get_rotr(stack_t **stack, unsigned int);

int digit_check(char *s);
void queue_setter(stack_t **stack, unsigned int);
void stack_setter(stack_t **stack, unsigned int);

#endif
