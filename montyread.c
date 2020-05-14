#include "monty.h"
montyfile monty = {NULL, NULL, 0};
/**
 * montyread - function that reads the monty file
 * @file: file to read
 */
void montyread(char *file)
{
	stack_t *mstack = NULL;
	unsigned int nline = 0;
	char line[1024];

	monty.file = fopen(file, "r");
	if (!monty.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		fgets(line, 1024, monty.file);
		nline++;
		if (feof(monty.file))
			break;
		if (strcmp(line, "\n") == 0)
			continue;

		monty.args = strdup(line);
		monty.args = strtok(monty.args, "\n");
		getmontylines(line, nline, &mstack);
		free(monty.args);
	}
	freestack(&mstack);
}
