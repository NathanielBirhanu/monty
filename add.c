#include "monty.h"
/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the add operation is performed
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "Error: Can't add, stack too short at line %u\n", line_number);
        exit(EXIT_FAILURE);
    }
    else
    {
        stack_t *temp = *stack;
        int sum = temp->n + temp->next->n;
        temp->next->n = sum;
        *stack = temp->next;
        (*stack)->prev = NULL;
        free(temp);
    }
}
