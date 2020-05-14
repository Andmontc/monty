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

	if (!tmp|| !(tmp->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	(*stack)->n = b;
	(*stack)->next->n = a;
}
