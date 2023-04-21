#include "compiler.h"

t_symbol_table *create_symbol_table(char type_table)
{
    t_symbol_table *table;
    table = (t_symbol_table *)malloc(sizeof(t_symbol_table));

    table->size = 0;
    table->begin = NULL;
    table->end = NULL;
    table->type_table = type_table;

    return (table);
}

t_symbol_table_elem  *create_symbol_table_element(char *name, char type, char type_symbol, short nb_args)
{
    t_symbol_table_elem* elem;

    elem = (t_symbol_table_elem *)malloc(sizeof(elem));
    elem->name = name;
    elem->type = type;
    elem->type_symbol = type_symbol;
    elem->nb_args = nb_args;
    elem->line_declaration = -1;
    elem->next = NULL;

    return (elem);
}

int add_element_in_symbol_table(t_symbol_table *table, t_symbol_table_elem *new_elem)
{
    t_symbol_table_elem *tmp_elem;

    tmp_elem = table->begin;
    if (!table)
        return (-1);
    if (table->begin == NULL)
        table->begin = new_elem;
    else if (table->end == NULL)
        table->end = new_elem;
    else
        table->end->next = new_elem;

    return (0);
}

void    free_symbol_table(t_symbol_table* table)
{
    t_symbol_table_elem *act_elem;
    t_symbol_table_elem *next_elem;

    act_elem = table->begin;
    while (act_elem)
    {
        next_elem = act_elem->next;
        free(act_elem);
        act_elem = next_elem;
    }
    free(table);
}

t_symbol_table_elem  *find_element_by_id(char *id, t_symbol_table *table)
{
    t_symbol_table_elem *act_elem;

    act_elem = table->begin;
    while (act_elem)
    {
        if (strcmp(act_elem->name, id) == 0)
            return (act_elem);
        act_elem = act_elem->next;
    }
    return (NULL);
}