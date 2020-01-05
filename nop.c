#include "monty.h"
/**
 * nop - doesn’t do anything :)
 * @stack: input stack address
 * @line_num: current line number
 */

void nop(stack_t **stack, unsigned int line_num)
{
  int i = 1;
  (void)stack;
  (void)line_num;

  while (i >= 0)
    {
      i--;
      continue;
    }
}
