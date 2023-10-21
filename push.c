#include "monty.h"
/**
 * _push - add node to the stack
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void _push(stack_t **head, unsigned int count)
{
	int n, j = 0, flag = 0;

	if (str.arg)
	{
		if (str.arg[0] == '-')
			j++;
		for (; str.arg[j] != '\0'; j++)
		{
			if (str.arg[j] > 57 || str.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(str.file);
			free(str.type);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(str.file);
		free(str.type);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(str.arg);
	if (str.lf == 0)
		newnode(head, n);
	else
		addqueue(head, n);
}
