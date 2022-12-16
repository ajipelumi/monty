#include "monty.h"

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void postMain(void) __attribute__((destructor));
FILE *file;
char *curLine = NULL;
int fileFlag = 0;

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
	stack_t *stack = NULL;
	ssize_t ret = 0;
	int i = 0;
	unsigned int line_number = 0;
	size_t bytes = 256;
	char *cmd;
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"nop", nop}, {"add", add}, {"sub", sub},
		{"div", divi}, {NULL, NULL}
		};

	curLine = malloc(sizeof(char) * bytes);
	/* check if right arguments was passed and open file */
	initArgs(argc, argv);

	/* parsing through file line by line... */
	while (1) /* loop until eof is encountered */
	{
		line_number++;

		ret = getline(&curLine, &bytes, file);
		/* Add if statement to check for memory error */
		if (ret == 0)
			continue; /* empty line */
		else if (ret == -1)
			break; /* EOF */

		_strchr(curLine, '\n', ' '); /* replace \n with ' ' */
		cmd = strtok(curLine, " ");
		if (cmd == NULL) /* empty line */
			continue;

		i = 0;
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(instructions[i].opcode, cmd) == 0) /*opcode found */
			{
				instructions[i].f(&stack, line_number);
				break;
			}

			i++;
			if (instructions[i].opcode == NULL)
			{
				dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, cmd);
				stackFree(&stack);
				exit(EXIT_FAILURE);
			}
		}

	}

	stackFree(&stack);

	return (EXIT_SUCCESS);
}

/**
 * postMain - free curLine and close file
 */

void postMain(void)
{
	free(curLine);
	if (fileFlag == 1)
		fclose(file);
}
