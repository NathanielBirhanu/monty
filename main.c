#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
    FILE *file;
    char *content = NULL;
    size_t size = 0;
    ssize_t read_line;

    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read_line = getline(&content, &size, file)) != -1)
    {
        counter++;

        if (read_line > 0)
        {
            execute(content, &stack, counter, file);
        }

        free(content);
        content = NULL;
    }

    free_stack(stack);
    fclose(file);

    printf("Customized code executed!\n");
    return 0;
}
