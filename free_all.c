#include "monty.h"
/**
 * free_all - free the stack and the str input
 * @head: input list pointer
 */

void free_all(stack_t **head)
{
	stack_t *current;

	if (head == NULL)
		return;
	free(arg_holder.input_str);
	while (*head != NULL)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}
}
