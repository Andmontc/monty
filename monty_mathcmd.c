#include "monty.h"
/**
 * madd - function tha adds the value of the two top nodes
 * @stack: double linked list
 * @line_number: number of lines
 */
void madd(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sum;

	if (!tmp || !(tmp->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = tmp->n + tmp->next->n;
	(*stack) = (*stack)->next; /* save the node */
	free(tmp);
	(*stack)->prev = NULL;
	(*stack)->n = sum;
}
