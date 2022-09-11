#define _GNU_SOURCE
#include "monty.h"

/**
 * process_file - process the whole monty file
 * @filename: str name of monty opcode file
 * @stack: double pointer to top of stack data struct
 *
 * Return: return an error code or success
 */
int process_file(char *filename, stack_t **stack)
{
	FILE *fp;
	size_t len;
	ssize_t read;
	char *line = NULL;
	char *op;
	unsigned int line_counter = 0;

	/*check if file exist*/
	if (!filename)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	/*free memory after program has terminated*/
	atexit(free_all);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		/*tokenize the commands per line*/
		op = strtok(line, DELIMITERS);
		line_counter++;
		if (op)
			choose_op(op, stack, line_counter);
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
