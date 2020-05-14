#ifndef _MONTY_H
#define _MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

/* structs */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct montyfile - global struct for monty files
 * @file: monty file reading from
 * @args: lines
 * @mode: stack or queue mode (stack mode default)
 * Description: struct for the monty file to read
 */
typedef struct montyfile
{
	FILE *file;
	char *args;
	int mode;
} montyfile;

extern montyfile monty;

/* Functions */
/*--------------------*/
/* Main functions */
void montyread(char *file);
void getmontylines(char *line, unsigned int lnum, stack_t **stack);
/* Aux Functions */
void freestack(stack_t **stack);
int checkint(char *str);
/* commands functions */
void mpush(stack_t **stack, unsigned int num);
void mpall(stack_t **stack, unsigned int num);

#endif
