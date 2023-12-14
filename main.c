#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *current_line;
    FILE *monty_file;
    size_t line_size = 0;
    ssize_t read_line = 1;
    stack_t *stack_head = NULL;
    unsigned int line_counter = 0;

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

    while (read_line > 0)
    {
        current_line = NULL;
        read_line = getline(&current_line, &line_size, monty_file);
        bus.content = current_line;
        line_counter++;

        if (read_line > 0)
        {
            execute_opcode(current_line, &stack_head, line_counter, monty_file);
        }

        free(current_line);
    }

    free_stack_nodes(stack_head);
    fclose(monty_file);

    return (0);
}

