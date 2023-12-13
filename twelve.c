#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @head: Head of the stack
 */
void free_stack(stack_t *head)
{
    stack_t *current = head;

    while (current)
    {
        stack_t *next_node = current->next;
        free(current);
        current = next_node;
    }
}

