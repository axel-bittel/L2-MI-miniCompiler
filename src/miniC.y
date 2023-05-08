%{
	#include "compiler.h"
	#include <stdio.h>
	#include <unistd.h>
	#define YYDEBUG 1

	t_tree	*ast;
	t_symbol_table	*global_symbol_table;
%}

%union	{
			int 	inttype;
			char	*id;
			t_tree	*tree;
		}
%token IDENTIFICATEUR CONSTANTE VOID INT FOR WHILE IF ELSE SWITCH CASE DEFAULT
%token BREAK RETURN PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT
%token GEQ LEQ EQ NEQ NOT EXTERN
%left PLUS MOINS
%left MUL DIV
%left LSHIFT RSHIFT
%left BOR BAND
%left LAND LOR
%nonassoc THEN
%nonassoc ELSE
%left OP
%left REL
%start programme
%type <tree> programme liste_declarations liste_fonctions declaration liste_declarateurs declarateur fonction liste_parms parm liste_instructions instruction iteration selection saut affectation bloc appel variable expression liste_expressions condition function_param parm_call_function_list_expression case_instruction case_selection case_liste_instructions const
%type <inttype>	type binary_op binary_rel binary_comp
%type <id> name
%%

programme :	
		liste_declarations liste_fonctions 					{
																t_tree	*end =  create_parent_tree(NULL, $2, ROOT_NODE, NULL);
																t_symbol_table *table = global_symbol_table;
																// Si on a pas de table globale, on en crée une
																// Peut ne pas exister si pas de extern
																if (!table)
																	table = create_symbol_table(SYMBOL_TYPE_GLOBAL);
																((t_node*)end->content)->table = table;
																symbol_list_declaration_rec($1, table);
																free_tree($1);
																symbol_list_fonction_rec($2, table);
																ast = end;
																$$ = end;
															}
;

liste_declarations :	
		liste_declarations declaration 	   					{	$$ = create_parent_tree($1, $2, LIST_DECLARATION_NODE, NULL);	}
	|														{	$$ = (t_tree*)0;												}	
;

liste_fonctions :	
		liste_fonctions fonction							{
																if ($1 && $2)
																	$$ = create_parent_tree($1, $2, LIST_FUNCTION_NODE, NULL);
																else if ($1)
																	$$ = $1;
																else if ($2)
																	$$ = $2;
															}	
	|	fonction 											{	$$ = $1;	}
;

declaration :	
		type liste_declarateurs ';'							{	$$ = $2;	}
;

liste_declarateurs :	
		liste_declarateurs ',' declarateur					{	$$ = create_parent_tree($1, $3, LIST_DECLARATION_NODE, NULL);	}
	|	declarateur											{	$$ = $1;														}
;

declarateur :	
		IDENTIFICATEUR										{
																t_declaration* dec = malloc(sizeof(t_declaration));
																dec->type = TYPE_INT;
																dec->name = strdup(yylval.id);
																$$ = create_parent_tree(NULL, NULL, VAR_DECLARATEUR_NODE, dec);
															
															}
	|	declarateur'[' CONSTANTE ']'						{	
																int	*constante = malloc(sizeof(int));
																*constante = yylval.inttype;
																t_tree	*sub = $1;
																//IF PREVIOUS STEP WAS AN IDENTIFICATOR
																if (((t_declaration*)((t_node*)sub->content)->datas)->type == TYPE_INT)
																{
																	t_declaration	*dec = malloc(sizeof(t_declaration));
																	dec->name = strdup(((t_declaration*)((t_node*)sub->content)->datas)->name);
																	dec->type = TYPE_TAB_INT;
																	$$ = create_parent_tree($1,create_parent_tree(create_parent_tree(NULL, NULL, CONST_NODE, constante), NULL, TAB_INT_DATA_NODE, NULL), VAR_DECLARATEUR_NODE, dec);
																}
																else if (((t_declaration*)((t_node*)sub->content)->datas)->type == TYPE_TAB_INT)
																{
																	t_tree	*inter = sub;
																	while (inter->f_b)
																		inter = inter->f_b;
																	inter->f_b = create_parent_tree(create_parent_tree(NULL, NULL, CONST_NODE, constante), NULL, TAB_INT_DATA_NODE, NULL);
																	$$ = sub;
																}
															}
;

name :
		IDENTIFICATEUR										{	$$ = yylval.id;		}
;

