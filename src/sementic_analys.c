#include "compiler.h"
#include <stdio.h>

int  nbNode = 1;
char is_error = 0;
FILE *fileResult_decla = 0;
FILE *fileResult_link  = 0;
FILE *fileResult       = 0;

void    print_error(char *error, char   *complement, int line)
{
    if (!complement)
        printf("compiler: \033[1;31merror: %s, line %d\033[1;0m\n", error, line);
    else
        printf("compiler: \033[1;31merror: %s %s, line %d\033[1;0m\n", error, complement, line);
    is_error = 1;
}

void    print_warning(char *error, char   *complement, int line)
{
    if (!complement)
        printf("compiler: \033[1;35mwarning: %s, line %d\033[1;0m \n", error, line);
    else
        printf("compiler: \033[1;35mwarning: %s %s, line &d\033[1;0m\n", error, complement, line);
    is_error = 1;
}

int check_tab_dimention(t_symbol_table_elem *elem, t_tree *tree, t_stack_symbol_table *stack)
{
    t_list_dimension *dim = elem->list_dimension;
    t_tree *tmp = tree->f_b;

    if (tree == NULL)
        return (-1);
    int line = ((t_node*)((t_tree*)tmp->f_a)->content)->line; 
    while (tmp)
    {
        if (tmp->f_a && ((t_node*)((t_tree*)tmp->f_a)->content)->type == CONST_NODE)
        {
            if (*(int*)((t_node*)((t_tree*)tmp->f_a)->content)->datas >= dim->dim || \
            *(int*)((t_node*)((t_tree*)tmp->f_a)->content)->datas < 0)
                return (print_warning("Dimension overflow", NULL, line), -1);
        }
        else if (tmp->f_a && get_type_expression(tmp->f_a, stack) != TYPE_INT)
            return (print_error("Dimension must be a constant", NULL, line), -1);
        tmp = tmp->f_b;
        dim = dim->next;
        if ((dim == NULL && tmp != NULL) || (dim != NULL && tmp == NULL))
            return (print_error("Bad dimension", NULL, line), -1);
    }
    return (1);
}

int get_type_expression(t_tree  *tree, t_stack_symbol_table *stack)
{
    char  *id = NULL;
    int   type_id;
    int   type_node;

    if (tree == NULL)
        return (TYPE_INT);
    type_node = ((t_node *)tree->content)->type;
    if ((t_declaration *)((t_node*)tree->content)->datas)
    {
        id = ((t_declaration *)((t_node*)tree->content)->datas)->name;
        type_id = ((t_declaration *)((t_node*)tree->content)->datas)->type;
    }

    switch (type_node)
    {
        case VAR_NODE:
            if (id == NULL || !find_element_by_id_stack(stack, id))
                return (-1);
            return (TYPE_INT);
            break;
        case CONST_NODE:
            return (TYPE_INT);
            break;
        case BOOL_AND_NODE:
        case BOOL_OR_NODE:
        case BOOL_EQ_NODE:
        case BOOL_GE_NODE:
        case BOOL_G_NODE:
        case BOOL_L_NODE:
        case BOOL_LE_NODE:
        case BOOL_NEQ_NODE:
        case ADD_NODE:
        case MINUS_NODE:
        case MULT_NODE:
        case DIV_NODE:
        case LSHIFT_NODE:
        case RSHIFT_NODE:
        case BAND_NODE:
        case BOR_NODE:
            if (get_type_expression(tree->f_a, stack) == TYPE_INT \
            && get_type_expression(tree->f_b, stack) == TYPE_INT)
                return (TYPE_INT);
            return (-1);
            break;
        case CALL_NODE:
            t_symbol_table_elem *elem = find_element_by_id_stack(stack, id);
            if (!elem)
                return (-1);
            return (elem->type);
            break;
        default:
            return (-1);
    }
}

int sementic_analysis_check_return(t_tree *ast, t_stack_symbol_table *stack, int type_return)
{
    int is_pushed_table = 0;

    if (ast == NULL)
        return (0);
    // If the node is a return node, check if the type is the same as the function
    if (((t_node *)ast->content)->type == RETURN_NODE)
    {
        if (type_return == TYPE_INT && ast->f_b && \
            get_type_expression(ast->f_b, stack) == TYPE_INT)
            return (1);
        else if (type_return == TYPE_VOID && \
                (ast->f_b == NULL || get_type_expression(ast->f_b, stack) == TYPE_VOID))
            return (1);
        return (-1);
    }
    // If the node has symbol table, push it 
    if (((t_node *)ast->content)->table && \
        (((t_node *)ast->content)->type != TYPE_FUNCTION))
    {
        push_stack_symbol_table(&stack, create_stack_symbol_table(((t_node *)ast->content)->table));
        is_pushed_table = 1;
    }

    // Call for others nodes and catch errors
    int res1 = sementic_analysis_check_return(ast->f_a, stack, type_return);
    int res2 = sementic_analysis_check_return(ast->f_b, stack, type_return); 
    if (is_pushed_table)
        pop_stack_symbol_table(&stack);
    if (res1 || res2)
    {
        if (res1 == -1 || res2 == -1)
            return (-1);
        return (1);
    }
    return (0);
}

int get_number_args(t_tree *ast)
{
    // If the node is not a list expression we are in the end
    if (((t_node *)ast->content)->type != LIST_EXPRESSION_NODE
    && ((t_node *)ast->content)->type != CALL_NODE)
        return (1);
    if (((t_node *)ast->content)->type == CALL_NODE && ast->f_b)
        return (get_number_args(ast->f_b));
    // If there is a son at the left -> we are not in the end
    if (ast->f_b)
        return (get_number_args(ast->f_b) + 1);
    // else we are in the case here we have a call node with no args or one arg
    return (ast->f_b != NULL);
}

