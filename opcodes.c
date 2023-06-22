#include "monty.h"

/**
 * _push - pushes an element to the stack
 * 
 * @stack: stack to add onto
 * @line_number: current line of file
 */

void _push(stack_t **stack, unsigned int line_number)
{
	if (vars.value && is_num(vars.value))
	{
		if (vars.mode == 0)
			addnode(stack, atoi(vars.value));
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pall - print all values in a stack
 * @stack: stack to print
 * @line_number: current line of file
 */

void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;

	while (stack && temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
