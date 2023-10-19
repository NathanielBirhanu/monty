#include "monty.h"
/**
 * pop - Removes the top element from the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the pop operation is performed
 */
void pop(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "Error: Can't pop an empty stack at line %u\n", line_number);
        exit(EXIT_FAILURE);
    }
    else
    {
        stack_t *temp = *stack;
        printf("The deleted element is %d\n", (*stack)->n);
        *stack = (*stack)->next;

        if (*stack != NULL)
            (*stack)->prev = NULL;

        free(temp);
    }
}
