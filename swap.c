#include "monty.h"
/**
 * _swap - swaps the top two elements of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;

	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = temp;
}
