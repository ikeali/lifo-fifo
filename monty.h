#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct bus_s
{
    char *arg;
    FILE *file;
    char *content;
    int lifi;  // You need to define the purpose of this field
} bus_t;

/* Global structure for bus */
extern bus_t bus;

/* Function prototypes */
void f_push(stack_t **head, unsigned int counter);
int is_valid_integer(const char *str);
void handle_failure(stack_t *head);
void f_pall(stack_t **head, unsigned int counter);
void add_node_to_stack(stack_t **head, int n);
void add_node_to_queue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void free_stack(stack_t *head);
int main(int argc, char *argv[]);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
#endif /* MONTY_H */

