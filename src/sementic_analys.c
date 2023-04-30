#import "compiler.h"

void    print_error(char *error, char   *complement)
{
    if (complement)
        printf("%s\n", error);
    else
        printf("%s %s\n", error, complement);
    exit (1);
}

int check_tab_dimention(t_tree *tree)
{
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
            if (type_id == TYPE_INT && !check_tab_dimention(tree))
                return (-1);
            if (id == NULL || !find_element_by_id_stack(stack, id))
                return (-1);
            return (TYPE_INT);
            break;
        case CONST_NODE:
            return (TYPE_INT);
            break;
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
        push_stack_symbol_table(&stack, create_stack_symbol_table(((t_node *)ast->content)->table));

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
    // If there is a son at the left -> we are not in the end
    if (ast->f_a)
        return (get_number_args(ast->f_a) + 1);
    // else we are in the end (We should not have this case)
    return (((t_node *)ast->content)->type != CALL_NODE);
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

int _sementic_analysis_check_rec(t_tree *ast, t_stack_symbol_table  *stack)
{
    int type = -1;
    char *id = NULL;
    int is_pushed_table = 0;
    static  unsigned long nb_node = 0;

    // Get id and type of the node
    if (!ast || ((t_node*)ast->content) == NULL)
        return (0); 
    if ((t_node*)ast->content)
    {
        if ((t_declaration *)((t_node*)ast->content)->datas)
            id = ((t_declaration*)((t_node*)ast->content)->datas)->name;
        type = ((t_node*)ast->content)->type;
    }
    nb_node++;
    // Push symbol table if it exist for this type
    if (((t_node *)ast->content)->table)
    {
        push_stack_symbol_table(&stack, create_stack_symbol_table(((t_node *)ast->content)->table));
        is_pushed_table = 1;
    }
    switch (type) {
        case FUNCTION_NODE:                     
            // Check Type of return
            int return_error = sementic_analysis_check_return(ast, \
            stack, ((t_declaration *)((t_node*)ast->content)->datas)->type);
            // Maybe it is not obligatory => for now always true
            return_error = 1;
            if (return_error == -1 || 
                (((t_declaration*)((t_node*)ast->content)->datas)->type == TYPE_INT && return_error == 0))
                return (print_error("Return has bad type\n", NULL), -1);
            break;
        case VAR_NODE:
            if (!find_element_by_id_stack(stack, id) \
            || (type == TYPE_TAB_INT && !check_tab_dimention(ast)))
                return (print_error("Variable not found :", id), -1);
            break;
        case ASSIGN_NODE:
            t_symbol_table_elem *elem = find_element_by_id_stack(stack, ((t_declaration*)((t_node*)((t_tree*)ast->f_a)->content)->datas)->name);

            if (!elem)
                return (print_error("Variable not found :", ((t_declaration*)((t_node*)((t_tree*)ast->f_a)->content)->datas)->name), -1);
            // if the expression is in good type
            if (get_type_expression(ast->f_b, stack) != TYPE_INT)
                return (print_error("Expressions have bad type\n", NULL), -1);
            if (elem->type_identificateur != TYPE_VAR && elem->type_identificateur != TYPE_ARG)
                return (print_error("It is not a variable\n", NULL), -1);
            break;
        case CALL_NODE:
            // If the function is not declared
            if (!find_element_by_id_stack(stack, id))
                return (print_error("function not exist\n", NULL), -1);
            // Bad number of args
            t_symbol_table_elem *fun_elem = find_element_by_id_stack(stack, id);
            if (get_number_args(ast) != elem->nb_args && 0)
                return (print_error("Bad number argument for the function \n", NULL), -1);
            // Bad type of args
            if (is_args_type_valid(ast->f_b, stack) == -1)
                return (print_error("Bad type of argument\n", NULL),-1);
        default:
            break;
    }
    _sementic_analysis_check_rec(ast->f_a, stack);
    _sementic_analysis_check_rec(ast->f_b, stack);
    if (is_pushed_table)
        pop_stack_symbol_table(&stack);
    return (0);
}

int conver_and_sementic_analys(t_tree *ast)
{
    if (ast == NULL)
        return (-1);
    t_stack_symbol_table    *stack = create_stack_symbol_table(((t_node*)ast->content)->table);
    return (_sementic_analysis_check_rec(ast->f_b, stack));
}