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
			fprintf(stderr, "L%u: division by zero\n", line_counter);
			exit(EXIT_FAILURE);
		}
		head = head->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_counter);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	aux = head->next->n % head->n;
	head->next->n = aux;
	*stack = head->next;
	free(head);
}

/**
 * instruction_pchar - prints the char at the top of the stack.
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 * Return: Nothing
 */

void instruction_pchar(stack_t **stack, unsigned int line_counter)
{
	stack_t *h = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_counter);
		exit(EXIT_FAILURE);
	}

	if (h->n < 33 || h->n > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_counter);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * instruction_pstr - prints the string starting at the top of the stack.
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 * Return: Nothing
 */

void instruction_pstr(stack_t **stack, unsigned int line_counter)
{
	stack_t *h = *stack;

	(void)line_counter;
	while (h)
	{
		if (h->n == 48 || h->n < 33 || h->n > 126 || stack == NULL || *stack == NULL)
		{
			printf("\n");
			return;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * instruction_rotl - shuffles the top and the bottom elements.
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 * Return: Nothing
 */

void instruction_rotl(stack_t **stack, unsigned int line_counter)
{
	stack_t *tmp = *stack, *new_top;

	(void)line_counter;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	new_top = (*stack)->next;
	new_top->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = new_top;
}

/**
 * instruction_rotr - rotates the stack to the bottom.
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 * Return: Nothing
 */

void instruction_rotr(stack_t **stack, unsigned int line_counter)
{
	stack_t *tmp = *stack;

	(void)line_counter;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
