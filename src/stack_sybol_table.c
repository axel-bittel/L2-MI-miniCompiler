#include "compiler.h"

t_stack_symbol_table *create_stack_symbol_table()
{
    t_stack_symbol_table *stack;
    t_stack_symbol_table = (t_stack_symbol_table *)malloc(sizeof(t_stack_symbol_table));

    stack->next = 0;
    return (t_stack_symbol_table);
}

t_stack_symbol_table *push_stack_symbol_table(t_stack_symbol_table **stack, t_stack_symbol_table* new_stack)
{
    new_stack->next = *stack;
    *stack = new_stack;
    return (new_stack);
}

t_stack_symbol_table *pop_stack_symbol_table(t_stack_symbol_table **stack)
{
    t_stack_symbol_table *tmp;

    if (*stack == NULL)
        return (NULL);
    tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);
    return (tmp);
}

void free_stack(t_stack_symbol_table *stack)
{
    while (stack)
        pop_stack_symbol_table(&stack);
}