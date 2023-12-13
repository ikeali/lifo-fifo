#include "monty.h"

/**
 * rotate_to_bottom - Rotates the stack to the bottom.
 * @head: Stack head
 */
static void rotate_to_bottom(stack_t **head)
{
    stack_t *copy = *head;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    while (copy->next)
    {
        copy = copy->next;
    }

    copy->next = *head;
    copy->prev->next = NULL;
    copy->prev = NULL;
    (*head)->prev = copy;
    (*head) = copy;
}

/**
 * rotate - Rotates the stack to the bottom.
 * @head: Stack head
 * @counter: Line number
 */
void rotate(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    rotate_to_bottom(head);
}

