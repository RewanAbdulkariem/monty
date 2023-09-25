#include "monty.h"
/**
 * main - Entry point for the Monty bytecode interpreter.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: EXIT_SUCCESS if the program
 * executes successfully, otherwise EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *mfile = NULL;
	char line[1024];
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	mfile = fopen(argv[1], "r");
	if (mfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), mfile) != NULL)
	{
		char *opcode, *value;


		opcode = strtok(line, " \t\n");
		value = strtok(NULL, " \t\n");
		if (opcode[0] == '#')
		{
			continue;
		}
		line_number++;
		if (opcode != NULL)
			execute_instruction(&stack, opcode, line_number, value);
	}
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->prev;
		free(temp);
	}
	fclose(mfile);
	return (0);
}
