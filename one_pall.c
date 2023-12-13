#include "monty.h"

/**
 * f_pall - Print all elements in the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number (not used).
 * Return: No return value.
 */
	void f_pall(stack_t **head, unsigned int counter)
	{
	stack_t *current;

	(void)counter;

	if (*head == NULL)
	return;

	current = *head;

	while (current)
	{
	printf("%d\n", current->n);
	current = current->next;
	}
	}

