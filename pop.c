#include "monty.h"
/**
 * _pop - prints the top
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void _pop(stack_t **head, unsigned int count)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(str.file);
		free(str.type);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
