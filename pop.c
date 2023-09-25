#include "monty.h"
/**
 * _pop - removes the top element of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->prev == NULL)
	{
		*stack = NULL;
	}
	else
	{
		(*stack)->prev->next = NULL;
		*stack = (*stack)->prev;
	}
	free(tmp);
}
