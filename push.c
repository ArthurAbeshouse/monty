#include "monty.h"
/**
 * isnum - check if string is a number
 * @str: string input
 * Return: 0 if false 1 if true
 */

int isnum(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * _stack - LIFO data type
 * @stack: stack of the memory
 * @new: new stack to add
 */
void _stack(stack_t **stack, stack_t *new)
{
	new->n = atoi(arg_holder.arg);
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		new->prev = NULL;
		*stack = new;
	}
}

/**
 * _queue - FIFO data type
 * @stack: stack of the memory
 * @new: new stack to add
 */
void _queue(stack_t **stack, stack_t *new)
{
	stack_t *holder;

	new->n = atoi(arg_holder.arg);
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		holder = *stack;
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = new;
		new->prev = holder;
	}
}

/**
 * push - push integers to memory
 * @stack: stack of memory
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!(isnum(arg_holder.arg)))
	{
		printf("L%u: usage: push integer\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	if (arg_holder.SQ)
		_stack(stack, new_node);
	else
		_queue(stack, new_node);
}
