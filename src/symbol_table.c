#include "compiler.h"

t_symbol_table *create_symbol_table(char type_table)
{
    t_symbol_table *t_symbol_table;
    t_symbol_table = (t_symbol_table *)malloc(sizeof(t_symbol_table));

    t_symbol_table->size = 0;
    t_symbol_table->begin = NULL;
    t_symbol_table->end = NULL;
    t_symbol_table->type_table = type_table;

    return (t_symbol_table);
}

t_symbol_table_element  *create_symbol_table_element(char *name, char type char type_symbol, short nb_args = 0)
{
    t_symbol_table_element *t_symbol_table_element;

    t_symbol_table_element = (t_symbol_table_element *)malloc(sizeof(t_symbol_table_element));
    t_symbol_table_element->name = name;
    t_symbol_table_element->type = type;
    t_symbol_table_element->type_symbol = type_symbol;
    t_symbol_table_element->value = value;
    t_symbol_table_element->nb_args = nb_args;
    t_symbol_table_element->line_declaration = -1;
    t_symbol_table_element->next = NULL;

    return (t_symbol_table_element);
}

int add_element_in_symbol_table(t_symbol_table *t_symbol_table, t_symbol_table_element *t_symbol_table_element)
{
    t_symbol_table_element *tmp_elem;

    tmp_elem = t_symbol_table->begin;
    if (!t_symbol_table)
        return (-1);
    if (tmp_elem == NULL)
        t_symbol_table->begin = t_symbol_table_element;
    else if (t_symbol_table_element->end == NULL)
        t_symbol_table->end = t_symbol_table_element;
    else
        t_symbol_table->end->next = t_symbol_table_element;

    return (0);
}

void    free_symbol_table(t_symbol_table* table)
{
    t_symbol_table_element *act_elem;
    t_symbol_table_element *next_elem;

    act_elem = table->begin;
    while (act_elem)
    {
        next_elem = act_elem->next;
        free(act_elem);
        act_elem = next_elem;
    }
    free(table);
}

t_symbol_table_element  *find_element_by_id(char *id, t_symbol_table *table)
{
    t_symbol_table_element *act_elem;

    act_elem = table->begin;
    while (act_elem)
    {
        if (strcmp(act_elem->name, id) == 0)
            return (act_elem);
        act_elem = act_elem->next;
    }
    return (NULL);
}