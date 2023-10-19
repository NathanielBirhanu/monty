#include "monty.h"
/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the pint operation is performed
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "Error: Can't pint, stack empty at line %u\n", line_number);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("%d\n", (*stack)->n);
    }
}
