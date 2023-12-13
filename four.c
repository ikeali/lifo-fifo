#include "monty.h"

/**
 * print_string - Prints the string starting at the top of the stack.
 * @head: Stack head
 */
static void print_string(stack_t *head)
{
    stack_t *current = head;

    while (current && current->n > 0 && current->n <= 127)
    {
        printf("%c", current->n);
        current = current->next;
    }
}

/**
 * pf - Prints the string starting at the top of the stack.
 * @head: Stack head
 * @counter: Line number
 */
void pf(stack_t **head, unsigned int counter)
{
    (void)counter;

    print_string(*head);
    printf("\n");
}