fonction :	
		type name '(' function_param ')' '{' liste_declarations liste_instructions '}'
		{
			t_declaration *func = malloc(sizeof(t_declaration));
			func->name = $2;
			func->type = $1;
			func->cst = get_number_args_decl($4);
			t_tree *res = $8;
			if (!res)
				res = create_parent_tree(NULL, NULL, FUNCTION_NODE, func);
			((t_node*)res->content)->datas = func;
			((t_node*)res->content)->type = FUNCTION_NODE;
			t_symbol_table	*table_function = ((t_node*)res->content)->table;
			if (!table_function)
			{
				table_function = create_symbol_table(SYMBOL_TYPE_FUNCTION);
			}
			symbol_list_declaration_rec($7, table_function);
			free_tree($7);
			symbol_list_param_rec($4, table_function);
			free_tree($4);
			((t_node*)res->content)->table = table_function;
			$$ = res;
		}
	|	EXTERN type name '(' function_param ')' ';' 	
		{
			// Si on a pas de table globale, on en crée une
			// n'existe pas si premier extern
			if (!global_symbol_table)
				global_symbol_table = create_symbol_table(SYMBOL_TYPE_GLOBAL);
			t_symbol_table_elem *new_elem = create_symbol_table_element($3, $2, TYPE_FUNCTION, get_number_args_decl($5), 0);
			free_tree($5);
			add_element_in_symbol_table(global_symbol_table, new_elem);
			$$ = (t_tree*)0;
		}
;

type :	
		VOID												{	$$ = TYPE_VOID;		}
	|	INT													{	$$ = TYPE_INT;		}
;

function_param :
		liste_parms		 									{	$$ = $1;			}
	|				    									{	$$ = (t_tree*)0;	}
;

liste_parms :	
		liste_parms ',' parm								{	$$ = create_parent_tree($1, $3, LIST_PARAM_NODE, NULL);	}
	|	parm												{	$$ = $1;												}	
;

parm :	
		INT IDENTIFICATEUR									{ 
																t_declaration *arg = malloc(sizeof(t_declaration));
																arg->name = yylval.id;
																arg->type = TYPE_INT;
																$$ = create_parent_tree(NULL, NULL, ARG_NODE, arg);
															}
;

liste_instructions :	
		liste_instructions instruction						{	$$ = create_parent_tree($1, $2, LIST_INSTRUCTION_NODE, NULL);	}
	|														{	$$ = (t_tree*)0;												}
;

instruction :	
		iteration 											{	$$ = $1;	}
	|	selection											{	$$ = $1;	}
	|	saut												{	$$ = $1;	}
	|	affectation ';'										{	$$ = $1;	}
	|	bloc												{	$$ = $1;	}
	|	appel ';'											{	$$ = $1;	}
;

iteration :	
		FOR '(' affectation ';' condition ';' affectation ')' instruction 
															{	$$ = create_parent_tree(create_parent_tree(create_parent_tree($3, $5, FOR_DATA_NODE, NULL), $7, FOR_DATA_NODE, NULL), $9, FOR_NODE, NULL);	}
	|	WHILE '(' condition ')' instruction 				{	$$ = create_parent_tree($3, $5, WHILE_NODE, NULL);				}
;

case_liste_instructions :
		case_liste_instructions case_instruction			{	$$ = create_parent_tree($1, $2, LIST_INSTRUCTION_NODE, NULL);	}
	|														{	$$ = (t_tree*)0;												}
;

case_instruction :	
		iteration 											{	$$ = $1;	}
	|	case_selection										{	$$ = $1;	}
	|	saut												{	$$ = $1;	}
	|	affectation ';'										{	$$ = $1;	}
	|	appel ';'											{	$$ = $1;	}
;

case_selection :
	IF '(' condition ')' instruction %prec THEN				{ 	$$ = create_parent_tree($3, $5, IF_NODE, NULL);			}
	|	IF '(' condition ')' instruction ELSE instruction	{ 	$$ = create_parent_tree(create_parent_tree($3,$5,IF_DATA_NODE, NULL),create_parent_tree($7, NULL, ELSE_NODE, NULL),IF_NODE,NULL); }
	|	SWITCH '(' expression ')' instruction				{ 	$$ = create_parent_tree($3, $5, SWITCH_NODE, NULL);		}
;

const:
	CONSTANTE	{
					int *constante = malloc(sizeof(int));
					*constante = yylval.inttype;
					$$ = create_parent_tree(NULL, NULL, CONST_NODE, constante);
				}

