#include "monty.h"
/**
 * _rotl - Rotates the stack to the top.
 *
 * @stack: Pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	stack_t *new;
	int tmp;

	if (*stack != NULL)
	{
		tmp = (*stack)->n;
		last = *stack;
		while (last->prev != NULL)
			last = last->prev;

		_pop(stack, line_number);
		new = malloc(sizeof(stack_t));
		new->n = tmp;
		new->next = last;
		last->prev = new; 
	}
}
