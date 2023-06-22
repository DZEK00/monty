#define _GNU_SOURCE
#include "monty.h"

global_variables vars;

/**
 * main - runs the monty code interpreter
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char *buffer = NULL, *token = NULL;
	size_t buff_len = 0;
	int  line_size;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	vars.value = NULL;
	vars.head = NULL;
	vars.line_num = 0;
	vars.mode = 0;

	line_size = getline(&buffer, &buff_len, file);
	while (line_size >= 0)
	{
		vars.line_num++;
		token = strtok(buffer, " \t\n");
		if (token && token[0] != '#')
		{
			vars.value = strtok(NULL, " \t\n");
			get_opcodes(token);
		}
		line_size = getline(&buffer, &buff_len, file);
	}
	free(buffer);
	buffer = NULL;
	fclose(file);
	free_stack_t(vars.head);
	return (0);
}