selection :	
		IF '(' condition ')' instruction %prec THEN			{ 	$$ = create_parent_tree($3, $5, IF_NODE, NULL);			}
	|	IF '(' condition ')' instruction ELSE instruction	{ 	$$ = create_parent_tree(create_parent_tree($3,$5,IF_DATA_NODE, NULL),create_parent_tree($7, NULL, ELSE_NODE, NULL),IF_NODE,NULL); }
	|	SWITCH '(' expression ')' instruction				{ 	$$ = create_parent_tree($3, $5, SWITCH_NODE, NULL);		}
	|	CASE const ':' case_liste_instructions			{ 
																$$ = create_parent_tree($2, $4, CASE_NODE, NULL);
															}
	|	DEFAULT ':' case_liste_instructions					{	$$ = create_parent_tree(NULL, $3, DEFAULT_NODE, NULL);	}
;

saut :	
		BREAK ';'											{	$$ = create_parent_tree(NULL, NULL, BREAK_NODE, NULL);	}
	|	RETURN ';'											{	$$ = create_parent_tree(NULL, NULL, RETURN_NODE, NULL);	}
	|	RETURN expression ';'								{	$$ = create_parent_tree(NULL, $2, RETURN_NODE, NULL);	}
;

affectation :	
		variable '=' expression								{	$$ = create_parent_tree($1, $3, ASSIGN_NODE, NULL);		}
;

bloc :	
		'{' liste_declarations liste_instructions '}'		{ 
																t_tree	*res = $3;
																((t_node*)res->content)->type = BLOCK_NODE;
																t_symbol_table	*table = create_symbol_table(SYMBOL_TYPE_LOCAL);
																((t_node*)res->content)->table = table;
																symbol_list_declaration_rec($2, table);
																free_tree($2);
																$$ = $3;
															}
;

appel :	
		name '(' parm_call_function_list_expression ')' 	{
																t_declaration	*dec = malloc(sizeof(t_declaration));
																dec->name = $1;
																$$ = create_parent_tree(NULL, $3, CALL_NODE, dec);
															}
;

variable :	
		IDENTIFICATEUR										{
																t_declaration	*dec = malloc(sizeof(t_declaration));
																dec->name = yylval.id;
																dec->type = TYPE_INT;
																$$ = create_parent_tree(NULL, NULL, VAR_NODE, dec);	
															}
	|	variable '[' expression ']'							{	
																t_tree	*sub = $1;
																//IF PREVIOUS STEP WAS AN IDENTIFICATOR
																if (((t_declaration*)((t_node*)sub->content)->datas)->type == TYPE_INT)
																{
																	t_declaration	*dec = malloc(sizeof(t_declaration));
																	dec->name = strdup(((t_declaration*)((t_node*)sub->content)->datas)->name);
																	dec->type = TYPE_TAB_INT;
																	$$ = create_parent_tree(sub, create_parent_tree($3, NULL, TAB_INT_DATA_NODE, NULL), VAR_NODE, dec);		
																}
																else if (((t_declaration*)((t_node *)sub->content)->datas)->type == TYPE_TAB_INT)
																{
																	t_tree	*inter = sub;
																	while (inter->f_b)
																		inter = inter->f_b;
																	inter->f_b = create_parent_tree($3, NULL, TAB_INT_DATA_NODE, NULL);
																	$$ = sub;
																}
															}
;
expression	:	
		'(' expression ')'							{ $$ = $2;}
	|	expression binary_op expression %prec OP	{ 
														t_tree *node1 = $1;
														int type = $2;
														t_tree *node3 = $3;
														$$ = create_parent_tree(node1, node3, type, NULL);
													}
	|	MOINS expression							{ 
														t_tree	*exp = $2;
														if (((t_node*)exp->content)->type == CONST_NODE)
														{
															*(int*)((t_node*)exp->content)->datas *= -1;
															$$ = exp;
														}
														else
															$$ = create_parent_tree(NULL, $2, MINUS_NODE, NULL);
													}
	|	CONSTANTE									{
														int *constante = malloc(sizeof(int));
														*constante = yylval.inttype;
														$$ = create_parent_tree(NULL, NULL, CONST_NODE, constante);
													}
	|	variable									{	$$ = $1; 	}
	|	appel										{	$$ = $1;	}
;

parm_call_function_list_expression :
		liste_expressions									{	$$ = $1;			}
	|														{	$$ = (t_tree*)0;	}
;

