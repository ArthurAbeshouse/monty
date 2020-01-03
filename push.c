#include "monty.h"

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
 */
void _stack(stack_t **stack, stack_t *new)
{
	new->n = atoi(arg_holder.arg);
	if (!(*stack))
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
 */
void _queue(stack_t **stack, stack_t *new)
{
	stack_t *holder;

	new->n = atoi(arg_holder.arg);
	new->next = NULL;
	if (!(*stack))
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

void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	if (!(isnum(arg_holder.arg)))
	{
		printf("L%u: usage: push integer\n", line_num);
		free(stack);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Error: malloc failed\n");
		free(stack);
		exit(EXIT_FAILURE);
	}
	if (arg_holder.SQ)
		_stack(stack, new);
	else
		_queue(stack, new);
}
