#include "monty.h"
/**
 * _pall - Prints all the values on the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d",current->n);
		current = current->prev;
	}
}
