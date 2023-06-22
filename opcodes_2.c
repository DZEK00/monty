#include "monty.h"

/**
 * _add - adds the two top elements of the stack
 *
 * @stack: the stack to add from
 * @line_number: current line of file
*/

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int length = 0, temp;

	h = (*stack);
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	h = (*stack);
	temp = h->n + h->next->n;
	h->next->n = temp;
	(*stack) = h->next;
	free(h);
}
