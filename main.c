#include "monty.h"
/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    stack_t *stack = NULL;

    if (argc < 2)
    {
        fprintf(stderr, "Error: No command-line arguments provided\n");
        return EXIT_FAILURE;
    }

    bool invalidInput = false;
    unsigned int line_number = 1;
    for (int i = 1; i < argc; i++)
    {
        char *endptr;
        int x = strtol(argv[i], &endptr, 10);
        if (*endptr != '\0')
        {
            fprintf(stderr, "Error: Invalid argument at line %u\n", line_number);
            invalidInput = true;
            break;
        }
        push(&stack, x, line_number);
        line_number++;
    }

    if (invalidInput)
    {
        while (stack != NULL)
        {
            stack_t *temp = stack;
            stack = stack->next;
            free(temp);
        }
        return EXIT_FAILURE;
    }

    push(&stack, 2, line_number);
    pall(&stack, line_number);
    pint(&stack, line_number);
    pop(&stack, line_number);
    swap(&stack, line_number);
    add(&stack, line_number);
    nop(&stack, line_number);

    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}
