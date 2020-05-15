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
/**
 * msub - function tha substract the value of the two top nodes
 * @stack: double linked list
 * @line_number: number of lines
 */
void msub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sub;

	if (!tmp || !(tmp->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = tmp->next->n - tmp->n;
	(*stack) = (*stack)->next; /* save the node */
	free(tmp);
	(*stack)->prev = NULL;
	(*stack)->n = sub;
}
/**
 *  * mdiv - function that divide the value of the two top nodes
 * @stack: double linked list
 * @line_number: number of lines
 */
void mdiv(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int div;

	if (!tmp || !(tmp->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = tmp->next->n / tmp->n;
	(*stack) = (*stack)->next; /* save the node */
	free(tmp);
	(*stack)->prev = NULL;
	(*stack)->n = div;
}
/**
 * mmul - function tha multiply the value of the two top nodes
 * @stack: double linked list
 * @line_number: number of lines
 */
void mmul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int mul;

	if (!tmp || !(tmp->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = tmp->next->n * tmp->n;
	(*stack) = (*stack)->next; /* save the node */
	free(tmp);
	(*stack)->prev = NULL;
	(*stack)->n = mul;
}
/**
 *  * mmod - function that module the value of the two top nodes
 * @stack: double linked list
 * @line_number: number of lines
 */
void mmod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int mod;

	if (!tmp || !(tmp->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = tmp->next->n % tmp->n;
	(*stack) = (*stack)->next; /* save the node */
	free(tmp);
	(*stack)->prev = NULL;
	(*stack)->n = mod;
}
