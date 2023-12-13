#include "monty.h"

/**
 * is_valid_integer - Checks if a string represents a valid integer.
 * @str: String to check
 * Return: 1 if valid integer, 0 otherwise
 */
static int is_valid_integer(const char *str)
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
 * push_node_to_stack - Adds a node to the stack.
 * @head: Stack head
 * @n: Value to push
 * @counter: Line number
 */
static void push_node_to_stack(stack_t **head, int n, unsigned int counter)
{
    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}

/**
 * f_push - Adds a node to the stack.
 * @head: Stack head
 * @counter: Line number
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n;

    if (!bus.arg || !is_valid_integer(bus.arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    n = atoi(bus.arg);
    push_node_to_stack(head, n, counter);
}

