#include "monty.h"
/**
 * _rotl - Rotates the stack to the top.
 *
 * @stack: Pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second, *last
	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		second = (*stack)->next;

		last = *stack;
		while (last->next->next != NULL)
			last = last->next;

		second->prev = NULL;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		*stack = second;
	}
}
