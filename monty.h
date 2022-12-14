#ifndef MONTY_H
#define MONTY_H

/*Header files to be included*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

/*new line, space, tab, carriage return as delimiters*/
#define DELIMITERS "\n \t\r$"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 *	for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 *	for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_s - globally useful variables, all rolled into one
 * @top: double pointer to top of stack
 * @ops: double pointer to an instruction struct
 */

typedef struct glob_s
{
	stack_t **top;
	instruction_t **ops;
} glob_t;

extern glob_t glob;

/* monty.c */
void stack_init(stack_t **head);
void free_all(void);

/*to open and read the file and tokenize the contents */
int process_file(char *filename, stack_t **stack_top);
void choose_op(char *op, stack_t **stack, unsigned int line_counter);

/*instruction1.c*/
void instruction_push(stack_t **stack, unsigned int line_counter);
void instruction_pall(stack_t **stack, unsigned int line_counter);
void instruction_pint(stack_t **stack, unsigned int line_counter);
void instruction_pop(stack_t **stack, unsigned int line_counter);
void instruction_swap(stack_t **stack, unsigned int line_counter);

/*instruction2.c*/
void instruction_add(stack_t **stack, unsigned int line_counter);
void instruction_nop(stack_t **stack, unsigned int line_counter);
void instruction_sub(stack_t **stack, unsigned int line_counter);
void instruction_div(stack_t **stack, unsigned int line_counter);
void instruction_mul(stack_t **stack, unsigned int line_counter);

/*instruction3.c*/
void instruction_mod(stack_t **stack, unsigned int line_counter);
void instruction_pchar(stack_t **stack, unsigned int line_counter);
void instruction_pstr(stack_t **stack, unsigned int line_counter);
void instruction_rotl(stack_t **stack, unsigned int line_counter);
void instruction_rotr(stack_t **stack, unsigned int line_counter);

/*instruction4.c*/
void instruction_queue(stack_t **head, unsigned int counter);
void instruction_stack(stack_t **head, unsigned int counter);
void addqueue(stack_t **head, int n);

#endif /*MONTY_H*/
