#include "monty.h"
/**
 * push - Pushes a new node onto the stack
 * @stack: Pointer to the stack
 * @x: Value to be inserted in the new node
 * @line_number: Line number where the push operation is performed
 */
void push(stack_t **stack, int x, unsigned int line_number)
{
    stack_t *newnode = malloc(sizeof(stack_t));
    if (newnode == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed at line %u\n", line_number);
        exit(EXIT_FAILURE);
    }

    newnode->n = x;
    newnode->prev = NULL;
    newnode->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = newnode;

    *stack = newnode;
}
