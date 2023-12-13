#include "monty.h"

/**
 * f_queue - Switch the mode to queue (lifo = 1).
 * @head: Pointer to the head of the stack.
 * @counter: Line number (not used).
 * Return: No return value.
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 1;
}

/**
 * add_node_to_queue - Add a new node to the tail of the stack.
 * @head: Pointer to the head of the stack.
 * @n: New value.
 * Return: No return value.
 */
void add_node_to_queue(stack_t **head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        stack_t *tail = *head;

        while (tail->next)
            tail = tail->next;

        tail->next = new_node;
        new_node->prev = tail;
    }
}

