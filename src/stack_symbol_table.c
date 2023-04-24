#include "compiler.h"

t_stack_symbol_table *create_stack_symbol_table(t_symbol_table* table)
{
    t_stack_symbol_table *stack;
    stack = (t_stack_symbol_table *)malloc(sizeof(t_stack_symbol_table));

    stack->table = table;
    stack->next = 0;
    return (stack);
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
    t_stack_symbol_table *tmp = stack;
    while (tmp)
    {
        pop_stack_symbol_table(tmp);
        tmp = tmp->next;
    }
    free (stack);
}

t_symbol_table_elem *find_element_by_id_stack(t_stack_symbol_table *stack, char *id)
{
    t_symbol_table_elem *elem;

    while (stack)
    {
        elem = find_element_by_id(stack->table, id);
        if (elem)
            return (elem);
        stack = stack->next;
    }
    return (NULL);
}

t_symbol_table_elem *find_table_by_id_stack(t_stack_symbol_table *stack, char *id)
{
    t_symbol_table_elem *elem;

    while (stack)
    {
        elem = find_element_by_id(stack->table, id);
        if (elem)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}