#include "monty.h"

/**
 * set_queue_mode - sets the queue mode
 * @stack: stack head
 * @line_number: line number
 * Return: no return
 */
void set_queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifi = 1;
}

/**
 * enqueue_node - adds a node to the tail of the stack
 * @value: new value
 * @stack: stack head
 * Return: no return
 */
void enqueue_node(stack_t **stack, int value)
{
	stack_t *new_node, *current_node;

	current_node = *stack;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = NULL;

	if (current_node)
	{
		while (current_node->next)
			current_node = current_node->next;
	}

	if (!current_node)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current_node->next = new_node;
		new_node->prev = current_node;
	}
}

