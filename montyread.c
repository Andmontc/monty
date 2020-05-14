#include "monty.h"
/**
 * montyread - function that reads the monty file
 * @file: file to read
 */
void montyread(char *file)
{
	FILE *montyfile;
	stack_t *mstack = NULL;
	unsigned int nline = 0;
	char *margs;
	char *line = NULL;
	size_t len = 0;
	ssize_t mread;

	montyfile = fopen(file, "r");
	if (!montyfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while ((mread = getline(&line, &len, montyfile)) != -1)
	{
		nline++;
		margs = strtok(line, DELIM);
		if (margs == NULL || strncmp(margs, "#", 1) == 0)
			continue;
		getmontylines(margs, nline, &mstack);
	}
	freestack(mstack, line, montyfile);
}
