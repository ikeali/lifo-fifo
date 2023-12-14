#include "monty.h"

/**
 * push_node - add node to the stack
 * @stack: stack head
 * @line_number: line number
 * Return: no return
 */
void push_node(stack_t **stack, unsigned int line_number)
{
	int num, i = 0, error_flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				error_flag = 1;
		}
		if (error_flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack_nodes(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack_nodes(*stack);
		exit(EXIT_FAILURE);
	}

	num = atoi(bus.arg);

	if (bus.lifi == 0)
		 add_node_to_head(stack, num);
	else
		enqueue_node(stack, num);
}

