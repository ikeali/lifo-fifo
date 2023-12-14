#include "monty.h"

/**
 * print_stack - prints the stack
 * @stack: stack head
 * @line_number: unused
 * Return: no return
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;
	(void)line_number;

	current_node = *stack;

	if (current_node == NULL)
		return;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

