#include "monty.h"

/**
 * create_new_node - Creates a new node with the given value.
 * @n: Value for the new node
 * @prev: Previous node
 * @next: Next node
 * Return: Pointer to the new node
 */
static stack_t *create_new_node(int n, stack_t *prev, stack_t *next)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory for new node\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = prev;
    new_node->next = next;

    return new_node;
}

/**
 * add_node_to_head - Adds a node to the head of the stack.
 * @head: Head of the stack
 * @n: New value
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node = create_new_node(n, NULL, *head);

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

