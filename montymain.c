#include "monty.h"
/**
 * main - main function for monty
 * @argc: number of args
 * @argv: file
 * Return: success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	montyread(argv[1]);
	exit(EXIT_SUCCESS);
}
