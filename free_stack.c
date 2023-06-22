#include "monty.h"

/**
 * free_stack_t - frees the memory being used by the stack
 * @head: head of the stack
 */

void free_stack_t(stack_t *head)
{
	stack_t *temp;

	temp = head;
    
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}