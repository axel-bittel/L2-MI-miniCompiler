#import "compiler.h"

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
    _create_symbol_tables_rec(tmp->f_b, table));
}

int create_symbol_tables(t_tree *ast)
{
    t_symbol_table  *global_table;

    global_table = create_symbol_table(SYMBOL_TYPE_GLOBAL);
    return (_create_symbol_tables_rec(ast, global_table));
}

int sementic_analysis_check_return(t_tree *ast, int type_return)
{
    int is_pushed_table = 0;

    // IF the node is a return node, check if the type is the same as the function
    if (((t_node *)ast->content)->type == RETURN_NODE)
    {
        // If the type_return != void
        if (type_return == TYPE_INT) 
            return (0);
        return (-1);
    }
    // If the node has symbol table, push it 
    if (((t_node *)ast->content)->table)
        push_stack_symbol_table(stack, ((t_node *)ast->content)->table);

    // Call for others nodes and catch errors
    if ((sementic_analysis_check_return(tmp->f_a, stack, tmp->type) == -1) \
    ||  (sementic_analysis_check_return(tmp->f_b, stack, tmp->type) == -1))
    {
        if (is_pushed_table)
            pop_stack_symbol_table(stack);
        return (-1);
    }
    return (0);
}

int _sementic_analysis_rec(t_tree *ast, t_stack_symbol_table  *stack)
{
    char *id;
    int type;
    int is_pushed_table = 0;

    // Get id and type of the node
    if (((t_node*)ast->content) == NULL)
        return (0); 

    id = tmp->name;
    type = ((t_node*)ast->content)->type;

    // Push symbol table is it exist for this type
    if (((t_node *)ast->content)->table)
    {
        push_stack_symbol_table(stack, ((t_node *)ast->content)->table);
        is_pushed_table = 1;
    }
    switch (type) {
        case FUNCTION_NODE:                     
            sementic_analysis_check_return(ast, stack, \
                    (t_declaration *)((t_node*)ast->content)->datas->type);
            break;
        case VAR_NODE:
            if (!find_element_by_id(stack, id))
                return (-1);
            break;
        case VAR_DECLARATION_NODE:
            if (find_element_by_id(stack->table, id))
                return (-1);
            break;
        default:
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
}