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

	if (*stack != NULL && (*stack)->prev != NULL)
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
/**
 * _rotr - Rotates the stack to the bottom.
 *
 * @stack: Pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *tmp;
	(void)line_number;

	if (*stack != NULL && (*stack)->prev != NULL)
	{
		last = *stack;
		while (last->prev != NULL)
			last = last->prev;
		
		tmp = last;
		last = last->next;
		last->prev = NULL;

		tmp->next = NULL;
		tmp->prev = *stack;
		
		(*stack)->next = tmp;
		*stack = tmp;
	}
}
