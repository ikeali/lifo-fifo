#include "monty.h"

/**
 * print_stack - Prints the elements of the stack.
 * @head: Stack head
 */
static void print_stack(stack_t *head)
{
	stack_t *current = head;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * the_stack- Prints the stack.
 * @head: Stack head
 * @counter: Unused parameter
 */
void the_stack(stack_t **head, unsigned int counter)
{
	(void)counter;

	if (*head == NULL)
		return;

	print_stack(*head);
}

