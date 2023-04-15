#import "compiler.h"

// int _create_symbol_tables_rec(t_tree *ast, t_symbol_table *actual_symbol_table)
// {
//     t_tree *tmp;
//     t_symbol_table *table;
//     t_symbol_table_element *elem;

//     if (((t_node*)tmp->content)->type == FUNCTION_NODE)
//     {
//         t_symbol_table = create_symbol_table(SYMBOL_TABLE_FUNCTION);
//         t_symbol_table_element = create_symbol_table_element(tmp->value, tmp->type, SYMBOL_TABLE_FUNCTION, 0);
//         add_element_in_symbol_table(t_symbol_table, t_symbol_table_element);
//         push_stack_symbol_table(&stack_symbol_table, t_symbol_table);
//     }
//     else if (tmp->type == INSTRUCTION_NODE)
//     {
//         t_symbol_table_element = create_symbol_table_element(tmp->value, tmp->type, SYMBOL_TABLE_VARIABLE, 0);
//         add_element_in_symbol_table(stack_symbol_table->table, t_symbol_table_element);
//     }
// }

int _create_symbol_tables_rec(t_tree *ast, t_symbol_table *actual_symbol_table)
{}

int create_symbol_tables(t_tree *ast)
{
    t_symbol_table  *global_table;

    global_table = create_symbol_table(SYMBOL_TYPE_GLOBAL);
    return (_create_symbol_tables_rec(ast, global_table));
}