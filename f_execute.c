#include "monty.h"

/**
 * execute_opcode - executes the opcode
 * @line_content: line content
 * @stack_head: head of the stack
 * @line_counter: line counter
 * @monty_file: pointer to the monty file
 * Return: no return
 */
int execute_opcode(char *line_content, stack_t **stack, unsigned int line_counter, FILE *monty_file)
{
    instruction_t opcodes[] = {
        {"push", push_node}, {"pall",  print_stack}
    };

    unsigned int i = 0;
    char *opcode;

    opcode = strtok(line_content, " \n\t");
    if (opcode && opcode[0] == '#')
        return 0;

    bus.arg = strtok(NULL, " \n\t");

    while (opcodes[i].opcode && opcode)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, line_counter);
            return 0;
        }
        i++;
    }

    if (opcode && opcodes[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, opcode);
        fclose(monty_file);
        free(line_content);
	free_stack_nodes(*stack);

        exit(EXIT_FAILURE);
    }

    return 1;
}

