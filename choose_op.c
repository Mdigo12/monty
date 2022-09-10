#include "monty.h"

/**
 * choose_op - based on tokens from single line, decide what function to call
 * @stack: double pointer to head of stack data structure
 * @op: operator, aka token[0] from getline
 * @line_counter: line in byte-code file being processed, zero indexed
 *
 * Return: int for mysterious purposes
 */

void choose_op(char *op, stack_t **stack, unsigned int line_counter)
{
	int i;

	instruction_t all_ops[] = {
		{"push", instruction_push},
		{"pall", instruction_pall},
		{"pint", instruction_pint},
		{"pop", instruction_pop},
		{"swap", instruction_swap},
		{"add", instruction_add},
		{"nop", instruction_nop},
		{NULL, NULL}
	};

	for (i = 0; all_ops[i].opcode; i++)
	{
		if (strcmp(op, all_ops[i].opcode) == 0)
		{
			/*Test*/
			/*printf("option [%i] %s picked\n",i, all_ops[i].opcode);*/
			all_ops[i].f(stack, line_counter);
			return;
		}
	}

	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", line_counter, op);
		exit(EXIT_FAILURE);
	}
}
