#ifndef COMPILER_H
#define COMPILER_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "ft_tree.h"

#define COND_NODE                0   //NODE FOR BEGIN CONDITION
#define IF_NODE                  1   //NODE FOR IF
#define ELSEIF_NODE              2   //NODE FOR ELSE IF
#define ELSE_NODE                3   //NODE FOR ELSE
#define RETURN_NODE              4   //NODE FOR RETURN OF FUNCTION
#define CALL_NODE                5   //NODE CALL FUNCTION
#define ADD_NODE                 6   //NODE FOR ADDITION
#define MINUS_NODE               7   //NODE FOR SUBSTRACTION
#define MULT_NODE                8   //NODE FOR MULTIPLICATION
#define DIV_NODE                 9   //NODE FOR DIVISION
#define ASSIGN_NODE             10   //NODE FOR EQUALITY
#define RSHIFT_NODE             11   //NODE FOR >>
#define LSHIFT_NODE             12   //NODE FOR <<
#define BAND_NODE               13   //NODE FOR &
#define BOR_NODE                14   //NODE FOR |
#define BOOL_EQ_NODE            15   //NODE FOR ==
#define BOOL_L_NODE             16   //NODE FOR <
#define BOOL_G_NODE             17   //NODE FOR >
#define BOOL_LE_NODE            18   //NODE FOR <=
#define BOOL_GE_NODE            19   //NODE FOR >=
#define BOOL_AND_NODE           20   //NODE FOR &&
#define BOOL_OR_NODE            21   //NODE FOR ||
#define INSTRUCTION_NODE        22   //NODE FOR INSTRUCTION
#define FUNCTION_NODE           23   //NODE FOR FUNCTION
#define CONST_NODE              24   //NODE FOR CONST
#define WHILE_NODE              25   //NODE FOR WHILE
#define VAR_DECLARATION_NODE    26   //NODE FOR ID DECLARATION (VAR)
#define VAR_LIST_NODE           27   //NODE FOR DECLARATION OF ID (VAR)
#define ARG_NODE                28   //NODE FOR ARGUMENT OF FUNCTION
#define EXP_LIST_NODE           29   //NODE FOR LIST OF ARGUMENT OF FUNCTION
#define ROOT_NODE               30   //NODE FOR ROOT OF AST
#define BLOCK_NODE              31   //NODE FOR BLOCK OF INSTRUCTION
#define NOT_NODE                32   //NODE FOR !
#define OPP_NODE                33   //NODE FOR -
#define BOOL_NEQ_NODE           34   //NODE FOR !=
#define FOR_NODE                35   //NODE FOR FOR
#define LIST_FUNCTION_NODE      36   //NODE FOR LIST_FUNCTION
#define EXTERN_FUNCTION_NODE    37   //NODE FOR FUNCTION
#define BREAK_NODE              38   //NODE FOR BREAK
#define SWITCH_NODE             39   //NODE FOR SWITCH
#define CASE_NODE               40   //NODE FOR CASE
#define DEFAULT_NODE            41   //NODE FOR DEFAULT
#define VAR_NODE                42   //NODE FOR ID (VAR)
#define BLOCK_FUN_NODE		    43   //NODE FOR BLOC FUNCTION


//AST
typedef struct	s_node
{
	char	type;
	void	*datas;
}				t_node;

void	print_tree(t_tree	*tree, int i);
t_node	*create_new_node(int	type, void	*data);
t_tree	*create_parent_tree(t_tree	*sub_g, t_tree	*sub_d, int type, void	*data);

#define TYPE_VAR				0 	//ID VAR
#define TYPE_FUNCTION			1	//ID FUNCTION
#define TYPE_ARG				2	//ID ARG
#define TYPE_EXTERN_FUNCTION	3	//ID ARG

#define TYPE_INT			0	//VAR TYPE INT
#define TYPE_TAB_INT		1	//VAR TYPE INT[]
#define TYPE_VOID			2	//VAR TYPE INT[]

//SYMBOL TABLE
typedef	struct	s_symbol_table_elem
{
	char	*name;
	char	type_symbol;
	char	type;
	short 	nb_args;
	int		line_declaration;
	struct s_symbol_table_elem*	next;
}				t_symbol_table_elem;

#define SYMBOL_TYPE_GLOBAL		0
#define SYMBOL_TYPE_FUNCTION	1
#define SYMBOL_TYPE_ARG			2
#define SYMBOL_TYPE_LOCAL		3

typedef	struct	s_symbol_table
{
	int					size;
	char				type_table;
	t_symbol_table_elem		*begin;
	t_symbol_table_elem		*end;
}				t_symbol_table;

typedef struct stack_symbol_table
{
	t_symbol_table	*table;
	struct stack_symbol_table	*next;
}				t_stack_symbol_table;

typedef	struct	s_declaration
{
	int	type;
	char	*name;
}				t_declaration;

// Program structure
typedef	struct	s_data
{
	t_symbol_table	**table;
	t_tree			*ast;	
	char			is_main;
}				t_data;

#endif