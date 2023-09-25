#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n += (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _sub - adds the top two elements of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n -= (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _div - adds the top two elements of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n /= (*stack)->n;
	_pop(stack, line_number);
}
