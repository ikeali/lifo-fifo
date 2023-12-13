#include "monty.h"

/**
 * set_stack_mode - Sets the stack mode to lifo.
 */
static void set_stack_mode(void)
{
    bus.lifi = 0;
}

/**
 * f_stack - Prints the top.
 * @head: Stack head
 * @counter: Line number
 */
void f_stack(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    set_stack_mode();
}
