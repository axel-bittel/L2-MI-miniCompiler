#include "compiler.h"

t_list_dimension    *create_dim_list_rec(t_tree *tree, t_list_dimension *new_list)
{
    if (tree == NULL) return (NULL);
    if (tree->f_a)
    {
        if (*(int*)((t_node*)((t_tree*)tree->f_a)->content)->datas <= 0)
            return (print_error("Dimension must be positive", NULL), NULL);
        t_list_dimension *res = push_back_list_dim(new_list, \
           *(int*)((t_node*)((t_tree*)tree->f_a)->content)->datas);
        new_list = res;
    }
    if (tree->f_b && \
    ((t_node*)((t_tree*)tree->f_b)->content)->type == TAB_INT_DATA_NODE)
        new_list = create_dim_list_rec(tree->f_b, new_list);
    else if (tree->f_b)
        new_list = push_back_list_dim(new_list, \
           *(int*)((t_node*)((t_tree*)tree->f_b)->content)->datas);
    return (new_list);
}

int symbol_list_declaration_rec (t_tree *tree, t_symbol_table *table)
{
    if (!tree) return (-1);
    if (((t_node *)tree->content)->type == VAR_DECLARATEUR_NODE)
    {
        t_list_dimension    *dim = NULL;
        t_node *tmp = (t_node *)(tree->content);
        // Check double declarations
        if (find_element_by_id(((t_declaration*)tmp->datas)->name, table))
            return (print_error("Double variable definition : ",((t_declaration*)tmp->datas)->name, table), -1);
        if (((t_declaration*)((t_node *)tree->content)->datas)->type == TYPE_TAB_INT)
            dim = create_dim_list_rec(tree->f_b, NULL);
        t_symbol_table_elem *new_elem = create_symbol_table_element(((t_declaration*)tmp->datas)->name, tmp->type, TYPE_VAR, 0, dim);
        add_element_in_symbol_table(table, new_elem);
    }
    else if (((t_node *)tree->content)->type == LIST_DECLARATION_NODE)
    {
        symbol_list_declaration_rec(tree->f_a,table);
        symbol_list_declaration_rec(tree->f_b,table);
    }
    else
    {
        return (-1);
    }
    return(0);
}


int symbol_list_param_rec (t_tree *tree, t_symbol_table *table)
{
    if (!tree) return (-1);
    if (((t_node *)tree->content)->type == ARG_NODE)
    {
        t_node *tmp = (t_node *)(tree->content);
        // Check double declarations
        if (find_element_by_id(((t_declaration*)tmp->datas)->name, table))
            return (print_error("Double param definition : ",((t_declaration*)tmp->datas)->name, table), -1);
        t_symbol_table_elem *new_elem = create_symbol_table_element(((t_declaration*)tmp->datas)->name, tmp->type, TYPE_ARG, 0, 0);
        add_element_in_symbol_table(table, new_elem);
    }
    else if (((t_node *)tree->content)->type == LIST_PARAM_NODE)
    {
        symbol_list_param_rec(tree->f_a,table);
        symbol_list_param_rec(tree->f_b,table);
    }
    else
    {
        return (-1);
    }
    return(0);
}


int symbol_list_fonction_rec (t_tree *tree, t_symbol_table *table)
{
    if (tree == NULL) return (-1);

    // If we are at the end of the list
    if (((t_node *)(tree)->content)->type == FUNCTION_NODE)
    {
        t_node *tmp = (t_node *)(tree->content);
        // Check double declarations
        if (find_element_by_id(((t_declaration*)tmp->datas)->name, table))
            return (print_error("Double fonction definition : ",((t_declaration*)tmp->datas)->name, table), -1);
        t_symbol_table_elem *new_elem = create_symbol_table_element(((t_declaration*)tmp->datas)->name, tmp->type, TYPE_FUNCTION, 0, 0);
        add_element_in_symbol_table(table, new_elem);
        return (0);
    }
    // else we continue to go down and after add the function
    symbol_list_fonction_rec(tree->f_a, table);
    t_node *tmp = (t_node *)((tree->f_b)->content);
    t_symbol_table_elem *new_elem = create_symbol_table_element(((t_declaration*)tmp->datas)->name, tmp->type, TYPE_FUNCTION, 0, 0);
    add_element_in_symbol_table(table, new_elem);
    return (0);
}