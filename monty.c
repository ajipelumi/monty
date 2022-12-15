#include "monty.h"

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void initArgs(int argc, char *argv[]);
FILE *file;
char *curLine = NULL;

/**
 * main - entry point for monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0: interpreted successfully
 * 1: coudn't interpret file
 */
int main(int argc, char *argv[])
{
	stack_t **stack = NULL;
	ssize_t ret = 0;
	int i = 0;
	unsigned int line_number = 0;
	size_t bytes = 0;
	char *cmd;
	instruction_t instructions[] = {
		{"push", push}, {"pint", pint}, {"pop", pop},
		{NULL, NULL}};

	/* check if right arguments was passed and open file */
	initArgs(argc, argv);

	/* parsing through file line by line... */
	while (1) /* loop until eof is encountered */
	{
		line_number++;
		ret = getline(&curLine, &bytes, file);

		/* Add if statement to check for memory error */
		if (ret == 0)
			continue;/* empty line */
		else if (ret == -1)
			break;/* EOF */

		_strchr(curLine, '\n', ' '); /* replace \n with ' ' */
		cmd = strtok(curLine, " ");
		if (cmd == NULL)
		{/*empty line*/
			free(curLine);
			curLine = NULL;
			continue;
		}

		while (instructions[i].opcode != NULL)
		{
			if (strcmp(instructions[i].opcode, cmd) == 0)/*opcode found */
			{
				instructions[i].f(stack, line_number);
				break;
			}

			i++;
			if (instructions[i].opcode == NULL)
			{
				dprintf(STDERR_FILENO, "%u: unknown instruction %s\n", line_number, cmd);
				exit(EXIT_FAILURE);
			}
		}

	}

	fclose(file); /* close file before exiting */

	return (EXIT_SUCCESS);
}

/**
 * initArgs - initialize arguments
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: void
 */

void initArgs(int argc, char *argv[])
{

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}
