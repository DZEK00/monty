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

/**
 * _pint - prints a value at the top of the stack
 *
 * @stack: stack to print from
 * @line_number: current line of file
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack
 * 
 * @stack: stack to remove from
 * @line_number: current line of file
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if ((*stack)->next)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(temp);
}

/**
 * _swap - swaps the top two elements of the stack
 * 
 * @stack: the stack to swap from
 * @line_number: current line of file
*/

void _swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *stack;

	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
