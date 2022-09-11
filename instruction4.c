#include "monty.h"

/**
 * instruction_stack - top of the stack becomes the front of the stack
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 *
 * Return: Nothing
 */

void instruction_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
}
/**
 * instruction_queue - top of the stack becomes the front of the queue
 * @stack: double pointer to the top element of the stack
 * @line_counter: line on the file containing the implemented instruction
 *
 * Return: Nothing
 */

void instruction_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */

void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
