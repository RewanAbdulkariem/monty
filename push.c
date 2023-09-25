#include "monty.h"
extern char *value;
/**
 * _push - Pushes an element onto the stack.
 *
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int num = 0;

	if (value == NULL || !is_integer(value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(value);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->next = new_node;
		new_node->prev = *stack;
		*stack = new_node;
	}
	else
		*stack = new_node;
}
/**
 * is_integer - Checks if a string represents a valid integer.
 * @str: The string to check.
 *
 * Return: 1 if @str is a valid integer, 0 otherwise.
 */
int is_integer(char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	if (str == NULL || *str == '\0')
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}
