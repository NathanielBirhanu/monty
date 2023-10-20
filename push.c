#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
    int value, index = 0, is_negative = 0, is_valid = 1;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            is_negative = 1;

        while (bus.arg[index] != '\0')
        {
            if (bus.arg[index] < '0' || bus.arg[index] > '9')
            {
                is_valid = 0;
                break;
            }
            index++;
        }

        if (is_valid)
        {
            value = atoi(bus.arg);
            if (is_negative)
                value *= -1;

            if (bus.lifi == 0)
                newnode(head, value);
        }
        else
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
}
