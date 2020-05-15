#include "monty.h"
/**
 * mswap - function that swaps the first two values of the top
 * @stack: double linked list
 * @line_number: number of lines
 *
 */
void mswap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int a;
	int b;

	if (!tmp || !(tmp->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	(*stack)->n = b;
	(*stack)->next->n = a;
}
/**
 * mpchar - print the data of the head
 * @stack: double linked list
 * @line_number: number of lines
 */
void mpchar(stack_t **stack, unsigned int line_number)
{
	int letter;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	letter = (*stack)->n; /* data in the head of the stack */
	if (letter < 0 || letter > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(letter);
	putchar(10);
}
/**
 * mpstr - print the string data of the head
 * @stack: double linked list
 * @line_number: number of lines
 */
void mpstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	ptr = *stack;
	if ((*stack))
	{
		while (ptr->next && ptr->n != 0)
		{
			if (ptr->n > 32 && ptr->n < 127)
			{
				printf("%c", ptr->n);
			}
			ptr = ptr->next;
		}
		putchar(10);
	}
	else
	{
		putchar(10);
	}
}
