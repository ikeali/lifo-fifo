#include "monty.h"

/**
 * print_top_element - Prints the top element of the stack.
 * @head: Stack head
 * @counter: Line number
 */
static void print_top_element(stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*head)->n);
}

/**
 * f_pint - Prints the top element of the stack.
 * @head: Stack head
 * @counter: Line number
 */
void f_pint(stack_t **head, unsigned int counter)
{
    print_top_element(head, counter);
}

