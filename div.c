#include "monty.h"
/**
 * _div - divide top 2 numbers
 * @stack: input stack address
 * @line_num: current line number
 */
void _div(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int total = 0;

	(void)line_num;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	total = current->next->n / current->n;

	*stack = current->next;

	free(current);

	(*stack)->n = total;
}
