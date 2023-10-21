#include "monty.h"
/**
 * _pall - Print all values in the stack
 * @head: Pointer to the head of the stack
 * @count: Line number in the Monty file (unused)
 *
 * Return: None
 */
void _pall(stack_t **head, unsigned int count)
{
    stack_t *current_node;
    (void) count;

    current_node = *head;
    if (current_node == NULL)
        return;

    while (current_node)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}
