#include "monty.h"

/**
 * instruction_push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_counter: value of new node
 * Return: nothing
 */

void instruction_push(stack_t **stack, unsigned int line_counter)
{
	stack_t *head = malloc(sizeof(stack_t));
	char *op, *endptr;
	int num, base = 10;
	long val;

	if (head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	op = strtok(NULL, DELIMITERS);
	if (op == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_counter);
		exit(EXIT_FAILURE);
	}

	val = strtol(op, &endptr, base);
	/*num = atoi(op);*/
	if (op == endptr || *endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_counter);
		exit(EXIT_FAILURE);
	}
	num = (int) val;
	head->n = num;
	head->prev = NULL;
	head->next = *stack;
	if (head->next != NULL)
		(head->next)->prev = head;
	*stack = head;
}

/**
 * instruction_pall - prints all values on the stack, starting from top
 * @stack: double pointer to the first node
 * @line_counter: value of new node
 * Return: nothing
 */

void instruction_pall(stack_t **stack, unsigned int line_counter)
{
	stack_t *head = *stack;
	unsigned int i = 0;

	(void)line_counter;
	if (head == NULL)
		return;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		++i;
		head = head->next;
	}
}

/**
 * instruction_pint - prints value at top of stack
 * @stack: double pointer to the first node
 * @line_counter: value of new node
 * Return: nothing
 */

void instruction_pint(stack_t **stack, unsigned int line_counter)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_counter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * instruction_pop - removes the top element of the stack
 * @stack: double pointer to the first node
 * @line_counter: line on the file containing the implemented instruction
 *
 * Return: nothing
 */

void instruction_pop(stack_t **stack, unsigned int line_counter)
{
	stack_t *head;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_counter);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	(*stack) = head->next;
	free(head);
}

/**
 * instruction_swap - swaps the top two elements of the stack.
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 *
 * Return: Nothing
 */

void instruction_swap(stack_t **stack, unsigned int line_counter)
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
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_counter);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	aux = head->n;
	head->n = head->next->n;
	head->next->n = aux;
}
