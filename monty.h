#define _POSIX_C_SOURCE 200809l
#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct str_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @type: line content
 * @lf: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct str_s
{
	char *arg;
	FILE *file;
	char *type;
	int lf;
}  str_t;
extern str_t str;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *type);
void _push(stack_t **head, unsigned int num);
void _pall(stack_t **head, unsigned int num);
void _pint(stack_t **head, unsigned int num);
int execute(char *type, stack_t **head, unsigned int count, FILE *file);
void free_stack(stack_t *head);
void _pop(stack_t **head, unsigned int count);
void _swap(stack_t **head, unsigned int count);
void _add(stack_t **head, unsigned int count);
void _nop(stack_t **head, unsigned int count);
void newnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void _queue(stack_t **head, unsigned int count);
#endif
