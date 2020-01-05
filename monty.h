#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define DELIMS "\n \t"

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

/**
 * struct global_struct - struct for global variable
 * @arg: arguments
 * @input_str: input string
 * @SQ: check for stack or queue
 * @file: file descripter
 */
typedef struct global_struct
{
	char *arg;
	char *input_str;
	int SQ;
	FILE *file;
} global_var;

extern global_var arg_holder;
global_var arg_holder;

void pall(stack_t **stack, unsigned int line_num);
int isnum(char *str);
void push(stack_t **stack, unsigned int line_num);
int main(int argc, char **argv);
void parse(char *file);
void opcode(char *command, unsigned int line_num, stack_t **stack);
void add(stack_t **stack, unsigned int line_num);
void _stack(stack_t **stack, stack_t *new);
void _queue(stack_t **stack, stack_t *new);
void free_all(stack_t **head);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);
void rotl(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);

#endif
