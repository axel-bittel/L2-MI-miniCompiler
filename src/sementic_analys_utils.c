#import "compiler.h"
/*
int _create_symbol_tables_rec(t_tree *ast, t_symbol_table *actual_symbol_table, void    *return_value) 
{
    void           *actual_return_value = return_value;
    t_symbol_table *table = actual_symbol_table;
    
    int type = ((t_node*)tmp->content)->type;
    switch (type)
    {
        case FUNCTION_NODE:
            t_declaration *tmp = (t_declaration *)((t_node)ast->content)->data;
            t_symbol_table  *fun_table = create_symbol_table(SYMBOL_TABLE_FUNCTION);
            t_symbol_table_element  *fun_elem = create_symbol_table_element(tmp->name, tmp->type, SYMBOL_TABLE_FUNCTION, 0);
            if (!fun_table || !fun_elem)
                return (-1);
            ((t_node *)ast->content)->table = fun_table;
            table = fun_table;
            break;
        case BLOCK_NODE:
            t_symbol_table  *block_table = create_symbol_table(SYMBOL_TABLE_BLOCK);
            ast->content = block_table;
            ((t_node *)ast->content)->table = fun_table;
            table = block_table;
            break;
        case VAR_DECLARATION_NODE :
            t_symbol_table_element *var_elem = create_symbol_table_element(tmp->name, tmp->type, SYMBOL_TABLE_VARIABLE, 0);
            add_element_in_symbol_table(table, var_elem);
            break;
        default:
            break;
    }
    return (_create_symbol_tables_rec(tmp->f_a, table) &&
   ) _create_symbol_tables_rec(tmp->f_b, table);
}

int create_symbol_tables(t_tree *ast)
{
    t_symbol_table  *global_table;

    global_table = create_symbol_table(SYMBOL_TYPE_GLOBAL);
    return (_create_symbol_tables_rec(ast, global_table));
}*/
int check_tab_dimention(t_tree  *ast)
{
    return (1);
}

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

int sementic_analysis_check_return(t_tree *ast, int type_return)
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

int get_number_args(t_tree *ast)//In a call
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

int get_number_args_decl(t_tree *ast)//In a declaration
{
    // If the node is not a list param we are in the end
    if (((t_node *)ast->content)->type != LIST_PARAM_NODE)
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

*/

int symbol_list_declaration_rec (t_tree *tree, t_symbol_table *table)
{
    if (((t_node *)tree->content)->type == VAR_DECLARATEUR_NODE)
    {
        t_node *tmp = (t_node *)(tree->content);
        t_symbol_table_elem *new_elem = create_symbol_table_element(tmp->datas, tmp->type, TYPE_VAR, 0);
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
    if (((t_node *)tree->content)->type == ARG_NODE)
    {
        t_node *tmp = (t_node *)(tree->content);
        t_symbol_table_elem *new_elem = create_symbol_table_element(tmp->datas, tmp->type, TYPE_ARG, 0);
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
    if (((t_node *)(tree->f_a)->content)->type == BLOCK_FUN_NODE)
    {
        t_node *tmp = (t_node *)((tree->f_a)->content);
        t_symbol_table_elem *new_elem = create_symbol_table_element(tmp->datas, tmp->type, TYPE_FUNCTION, get_number_args_decl(tree->f_a));
        add_element_in_symbol_table(table, new_elem);

    }
    else
    {
        symbol_list_fonction_rec(tree->f_a, table);
    }
    t_node *tmp = (t_node *)((tree->f_b)->content);
    t_symbol_table_elem *new_elem = create_symbol_table_element(tmp->datas, tmp->type, TYPE_FUNCTION, get_number_args_decl(tree->f_b));
    add_element_in_symbol_table(table, new_elem);
    return (0);
}


/*
int _sementic_analysis_check_rec(t_tree *ast, t_stack_symbol_table  *stack)
{
    char *id = NULL;
    int type;
    int is_pushed_table = 0;

    // Get id and type of the node
    if (((t_node*)ast->content) == NULL)
        return (0); 
    if ((t_declaration *)((t_node*)ast->content)->datas)
    {
        id = ((t_declaration*)((t_node*)ast->content)->datas)->name;
        type = ((t_node*)ast->content)->type;
    }
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

int sementic_analysis(t_tree *ast)
{
    if (ast == NULL)
        return (-1);
    t_stack_symbol_table    *stack = create_stack_symbol_table();
    push_stack_symbol_table(stack, ast->content);
    return (_sementic_analysis_rec(ast, stack));
}*/