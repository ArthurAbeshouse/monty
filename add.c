#include "monty.h"
/**
 * add - adding first two elements
 * @stack: input stack address
 * @line_num: current line number
 */

void add(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	sum = current->n + current->next->n;
	current->next->n = sum;

	*stack = current->next;

	free(current);
}
