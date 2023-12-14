#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
    char *current_line = NULL;
    FILE *monty_file;
    size_t line_size = 0;
    stack_t *stack_head = NULL;
    unsigned int line_counter = 1;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    monty_file = fopen(argv[1], "r");
    bus.file = monty_file;

    if (!monty_file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        current_line = malloc(line_size);
        if (current_line == NULL)
        {
            fprintf(stderr, "Error: Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        if (fgets(current_line, line_size, monty_file) == NULL)
        {
            free(current_line);
            break;
        }

        execute_opcode(current_line, &stack_head, line_counter, monty_file);
        line_counter++;

        free(current_line);
    }

    free_stack_nodes(stack_head);
    fclose(monty_file);

    return 0;
}

