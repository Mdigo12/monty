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
		fprintf(stderr, "L%u: can't add, stack too short\n", line_counter);
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

/**
 * instruction_sub - subtracts the top element
 *	from the second top element of the stack.
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 * Return: Nothing
 */

void instruction_sub(stack_t **stack, unsigned int line_counter)
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
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_counter);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	aux = head->next->n - head->n;
	head->next->n = aux;
	*stack = head->next;
	free(head);
}

/**
 * instruction_div - Divides the second top element of the stack
 *	by the top element of the stack
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 *
 * Return: Nothing
 */

void instruction_div(stack_t **stack, unsigned int line_counter)
{
	stack_t *head;
	int len = 0, aux;

	head = *stack;
	while (head)
	{
		if (head->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_counter);
			exit(EXIT_FAILURE);
		}
		head = head->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_counter);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	aux = head->next->n / head->n;
	head->next->n = aux;
	*stack = head->next;
	free(head);
}

/**
 * instruction_mul - Multiplies the second top element of the stack
 *	with the top element of the stack.
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 *
 * Return: Nothing
 */

void instruction_mul(stack_t **stack, unsigned int line_counter)
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
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_counter);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	aux = head->next->n * head->n;
	head->next->n = aux;
	*stack = head->next;
	free(head);
}
