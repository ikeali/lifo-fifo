#include "monty.h"

/**
 * get_opcode_function - Finds the corresponding function for a given opcode.
 * @opcode: The opcode to search for
 * Return: The corresponding function or NULL if not found
 */
static void (*get_opcode_function(const char *opcode))(stack_t **, unsigned int)
{
    instruction_t opst[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {"sub", f_sub},
        {"div", f_div},
        {"mul", f_mul},
        {"mod", f_mod},
        {"pchar", f_pchar},
        {"pstr", f_pstr},
        {"rotl", f_rotl},
        {"rotr", f_rotr},
        {"queue", f_queue},
        {"stack", f_stack},
        {NULL, NULL}
    };

    for (size_t i = 0; opst[i].opcode; i++)
    {
        if (strcmp(opcode, opst[i].opcode) == 0)
        {
            return opst[i].f;
        }
    }

    return NULL;
}

/**
 * execute - Executes the opcode.
 * @content: Line content
 * @stack: Head linked list - stack
 * @counter: Line counter
 * @file: Pointer to monty file
 * Return: 0 on success, 1 on failure
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    char *op;
    void (*op_function)(stack_t **, unsigned int);

    op = strtok(content, " \n\t");
    if (op && op[0] == '#')
        return 0;

    bus.arg = strtok(NULL, " \n\t");

    op_function = get_opcode_function(op);

    if (op && !op_function)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    if (op_function)
        op_function(stack, counter);

    return 0;
}

