#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the swap operation is performed
 */
void swap(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "Error: Can't swap, stack too short at line %u\n", line_number);
        exit(EXIT_FAILURE);
    }
    else
    {
        int temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
    }
}