liste_expressions :	
		liste_expressions ',' expression					{	$$ = create_parent_tree($3, $1, LIST_EXPRESSION_NODE, NULL);	}
	|	expression											{	$$ = $1;														}
;

condition :	
		NOT '(' condition ')'								{	$$ = create_parent_tree(NULL, $3, NOT_NODE, NULL);	}	
	|	condition binary_rel condition %prec REL			{	$$ = create_parent_tree($1, $3, $2, NULL);			}
	|	'(' condition ')'									{	$$ = $2; 											}
	|	expression binary_comp expression					{	$$ = create_parent_tree($1, $3, $2, NULL);			}
;

binary_op :	
		PLUS 												{	$$ = ADD_NODE;		}
	|   MOINS												{	$$ = MINUS_NODE;	}
	|	MUL													{	$$ = MULT_NODE;		}
	|	DIV													{	$$ = DIV_NODE;		}
	|   LSHIFT												{	$$ = LSHIFT_NODE;	}
	|   RSHIFT												{	$$ = RSHIFT_NODE;	}
	|	BAND												{	$$ = BAND_NODE;		}
	|	BOR													{	$$ = BOR_NODE;		}
;

binary_rel :	
		LAND												{	$$ = BOOL_AND_NODE;	}
	|	LOR													{	$$ = BOOL_OR_NODE; 	}
;

binary_comp :	
		LT													{	$$ = BOOL_L_NODE;	}
	|	GT													{	$$ = BOOL_G_NODE;	}
	|	GEQ													{	$$ = BOOL_GE_NODE;	}
	|	LEQ													{	$$ = BOOL_LE_NODE;	}
	|	EQ 													{	$$ = BOOL_EQ_NODE;	}
	|	NEQ 												{	$$ = BOOL_NEQ_NODE;	}
;

%%

#include "lex.yy.c"

void yyerror(char *s)
{
	printf("compiler: %s, ligne %d\n", s, yylineno);
	is_error = 1;
}

int	create_files(char	*name_file)
{
	char	buffer[4096] = {0};

	// Create the declaration file
	sprintf(buffer, "./%s_decla.dot", name_file);
	fileResult_decla = fopen(buffer, "w+");
	if (fileResult_decla == -1)
		return (0);

	// Create the link file
	sprintf(buffer, "./%s_link.dot", name_file);
	fileResult_link = fopen(buffer, "w+");
	if (fileResult_link == -1)
		return (0);

	// Create the final file
	sprintf(buffer, "./%s.dot", name_file);
	fileResult = fopen(buffer, "w+");
	if (fileResult == -1)
		return (0);
}

void	generate_result_file()
{
	char	buffer[4096] = {0};

	int bytesRead;
	fseek(fileResult_decla, 0, SEEK_SET);
	while ((bytesRead = fread(buffer, 1, 4096, fileResult_decla)) > 0)
		fwrite(buffer, 1, bytesRead, fileResult);
	fseek(fileResult_link, 0, SEEK_SET);
	while ((bytesRead = fread(buffer, 1, 4096, fileResult_link)) > 0)
		fwrite(buffer, 1, bytesRead, fileResult);
	fprintf(fileResult, "\n}");
}

void	cleanup_data(char	*name_file)
{
	char	buffer[4096] = {0};

	free_tree(ast);
	free_symbol_table(global_symbol_table);
	fclose(fileResult);
	fclose(fileResult_decla);
	sprintf(buffer, "./%s_decla.dot", name_file);
	remove(buffer);
	fclose(fileResult_link);
	sprintf(buffer, "./%s_link.dot", name_file);
	remove(buffer);
	if (is_error)
	{
		sprintf(buffer, "./%s.dot", name_file);
		remove(buffer);
	}
	fclose(yyin);
	ast = NULL;
	global_symbol_table = NULL;
	is_error = 0;
}

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
  	    
		yyin = fopen(argv[i], "r");
		if (yyin == NULL)
		{
			fprintf(stderr, "compiler: impossible d'ouvrir le fichier %s\n", argv[i]);
			continue ; 
		}

		#ifdef YYDEBUG
			fprintf(stdout, "\n#compiler: compilation du fichier %s\n", argv[i]);
		#endif
		yyparse();
		create_files(argv[i]);
		fprintf(fileResult, "digraph mon_programme {\n");
		fflush(fileResult);
		conver_and_sementic_analys(ast);
		if (!is_error)
			generate_result_file();
		cleanup_data(argv[i]);
	}
	return 0;
}
