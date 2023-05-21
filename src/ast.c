#include "compiler.h"
#include "ft_tree.h"


t_node	*create_new_node(int	type, void	*data, int line)
{
	t_node	*new_node;
	
	new_node = malloc (sizeof(t_node));
	new_node->type = type;
	new_node->datas = data;
    new_node->table = NULL;
    new_node->line = line;
	return (new_node);
}

t_tree	*create_parent_tree(t_tree	*sub_g, t_tree	*sub_d, int type, void	*data, int line)
{
	t_tree	*new_tree;
	
	new_tree = ft_treenew((void *)create_new_node(type, data, line));
	new_tree->f_a = sub_g;
	new_tree->f_b = sub_d;
	return (new_tree);
}

void    free_node(t_node    *node)
{
    if (node->datas)
    {
        switch (node->type)
        {
            case FUNCTION_NODE:
            case VAR_NODE:
            case CALL_NODE:
            case ARG_NODE:
            case VAR_DECLARATEUR_NODE:
                if(((t_declaration *)node->datas)->name)
                    free (((t_declaration *)node->datas)->name);
                break;
        }
        free(node->datas);
    }
    if (node->table)
        free_symbol_table(node->table);
    free(node);
}

void    free_tree(t_tree    *tree)
{
    if (tree)
    {
        // Free son
        if (tree->f_a)
            free_tree(tree->f_a);
        if (tree->f_b)
            free_tree(tree->f_b);

        //Free actual tree
        if (tree->content)
            free_node((t_node *)tree->content);
        free(tree);
    }
}

void	print_tree(t_tree	*tree, int i)
{
	int	j = i;
    
    
	if (tree)
	{
		print_type(((t_node *)tree->content)->type);
        if (((t_node *)tree->content)->type == CONST_NODE)
        {
            printf("(%d)", *(int*)((t_node *)tree->content)->datas);
        }
		printf("\n");
	}
    else
        return;
    if (!tree->f_a && !tree->f_b)
        return ;
    j = i;
	while (j-- > 0)
		printf("| ");
	printf("Gauche->");
    if (tree->f_a)
		print_tree(tree->f_a, i + 1);
    else
        printf("NULL\n");
    j = i;
	while (j-- > 0)
		printf("| ");
	printf("Droite->");
	if (tree->f_b)
		print_tree(tree->f_b, i + 1);
    else
        printf("NULL\n");
}

void print_type(int type)
{
    switch (type)
    {
        case COND_NODE:
            printf("COND_NODE");
            break;
        case IF_NODE:
            printf("IF_NODE");
            break;
        case ELSE_NODE:
            printf("ELSE_NODE");
            break;
        case RETURN_NODE:
            printf("RETURN_NODE");
            break;
        case CALL_NODE:
            printf("CALL_NODE");
            break;
        case ADD_NODE:
            printf("ADD_NODE");
            break;
        case MINUS_NODE:
            printf("MINUS_NODE");
            break;
        case MULT_NODE:
            printf("MULT_NODE");
            break;
        case DIV_NODE:
            printf("DIV_NODE");
            break;
        case ASSIGN_NODE:
            printf("ASSIGN_NODE");
            break;
        case RSHIFT_NODE:
            printf("RSHIFT_NODE");
            break;
        case LSHIFT_NODE:
            printf("LSHIFT_NODE");
            break;
        case BAND_NODE:
            printf("BAND_NODE");
            break;
        case BOR_NODE:
            printf("BOR_NODE");
            break;
        case NOT_NODE:
            printf("NOT_NODE");
            break;
        case OPP_NODE:
            printf("OPP_NODE");
            break;
        case BOOL_EQ_NODE:
            printf("BOOL_EQ_NODE");
            break;
        case BOOL_L_NODE:
            printf("BOOL_L_NODE");
            break;
        case BOOL_G_NODE:
            printf("BOOL_G_NODE");
            break;
        case BOOL_LE_NODE:
            printf("BOOL_LE_NODE");
            break;
        case BOOL_GE_NODE:
            printf("BOOL_GE_NODE");
            break;
        case BOOL_AND_NODE:
            printf("BOOL_AND_NODE");
            break;
        case BOOL_OR_NODE:
            printf("BOOL_OR_NODE");
            break;
        case BOOL_NEQ_NODE:
            printf("BOOL_NEQ_NODE");
            break;
        case INSTRUCTION_NODE:
            printf("INSTRUCTION_NODE");
            break;
        case FUNCTION_NODE:
            printf("FUNCTION_NODE");
            break;
        case EXTERN_FUNCTION_NODE:
            printf("EXTERN_FUNCTION_NODE");
            break;
        case LIST_FUNCTION_NODE:
            printf("LIST_FUNCTION_NODE");
            break;
        case WHILE_NODE:
            printf("WHILE_NODE");
            break;
        case FOR_NODE:
            printf("FOR_NODE");
            break;
        case CONST_NODE:
            printf("CONST_NODE");
            break;
        case VAR_DECLARATEUR_NODE:
            printf("VAR_DECLARATEUR_NODE");
            break;
        case VAR_NODE:
            printf("VAR_NODE");
            break;
        case VAR_LIST_NODE:
            printf("VAR_LIST_NODE");
            break;
        case ARG_NODE:
            printf("ARG_NODE");
            break;
        case LIST_EXPRESSION_NODE:
            printf("LIST_EXPRESSION_NODE");
            break;
        case BLOCK_NODE:
            printf("BLOCK_NODE");
            break;
        case BLOCK_FUN_NODE:
            printf("BLOCK_FUN_NODE");
            break;
        case BREAK_NODE:
            printf("BREAK_NODE");
            break;
        case SWITCH_NODE:
            printf("SWITCH_NODE");
            break;
        case CASE_NODE:
            printf("CASE_NODE");
            break;
        case DEFAULT_NODE:
            printf("DEFAULT_NODE");
            break;
        case ROOT_NODE:
            printf("ROOT_NODE");
            break;
        case LIST_DECLARATION_NODE:
            printf("LIST_DECLARATION_NODE");
            break;
        case LIST_PARAM_NODE:
            printf("LIST_PARAM_NODE");
            break;       
        case LIST_INSTRUCTION_NODE:
            printf("LIST_INSTRUCTION_NODE");
            break; 
        case LIST_DECLARATEUR_NODE :
            printf("LIST_DECLARATEUR_NODE ");
            break; 
        case TAB_INT_DATA_NODE:
            printf("TAB_INT_DATA_NODE ");
            break; 
        case FOR_DATA_NODE:
            printf("FOR_DATA_NODE");
            break;
        case IF_DATA_NODE:
            printf("IF_DATA_NODE");
            break;
        default:
            printf("%d", type);
            break;
    }
}
