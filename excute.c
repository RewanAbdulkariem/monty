#include "monty.h"
/**
 * execute_instruction - Execute Monty ByteCode instructions
 * @stack: Pointer to the stack data structure
 * @opcode: The opcode to execute
 * @line_number: line number of opcode
 * @value: to pass to push
 */
void execute_instruction(stack_t **stack,
		char *opcode, unsigned int line_number, char *value)
{
	int i;

	instruction_t instructions[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr",_rotr},
		{"null", NULL}
	};

	for (i = 0; i < 14; i++)
	{
		if (strcmp("push", opcode) == 0)
		{
			_push(stack, line_number, value);
			return;
		}
		else if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
