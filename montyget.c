#include "monty.h"
/**
 * getmontylines - function that get the arg of the file and execute it
 * @line: argument
 * @lnum: number of lines of the file
 * @stack: double linked list
 */
void getmontylines(char *line, unsigned int lnum, stack_t **stack)
{
	char *cmd;
	int i;
	instruction_t op[] = {
		{"push", mpush},
		{"pall", mpall},
		{NULL, NULL}
	};
	cmd = strtok(line, " \n\t\r");
	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(cmd, op[i].opcode) == 0)
		{
			op[i].f(stack, lnum);
			return;
		}
		if (strncmp(cmd, "#", 1) == 0)
			return;
	}
	freestack(stack);
	fprintf(stderr, "L%d: unknown instruction %s\n", lnum, cmd);
	exit(EXIT_FAILURE);
}
