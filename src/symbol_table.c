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

t_symbol_table_elem  *create_symbol_table_element(char *name, char type, char type_symbol, short nb_args, t_list_dimension *dim)
{
    t_symbol_table_elem* elem;

    elem = (t_symbol_table_elem *)malloc(sizeof(t_symbol_table_elem));
    elem->name = strdup(name);
    elem->type = type;
    elem->type_identificateur = type_symbol;
    elem->nb_args = nb_args;
    elem->next = NULL;
    elem->list_dimension = dim;

    return (elem);
}

int add_element_in_symbol_table(t_symbol_table *table, t_symbol_table_elem *new_elem)
{
    if (!table)
        return (-1);
    if (table->begin == NULL)
        table->begin = new_elem;
    else if (table->end == NULL)
    {
        table->begin->next = new_elem;
        table->end = new_elem;
    }
    else
    {
        table->end->next = new_elem;
        table->end = new_elem;
    }
    return (0);
}

void    free_symbol_table(t_symbol_table* table)
{
    t_symbol_table_elem *act_elem;
    t_symbol_table_elem *next_elem;

    if (!table)
        return ;
    act_elem = table->begin;
    while (act_elem)
    {
        next_elem = act_elem->next;
        if (act_elem->list_dimension)
            free_list_dim(act_elem->list_dimension);
        free(act_elem->name);
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