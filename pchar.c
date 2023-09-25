#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int asciiCode;
	char asciiChar;

	if (*stack == NULL)
	{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}

	asciiCode = (*stack)->n;
	if (asciiCode < 0 || asciiCode > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	asciiChar = (char)asciiCode;
	putchar(asciiChar);
	putchar('\n');
}
