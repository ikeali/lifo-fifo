#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n;

	if (!bus.arg || !is_valid_integer(bus.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		handle_failure(*head);
	}

	n = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node_to_stack(head, n);
	else
		add_node_to_queue(head, n);
}

/**
 * is_valid_integer - check if the string is a valid integer
 * @str: input string
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_integer(const char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
	}

	return 1;
}

/**
 * handle_failure - handle failure conditions and exit
 * @head: stack head
 */
void handle_failure(stack_t *head)
{
	fclose(bus.file);
	free(bus.content);
	free_stack(head);
	exit(EXIT_FAILURE);
}