int is_args_type_valid(t_tree *ast, t_stack_symbol_table *stack)
{
    if (ast == NULL)
        return (1);
    // If the node is not a list expression we are in the end
    if (((t_node *)ast->content)->type != LIST_EXPRESSION_NODE)
        return (get_type_expression(ast, stack) == TYPE_INT);
    // If there is a son at the left -> we are not in the end
    if (ast->f_a)
    {
        if (get_type_expression(ast->f_b, stack) == TYPE_INT)
            return (is_args_type_valid(ast->f_a, stack));
        return (0);
    }
    // else we are in the end (We should not have this case)
    return (1);
}

int _sementic_analysis_check_rec(t_tree *ast, t_stack_symbol_table  *stack, int nb, int is_in_switch)
{
    int line = 0;
    int type = -1;
    char *id = NULL;
    int is_pushed_table = 0;
    int actual_nb_node = nb;
    t_symbol_table_elem *elem = NULL;

    // Get id and type of the node
    if (!ast || ((t_node*)ast->content) == NULL)
        return (0); 
    if ((t_node*)ast->content)
    {
        if ((t_declaration *)((t_node*)ast->content)->datas)
            id = ((t_declaration*)((t_node*)ast->content)->datas)->name;
        type = ((t_node*)ast->content)->type;
        if (type != LIST_EXPRESSION_NODE \
        && type != LIST_INSTRUCTION_NODE \
        && type != LIST_FUNCTION_NODE    \
        && type != ELSE_NODE \
        && type != TAB_INT_DATA_NODE \
        && type != IF_DATA_NODE \
        && type != FOR_DATA_NODE)
            actual_nb_node = nbNode;
        line = ((t_node*)ast->content)->line;
    }
    // Push symbol table if it exist for this type
    if (((t_node *)ast->content)->table)
    {
        push_stack_symbol_table(&stack, create_stack_symbol_table(((t_node *)ast->content)->table));
        is_pushed_table = 1;
    }
    decl_dot(ast, actual_nb_node);
    switch (type) {
        case FUNCTION_NODE:                     
            // Check Type of return
            int return_error = sementic_analysis_check_return(ast, \
            stack, ((t_declaration *)((t_node*)ast->content)->datas)->type);
            if (return_error == -1 || 
                (((t_declaration*)((t_node*)ast->content)->datas)->type == TYPE_INT && return_error == 0))
                    print_warning("Return has bad type", NULL, line);
            break;
        case VAR_NODE:
            // Find in symbol table
            if (!(elem = find_element_by_id_stack(stack, id)))
                print_error("Variable not found :", id, line);
            // Check if the type and dimensiosn are good
            if (((t_declaration*)((t_node*)ast->content)->datas)->type == TYPE_TAB_INT)
                check_tab_dimention(elem, ast, stack);
            break;
        case ASSIGN_NODE:
            elem = find_element_by_id_stack(stack, ((t_declaration*)((t_node*)((t_tree*)ast->f_a)->content)->datas)->name);

            if (get_type_expression(ast->f_b, stack) != TYPE_INT)
                print_error("Assignation expressions have bad type", NULL, line);
            if (!elem)
                break;
            else if (elem->type_identificateur != TYPE_VAR && elem->type_identificateur != TYPE_ARG)
                print_error("It is not a variable", NULL, line);
            break;
        case CALL_NODE:
            // If the function is not declared
            if (!find_element_by_id_stack(stack, id))
            {
                print_error("Function not exist :", id, line);
                break;
            }
            // Bad number of args
            t_symbol_table_elem *fun_elem = find_element_by_id_stack(stack, id);
            if (get_number_args(ast) != fun_elem->nb_args)
                print_error("Bad number argument for the function", NULL, line);
            // Bad type of args
            if (is_args_type_valid(ast->f_b, stack) == -1)
                print_error("Bad type of argument", NULL, line);
            break;
        case IF_NODE:
            // Check if the expression is in good type
            if (((t_node*)((t_tree*)ast->f_a)->content)->type == IF_DATA_NODE \
                && (get_type_expression(((t_tree*)ast->f_a)->f_a, stack) != TYPE_INT))
                    print_error("Condition expressions have bad type", NULL, line);
            else if (((t_node*)((t_tree*)ast->f_a)->content)->type != IF_DATA_NODE \
                && (get_type_expression((t_tree*)ast->f_a, stack) != TYPE_INT))
                    print_error("Condition expressions have bad type", NULL, line);
            break; 
        case SWITCH_NODE:
            is_in_switch = 1;
            // Check if the expression is in good type
            if (get_type_expression(ast->f_a, stack) != TYPE_INT)
                print_error("Condition expressions have bad type", NULL, line);
            break;
        case CASE_NODE:
            if (!is_in_switch)
                print_error("Case not in switch", NULL, line);
        default:
            break;
    }
    link_dot(actual_nb_node, _sementic_analysis_check_rec(ast->f_a, stack, actual_nb_node, is_in_switch));
    link_dot(actual_nb_node, _sementic_analysis_check_rec(ast->f_b, stack, actual_nb_node, is_in_switch));
    if (is_pushed_table)
        pop_stack_symbol_table(&stack);
    return (actual_nb_node);
}

int conver_and_sementic_analys(t_tree *ast)
{
    int res;
    t_stack_symbol_table    *stack;

    if (ast == NULL)
        return (-1);

    stack = create_stack_symbol_table(((t_node*)ast->content)->table);
    res = _sementic_analysis_check_rec(ast->f_b, stack, 0, 0);
    free_stack(stack);
    return (res);
}