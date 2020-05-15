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

	montyfile = fopen(file, "r"); /*open file*/
	if (!montyfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while ((mread = getline(&line, &len, montyfile)) != -1)
	{
		nline++; /*number of lines in the cycle */
		margs = strtok(line, DELIM); /*tokenization of the line */
		if (margs == NULL || strncmp(margs, "#", 1) == 0) /*comment and blank*/
			continue;
		getmontylines(margs, nline, &mstack);
	}
	freestack(mstack, line, montyfile);
}
