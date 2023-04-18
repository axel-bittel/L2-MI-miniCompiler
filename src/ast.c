/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abittel <abittel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:48:27 by abittel           #+#    #+#             */
/*   Updated: 2023/01/31 00:28:06 by abittel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compiler.h"
#include "ft_tree.h"


t_node	*create_new_node(int	type, void	*data)
{
	t_node	*new_node;
	
	new_node = malloc (sizeof(t_node));
	new_node->type = type;
	new_node->datas = data;
	return (new_node);
}

t_tree	*create_parent_tree(t_tree	*sub_g, t_tree	*sub_d, int type, void	*data)
{
	t_tree	*new_tree;
	
	new_tree = ft_treenew((void *)create_new_node(type, data));
	new_tree->f_a = sub_g;
	new_tree->f_b = sub_d;
	//print_tree(new_tree);
	//printf("---------------------------------\n");
	return (new_tree);
}

void	print_tree(t_tree	*tree, int i)
{
	int	j = i;
	printf("  ");
	if (tree)
	{
		printf("ROOT -> ");
		print_type(((t_node *)tree->content)->type);
		printf("\n");
	}
	else
		return ;
	if (tree->f_b)
	{
		j = i;
		while (j-- > 0)
			printf("| ");
		printf("Droite->");
		print_tree(tree->f_b, i + 1);
	}
	if (tree->f_a)
	{
		j = i;
		while (j-- > 0)
			printf("| ");
		printf("Gauche->");
		print_tree(tree->f_a, i + 1);
	}
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
        case ELSEIF_NODE:
            printf("ELSEIF_NODE");
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
        case VAR_DECLARATION_NODE:
            printf("VAR_DECLARATION_NODE");
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
        case EXP_LIST_NODE:
            printf("EXP_LIST_NODE");
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
        default:
            printf("%d", type);
            break;
    }
}
