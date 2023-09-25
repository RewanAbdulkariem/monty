#include "monty.h"
/**
 * execute_instruction - Execute Monty ByteCode instructions
 * @stack: Pointer to the stack data structure
 * @instruction: The opcode to execute
 * @value: The argument associated with the opcode
 */
void execute_instruction(stack_t **stack, char *opcode, unsigned int line_number)
{
	int i;

	instruction_t instructions[] =
	{
		{"push", _push},
		{"pall", _pall},
		{"null", NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
