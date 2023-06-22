#include "monty.h"

/**
 * get_opcodes - get the function for a corresponding command
 * 
 * @cmd: command to check
 *
 * Return: Always 0
 */

int get_opcodes(char *cmd)
{
	unsigned int i = 0;

	instruction_t funcs[] = {
		{"push", _push},
        {"pall", _pall},
		{NULL, NULL}
	};

    while (funcs[i].opcode && cmd)
	{
		if (strcmp(funcs[i].opcode, cmd) == 0)
		{
			funcs[i].f(&vars.head, vars.line_num);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
	    vars.line_num, cmd);
	exit(EXIT_FAILURE);
}
