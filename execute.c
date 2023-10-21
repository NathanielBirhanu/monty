#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @type: line content
* Return: no return
*/
int execute(char *type, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(type, " \n\t");
	if (op && op[0] == '#')
		return (0);
	str.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(type);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
