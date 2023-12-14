#include "monty.h"

/**
 * add_node_to_head - adds a node to the head of the stack
 * @stack: head of the stack
 * @value: new value
 * Return: no return
 */
void add_node_to_head(stack_t **stack, int value)
{
	stack_t *new_node, *current_node;

	current_node = *stack;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	if (current_node)
		current_node->prev = new_node;

	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
