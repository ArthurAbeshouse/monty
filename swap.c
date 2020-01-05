#include "monty.h"
/**
 * swap - swap top 2 numbers
 * @stack: input stack address
 * @line_num: current line number
 */

void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int holder = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	holder = current->n;

	current->n = holder;
	current->n = current->next->n;
	current->next->n = holder;
}
