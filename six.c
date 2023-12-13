#include "monty.h"

/**
 * add_top_elements - Adds the top two elements of the stack.
 * @head: Stack head
 */
static void add_top_elements(stack_t **head)
{
    stack_t *current = *head;
    int sum;

    sum = current->n + current->next->n;
    current->next->n = sum;
    *head = current->next;
    free(current);
}

/**
 * f_add - Adds the top two elements of the stack.
 * @head: Stack head
 * @counter: Line number
 */
void f_add(stack_t **head, unsigned int counter)
{
    stack_t *current = *head;
    int len = stack_len(current);

    if (len < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    add_top_elements(head);
}

