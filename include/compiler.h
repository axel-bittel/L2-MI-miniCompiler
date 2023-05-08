#ifndef COMPILER_H
#define COMPILER_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
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
#define VAR_DECLARATEUR_NODE    26   //NODE FOR ID DECLARATION (VAR)
#define VAR_LIST_NODE           27   //NODE FOR DECLARATION OF ID (VAR)
#define ARG_NODE                28   //NODE FOR ARGUMENT OF FUNCTION
#define LIST_EXPRESSION_NODE    29   //NODE FOR LIST OF ARGUMENT OF FUNCTION
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
#define LIST_DECLARATION_NODE   44 	 //NODE FOR LIST OF DECLARATION
#define LIST_PARAM_NODE   		45 	 //NODE FOR LIST OF PARAM
#define LIST_INSTRUCTION_NODE   46 	 //NODE FOR LIST OF INSTRUCTION
#define LIST_DECLARATEUR_NODE   47 	 //NODE FOR LIST OF DECLARATEUR
#define TAB_INT_DATA_NODE	    48 	 //NODE FOR DATA IN TAB_INT DECLARATION
#define FOR_DATA_NODE	    	49 	 //NODE FOR DATA IN TAB_INT DECLARATION
#define IF_DATA_NODE	    	50 	 //NODE FOR DATA IN TAB_INT DECLARATION

struct stack_symbol_table;
struct s_list_dimension;

//AST
typedef struct	s_node
{
	char	type;
	void	*datas;
	struct s_symbol_table *table;
}				t_node;

typedef	struct	s_declaration
{
	int	type;
	char	*name;
	int		cst;
}				t_declaration;

#define TYPE_INT			0	//VAR TYPE INT
#define TYPE_TAB_INT		1	//VAR TYPE INT[]
#define TYPE_VOID			2	//TYPE VOID

//SYMBOL TABLE
typedef	struct	s_symbol_table_elem
{
	char	*name;
	char	type_identificateur;
	char	type;
	short 	nb_args;				// POUR LES FONCTIONS + EXTERN FONCTIONS
	struct s_list_dimension		*list_dimension;	// POUR LES TABLEAUX
	struct s_symbol_table_elem	*next;
}				t_symbol_table_elem;

//TYPES DES ELEMS DE LA TABLE
#define TYPE_VAR				0 	//ID VAR
#define TYPE_FUNCTION			1	//ID FUNCTION
#define TYPE_ARG				2	//ID ARG
#define TYPE_EXTERN_FUNCTION	3	//ID EXTERN FUNCTION

//TYPES DE TABLES :
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

typedef struct s_list_dimension
{
	int dim;
	struct s_list_dimension *next;
}			t_list_dimension;

// AST 
t_node	*create_new_node(int	type, void	*data);
t_tree	*create_parent_tree(t_tree	*sub_g, t_tree	*sub_d, int type, void	*data);
void    free_tree(t_tree    *tree);
void	print_tree(t_tree	*tree, int i);
void print_type(int type);

// SEMENTIC ANALYSIS
void    print_error(char *error, char   *complement);
int check_tab_dimention(t_symbol_table_elem *elem, t_tree *tree, t_stack_symbol_table *stack);
int get_type_expression(t_tree  *tree, t_stack_symbol_table *stack);
int sementic_analysis_check_return(t_tree *ast, t_stack_symbol_table *stack, int type_return);
int get_number_args(t_tree *ast);
int is_args_type_valid(t_tree *ast, t_stack_symbol_table *stack);
int conver_and_sementic_analys(t_tree *ast);
int _sementic_analysis_check_rec(t_tree *ast, t_stack_symbol_table  *stack, int actual_node);

// DIMENSION LIST
t_list_dimension *create_list_dim(int n);
t_list_dimension *push_back_list_dim(t_list_dimension *list, int n);
t_list_dimension *pop_back_list_dim(t_list_dimension *list);
void free_list_dim(t_list_dimension *list);

// SEMENTIC SYMBOLE TABLE
t_list_dimension    *create_dim_list_rec(t_tree *tree, t_list_dimension *new_list);
int symbol_list_declaration_rec (t_tree *tree, t_symbol_table *table);
int symbol_list_param_rec (t_tree *tree, t_symbol_table *table);
int symbol_list_fonction_rec (t_tree *tree, t_symbol_table *table);
int get_number_args_decl(t_tree *ast);//In a declaration

// SYMBOL TABLE
t_symbol_table *create_symbol_table(char type_table);
t_symbol_table_elem  *create_symbol_table_element(char *name, char type, char type_symbol, short nb_args, t_list_dimension *dim);
int add_element_in_symbol_table(t_symbol_table *table, t_symbol_table_elem *new_elem);
void    free_symbol_table(t_symbol_table* table);
t_symbol_table_elem  *find_element_by_id(char *id, t_symbol_table *table);

// STACK TABLE
t_stack_symbol_table *create_stack_symbol_table(t_symbol_table* table);
t_stack_symbol_table *push_stack_symbol_table(t_stack_symbol_table **stack, t_stack_symbol_table* new_stack);
t_stack_symbol_table *pop_stack_symbol_table(t_stack_symbol_table **stack);
t_symbol_table_elem *find_element_by_id_stack(t_stack_symbol_table *stack, char *id);
t_symbol_table_elem *find_table_by_id_stack(t_stack_symbol_table *stack, char *id);
void free_stack(t_stack_symbol_table *stack);

int decl_dot(t_tree *tree, int nb);
int link_dot(int node_1, int node_2);

// Global variables
extern int 	 nbNode;
extern char	 is_error;
extern FILE *fileResult_decla;
extern FILE *fileResult_link;
extern FILE *fileResult;
#endif