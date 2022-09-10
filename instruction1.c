#include "monty.h"

/**
 * instruction_push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_counter: value of new node
 * Return: nothing
 */

void instruction_push(stack_t **stack, unsigned int line_counter)
{
	stack_t* head = malloc(sizeof(stack_t));
	char* op;
	int num;

	if (head == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*Test*/
	/*printf("malloc allocated\n");*/

	op = strtok(NULL, DELIMITERS);
	if (op == NULL || stack == NULL)
	{
		printf("L%u: usage: push integer\n", line_counter);
		exit(EXIT_FAILURE);
	}

	num = atoi(op);
	/*test*/
	/*printf("Num from atoi is: %d\n", num);*/
	if (num == 0)
	{
		printf("L%d: usage: push integer\n", line_counter);
		exit(EXIT_FAILURE);
	}

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

void instruction_pall(stack_t** stack, unsigned int line_counter)
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
		printf("L%u: can't pint, stack empty\n", line_counter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}