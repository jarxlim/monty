#ifndef __MONTY_H__
#define __MONTY_H__

#define VAL_DATA		0
#define MINI_ARG		2

#define ERROR_INV	100
#define ERROR_MALLOC	101
#define ERR_INVLD_PARM	102
#define M_STACK		300
#define M_QUEUE		301
#define ERROR_USE		200
#define ERROR_PUSH		201
#define ERROR_PINT		202
#define ERROR_POP			203
#define ERROR_SWAP		204
#define ERROR_ADD			205
#define ERROR_SUB			206
#define ERROR_DIV			207
#define ERROR_ZDIV	208
#define ERROR_MUL			209
#define ERROR_MOD			210
#define ERROR_PCHARF		211
#define ERROR_PCHARE		212

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int num_line);
} instruction_t;

extern stack_t *head;

int exec_handler(char *_code, char *data, unsigned int line, int _stats);
void error_handler(int err, char *opcode, unsigned int line, char *line_reader);
void malloc_handler(int err, char *opcode, unsigned int line);
void more_handlers(int err, unsigned int line);
void (*selectors(char *str))(stack_t **, unsigned int);
void op_handlers(int err, unsigned int line);
void push(stack_t **stack, unsigned int data);
void permission_reader(char *fd);
unsigned int stack_size(stack_t *stack);
int data_checker(char *param);
void args_checker(int agc);
int digits_checker(char *s);
void stackfreed(void);
void divide(stack_t **stack, unsigned int num_line);
void pchar(stack_t **stack, unsigned int num_line);
void swap(stack_t **stack, unsigned int num_line);
void push_queue(stack_t **stack, unsigned int data);
void pall(stack_t **stack, unsigned int num_line);
void pint(stack_t **stack, unsigned int num_line);
void pstr(stack_t **stack, unsigned int num_line);
void rotl(stack_t **stack, unsigned int num_line);
void rotr(stack_t **stack, unsigned int num_line);
void pop(stack_t **stack, unsigned int num_line);
void add(stack_t **stack, unsigned int num_line);
void nop(stack_t **stack, unsigned int num_line);
void sub(stack_t **stack, unsigned int num_line);
void mul(stack_t **stack, unsigned int num_line);
void mod(stack_t **stack, unsigned int num_line);
FILE *file_opener(char *fd);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif 
