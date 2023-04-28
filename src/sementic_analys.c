#import "compiler.h"

int get_type_expression(t_tree  *tree, t_stack *stack)
{
    char  *id = NULL;
    int   type_id;
    int type_node = ((t_node *)tree->content)->type;

    if ((t_declaration *)((t_var_node *)tree->content)->datas)
    {
        id = ((t_declaration *)((t_var_node *)tree->content)->datas)->name;
        type_id = ((t_declaration *)((t_var_node *)tree->content)->datas)->type;
    }

    switch (type_node)
    {
        switch (type_node)
        {
            case VAR_NODE:
                if (type_id == TYPE_INT && !check_tab_dimention(ast))
                    return (-1);
                if (id == NULL || !find_element_by_id(stack, id))
                    return (-1);
                return (TYPE_INT);
                break;
            case CONSTATE_NODE:
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
                if (find_element_by_id(stack, id))
                    return (-1);
                return (type_id);
                break;
            default:
                return (-1);
        }
    }
}

int sementic_analysis_check_return(t_tree *ast, t_stack_symbol_table *stack, int type_return)
{
    int is_pushed_table = 0;

    // If the node is a return node, check if the type is the same as the function
    if (((t_node *)ast->content)->type == RETURN_NODE)
    {
        if (type_return == TYPE_INT && ast->f_b && \
            get_type_expression(ast->f_b, stack) == TYPE_INT)
            return (1);
        else if (type_return == TYPE_VOID && \
                (ast->f_b == NULL || get_type_expression(ast->f_b, stack) == TYPE_VOID))
            return (1);
        return (0);
    }
    // If the node has symbol table, push it 
    if (((t_node *)ast->content)->table)
        push_stack_symbol_table(stack, ((t_node *)ast->content)->table);

    // Call for others nodes and catch errors
    if (!sementic_analysis_check_return(tmp->f_a, tmp->type) \
    ||  !sementic_analysis_check_return(tmp->f_b, tmp->type))
    {
        if (is_pushed_table)
            pop_stack_symbol_table(stack);
        return (0);
    }
    if (is_pushed_table)
        pop_stack_symbol_table(stack);
    return (1);
}

int get_number_args(t_tree *ast)
{
    // If the node is not a list expression we are in the end
    if (((t_node *)ast->content)->type != LIST_EXPRESSION_NODE)
        return (1);
    // If there is a son at the left -> we are not in the end
    if (ast->f_a)
        return (get_number_args(ast->f_a) + 1);
    // else we are in the end (We should not have this case)
    return (1);
}

int is_args_type_valid(t_tree *ast, t_stack *stack)
{
    // If the node is not a list expression we are in the end
    if (((t_node *)ast->content)->type != LIST_EXPRESSION_NODE)
        return (get_type_expression(ast, stack) == TYPE_INT);
    // If there is a son at the left -> we are not in the end
    if (ast->f_a)
    {
        if (get_type_expression(ast->f_b, stack) == TYPE_INT)
            return (is_args_type_valid(ast->f_a));
        return (0);
    }
    // else we are in the end (We should not have this case)
    return (1);
}

int _sementic_analysis_check_rec(t_tree *ast, t_stack_symbol_table  *stack)
{
    int type;
    char *id = NULL;
    int is_pushed_table = 1;
    static  unsigned long nb_node = 0;

    // Get id and type of the node
    if (((t_node*)ast->content) == NULL)
        return (0); 
    if ((t_declaration *)((t_node*)ast->content)->datas)
    {
        id = ((t_declaration*)((t_node*)ast->content)->datas)->name;
        type = ((t_node*)ast->content)->type;
    }
    nb_node++;
    // Push symbol table if it exist for this type
    if (((t_node *)ast->content)->table)
    {
        push_stack_symbol_table(stack, ((t_node *)ast->content)->table);
        is_pushed_table = 1;
    }
    switch (type) {
        case FUNCTION_NODE:                     
            // Check Type of return
            if (!find_element_by_id || sementic_analysis_check_return(ast, \
            ((t_declaration *)((t_node*)ast->content)->datas)->type) == -1)
                return (-1);
            break;
        case VAR_NODE:
            if (!find_element_by_id(stack, id) \
            || (type == TYPE_TAB_INT && !check_tab_dimention(ast)))
                return (-1);
            break;
        case ASSIGN_NODE:
            int type_var = find_element_by_id(stack, (t_declaration*)((t_node*)(ast->f_a->content)->datas)->id)->type_identificateur;
            // if the expression is in good type
            if (get_type_expression(ast->f_a, stack) != TYPE_INT)
                return (-1);
            if (type_var != TYPE_VAR && type_var != TYPE_ARG)
                return (-1);
            break;
        case CALL_NODE:
            // If the function is not declared
            if (!find_element_by_id_stack(stack, id))
                return (-1);
            // Bad number of args
            if (get_number_args(ast) != find_element_by_id_stack(stack, id)->nb_args)
                return (-1);
            // Bad type of args
            if (is_args_type_valid(ast, stack) == -1)
                return (-1);
        default:
            return (0);
            break;
    }
    _sementic_analysis_rec(ast->f_a, stack);
    _sementic_analysis_rec(ast->f_b, stack);
    if (is_pushed_table)
        pop_stack_symbol_table(stack);
    return (0);
}

int conver_and_sementic_analys(t_tree *ast)
{
    if (ast == NULL)
        return (-1);
    t_stack_symbol_table    *stack = create_stack_symbol_table();
    push_stack_symbol_table(stack, ast->content);
    return (_sementic_analysis_rec(ast, stack));
}*/