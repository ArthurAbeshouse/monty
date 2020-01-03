#include "monty.h"
/**
 * pop_listint - deletes the head node of a listint_t linked list,
 * and returns its contents
 *
 * @head: head of the list
 *
 * Return: contents of head
 */

void pop(stack_t **stack, unsigned int line_num)
{
  stack_t *next = NULL;

  if (stack == NULL || *stack == NULL)
    {
      printf("L%u: can't pop an empty stack\n", line_num);
      free_all(stack);
      exit(EXIT_FAILURE);
    }
  next = (*stack)->next;
  free(*stack);
  *stack = next;
  if (*stack == NULL)
    return;
  (*stack)->prev = NULL;
}
