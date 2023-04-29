#include "compiler.h"

t_list_dimension *create_list_dim(int n)
{
    t_list_dimension *list;
    list = (t_list_dimension *)malloc(sizeof(t_list_dimension));

    list->dim = n;
    list->next = 0;
    return (list);
}

t_list_dimension *push_back_list_dim(t_list_dimension *list, int n)
{   
    t_list_dimension *tmp = list;
    t_list_dimension *inter;

    inter = create_list_dim(n);
    if (list == NULL) 
        return (inter);
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = inter;
    return (list);
}

t_list_dimension *pop_back_list_dim(t_list_dimension *list)
{
    t_list_dimension *tmp;
    t_list_dimension *begin = list;
    if (list == NULL)
        return (NULL);
    while (list->next)
    {
        tmp = list;
        list = (list)->next;
    }
    tmp->next = 0;
    free(list);
    return (begin);
}

void free_list_dim(t_list_dimension *list)
{
    t_list_dimension *tmp = list;
    while (tmp)
    {
        pop_back_list_dim(tmp);
    }
    free (list);
}