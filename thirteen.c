#include "monty.h"

/**
 * get_stack_length - Computes the length of the stack.
 * @head: Stack head
 * Return: Length of the stack
 */
static int get_stack_length(stack_t *head)
{
    int len = 0;
    stack_t *current = head;

    while (current)
    {
        current = current->next;
        len++;
    }

    return len;
}

/**
 * multiply_top_elements - Multiplies the top two elements of the stack.
 * @head: Stack head
 * @counter: Line number
 */
static void multiply_top_elements(stack_t **head, unsigned int counter)
{
    stack_t *top = *head;

    if (top->n == 0)
    {
        fprintf(stderr, "L%d: multiplication by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    top->next->n *= top->n;
    *head = top->next;
    free(top);
}

/**
 * f_mul - Multiplies the top two elements of the stack.
 * @head: Stack head
 * @counter: Line number
 */
void f_mul(stack_t **head, unsigned int counter)
{
    int len = get_stack_length(*head);

    if (len < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    multiply_top_elements(head, counter);
}

