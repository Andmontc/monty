#include "monty.h"
/**
 * getmontylines - function that get the arg of the file and execute it
 * @line: argument
 * @lnum: number of lines of the file
 * @stack: double linked list
 * Return: sucess
 */
int getmontylines(char *line, unsigned int lnum, stack_t **stack)
{
	int i;
	instruction_t op[] = {
		{"push", mpush}, {"swap", mswap},
		{"pall", mpall}, {"add", madd},
		{"pint", mpint},
		{"pop", mpop},
		{"nop", mnop},
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(line, op[i].opcode) == 0)
		{
			op[i].f(stack, lnum);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", lnum, line);
	exit(EXIT_FAILURE);
}
