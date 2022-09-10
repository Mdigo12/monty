#include "monty.h"

/**
 * instruction_add - adds the top two elements of the stack.
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 *
 * Return: Nothing
 */

void instruction_add(stack_t **stack, unsigned int line_counter)
{
	stack_t *head;
	int len = 0, aux;

	head = *stack;
	while (head)
	{
		head = head->next;
		len++;
	}

	if (len < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_counter);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	aux = head->n + head->next->n;
	head->next->n = aux;
	*stack = head->next;
	free(head);
}

/**
 * instruction_nop - Does nothing
 * @stack: double pointer to the top element on the stack
 * @line_counter: line of the instruction on the file
 *
 * Return: Nothing
 */

void instruction_nop(stack_t **stack, unsigned int line_counter)
{
	(void)stack;
	(void)line_counter;
}
