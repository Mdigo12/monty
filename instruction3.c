#include "monty.h"

/**
 * instruction_mod - Computes the rest of the division
 *	of the second top element by the top element of the stack.
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 * Return: Nothing
 */

void instruction_mod(stack_t **stack, unsigned int line_counter)
{
	stack_t *head;
	int len = 0, aux;

	head = *stack;
	while (head)
	{
		if (head->n == 0)
		{
			printf("L%u: division by zero\n", line_counter);
			exit(EXIT_FAILURE);
		}
		head = head->next;
		len++;
	}

	if (len < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_counter);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	aux = head->next->n % head->n;
	head->next->n = aux;
	*stack = head->next;
	free(head);
}
