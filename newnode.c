#include "monty.h"
/**
 * newnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void newnode(stack_t **head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        printf("Error\n");
        exit(0);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }

    *head = new_node;
}
