#include "monty.h"
/**
 * pall - Prints all elements in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the pall operation is performed
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    if (*stack == NULL)
    {
        fprintf(stderr, "Error: Stack underflow at line %u\n", line_number);
        exit(EXIT_FAILURE);
    }

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
