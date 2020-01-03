#include "monty.h"

void swap(stack_t **stack, unsigned int line_num)
{
  stack_t *current = NULL;
  int holder = 0;

  if (!stack || !(*stack) || !(*stack)->next)
    {
      printf("L%d: can't swap, stack too short\n", line_num);
      free_all(stack);
      exit(EXIT_FAILURE);
    }
  current = *stack;
  holder = current->n;

  current->n = holder;
  current->n = current->next->n;
  current->next->n = holder;
}
