%{
	#include "compiler.h"
	#include <stdio.h>
	#include <unistd.h>
	#define YYDEBUG 1
%}
%union	
{
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
%type <tree> programme liste_declarations liste_fonctions declaration liste_declarateurs declarateur fonction liste_parms parm liste_instructions instruction iteration selection saut affectation bloc appel variable expression liste_expressions condition function_param parm_call_function_list_expression
%type <inttype>	type binary_op binary_rel binary_comp
%%
programme	:	
		liste_declarations liste_fonctions 	{
								t_tree	*end =  $2;
								print_tree(end, 0);
								$$ = end;
							}
;
liste_declarations	:	
		liste_declarations declaration 	   { 
											 	$$ = create_parent_tree($1, $2, LIST_DECLARATION_NODE, NULL); 
										   }
	|										{	$$ = (t_tree*)0;	}	
;
liste_fonctions	:	
		liste_fonctions fonction			{
												$$ = create_parent_tree($1, $2, LIST_FUNCTION_NODE, NULL);
											}	
| 		fonction 							{ $$ = $1; }
;
declaration	:	
		type liste_declarateurs ';'		{	$$ = $2;	}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur	{
												$$ = create_parent_tree($1, $3, LIST_DECLARATION_NODE, NULL);
											}
	|	declarateur							{	$$ = $1;	}
;
declarateur	:	
		IDENTIFICATEUR							{
													t_declaration* dec = malloc(sizeof(t_declaration));
													dec->type = TYPE_INT;
													dec->name = yylval.id;
													$$ = create_parent_tree(NULL, NULL, VAR_DECLARATEUR_NODE, dec);
												
												}
	|	declarateur'[' CONSTANTE ']'			{	
									int	*constante = malloc(sizeof(int));
									*constante = yylval.inttype;
									t_tree	*sub = $1;
									//IF PREVIOUS STEP WAS AN IDENTIFICATOR
									if (((t_declaration*)((t_node*)sub->content)->datas)->type == TYPE_INT)
									{
										t_declaration	*dec = malloc(sizeof(t_declaration));
										dec->name = ((t_declaration*)((t_node*)sub->content)->datas)->name;
										dec->type = TYPE_TAB_INT;
										$$ = create_parent_tree(create_parent_tree(NULL, NULL, CONST_NODE, constante), NULL, VAR_DECLARATEUR_NODE, dec);
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
fonction	:	
		type IDENTIFICATEUR '(' function_param')' '{' liste_declarations liste_instructions '}'
		{
			t_declaration *func = malloc(sizeof(t_declaration));
			func->name = yylval.id;
			func->type = $1;
			t_tree *res = $8;
			((t_node*)res->content)->datas = func;
			((t_node*)res->content)->type = LIST_FUNCTION_NODE;
			$$ = res;
		}
	|	EXTERN type IDENTIFICATEUR '(' function_param ')' ';' 	{
										$$ = (t_tree*)0;
									}
;
type	:	
		VOID	{ $$ = TYPE_VOID;}
	|	INT		{ $$ = TYPE_INT;}
;
function_param:
			liste_parms 	{	$$ = $1;	}
	|				    	{				}
;
liste_parms	:	
		liste_parms ',' parm	{
									$$ = create_parent_tree($1, $3, LIST_PARAM_NODE, NULL);
								}
	|	parm					{
									$$ = $1;
								}	
;
parm	:	
		INT IDENTIFICATEUR		{ 
									t_declaration *arg = malloc(sizeof(t_declaration));
									arg->name = yylval.id;
									arg->type = TYPE_INT;
									$$ = create_parent_tree(NULL, NULL, ARG_NODE, arg);
								}
;
liste_instructions :	
		liste_instructions instruction	{ 
											$$ = create_parent_tree($1, $2, LIST_INSTRUCTION_NODE, NULL);
										}
	|									{	$$ = (t_tree*)0;	}
;
instruction	:	
		iteration 		{ $$ = $1;}
	|	selection		{ $$ = $1;}
	|	saut			{ $$ = $1;}
	|	affectation ';'	{ $$ = $1;}
	|	bloc			{ $$ = $1;}
	|	appel ';'		{ $$ = $1;}
;
iteration	:	
		FOR '(' affectation ';' condition ';' affectation ')' instruction {
																		$$ = create_parent_tree(create_parent_tree(create_parent_tree($3, $5, FOR_NODE, NULL), $7, FOR_NODE, NULL), $9, FOR_NODE, NULL);
																		}
	|	WHILE '(' condition ')' instruction {
												$$ = create_parent_tree($3, $5, WHILE_NODE, NULL);
											}
;
selection	:	
		IF '(' condition ')' instruction %prec THEN			{ $$ = create_parent_tree($3, $5, IF_NODE, NULL); }
	|	IF '(' condition ')' instruction ELSE instruction	{ $$ = create_parent_tree(create_parent_tree($3,$5,IF_NODE, NULL),create_parent_tree($7, NULL, ELSE_NODE, NULL),IF_NODE,NULL); }
	|	SWITCH '(' expression ')' instruction				{ $$ = create_parent_tree($3, $5, SWITCH_NODE, NULL); }
	|	CASE CONSTANTE ':' instruction						{ 
																int	*constante = malloc(sizeof(int));
																*constante = yylval.inttype;
																$$ = create_parent_tree(NULL, $4, CASE_NODE, constante);
															}
	|	DEFAULT ':' instruction								{ $$ = create_parent_tree(NULL, $3, DEFAULT_NODE, NULL); }
;
saut	:	
		BREAK ';'				{ $$ = create_parent_tree(NULL, NULL, BREAK_NODE, NULL); }
	|	RETURN ';'				{ $$ = create_parent_tree(NULL, NULL, RETURN_NODE, NULL); }
	|	RETURN expression ';'	{ $$ = create_parent_tree(NULL, $2, RETURN_NODE, NULL); }
;
affectation	:	
		variable '=' expression	{ $$ = create_parent_tree($1, $3, ASSIGN_NODE, NULL); }
;
bloc	:	
		'{' liste_declarations liste_instructions '}'	{ 
															t_tree	*res = $3;
															((t_node*)res->content)->type = BLOCK_NODE;
															$$ = $3;
														}
;
appel	:	
		IDENTIFICATEUR '(' parm_call_function_list_expression ')' 	{ 
															t_declaration	*dec = malloc(sizeof(t_declaration));
															dec->name = yylval.id;
															$$ = create_parent_tree(NULL, $3, CALL_NODE, dec);
														}
;
variable	:	
		IDENTIFICATEUR				{
										t_declaration	*dec = malloc(sizeof(t_declaration));
										dec->name = yylval.id;
										dec->type = TYPE_INT;
										$$ = create_parent_tree(NULL, NULL, VAR_NODE, dec);	
									}
	|	variable '[' expression ']'	{	
										t_tree	*sub = $1;
										//IF PREVIOUS STEP WAS AN IDENTIFICATOR
										if (((t_declaration*)((t_node*)sub->content)->datas)->type == TYPE_INT)
										{
											t_declaration	*dec = malloc(sizeof(t_declaration));
											dec->name = ((t_declaration*)((t_node*)sub->content)->datas)->name;
											dec->type = TYPE_TAB_INT;
											$$ = create_parent_tree($3, NULL, VAR_NODE, dec);		
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
	|	MOINS expression							{ $$ = create_parent_tree(NULL, $2, OPP_NODE, NULL);}
	|	CONSTANTE									{
														int *constante = malloc(sizeof(int));
														*constante = yylval.inttype;
														$$ = create_parent_tree(NULL, NULL, CONST_NODE, constante);
													}
	|	variable									{	$$ = $1; 	}
	|	appel										{	$$ = $1;	}
;
parm_call_function_list_expression	:
		liste_expressions							{	$$ = $1;			}
	|												{	$$ = (t_tree*)0;	}
liste_expressions	:	
		liste_expressions ',' expression			{ $$ = create_parent_tree($3, $1, LIST_EXPRESSION_NODE, NULL); }
	|	expression									{ $$ = $1; }
;
condition	:	
		NOT '(' condition ')'						{ $$ = create_parent_tree(NULL, $3, NOT_NODE, NULL);}	
	|	condition binary_rel condition %prec REL	{ $$ = create_parent_tree($1, $3, $2, NULL);		}
	|	'(' condition ')'							{ $$ = $2; }
	|	expression binary_comp expression			{ $$ = create_parent_tree($1, $3, $2, NULL);}
;
binary_op	:	
		PLUS 	{$$ = ADD_NODE;}
	|   MOINS	{$$ = MINUS_NODE;}
	|	MUL		{$$ = MULT_NODE;}
	|	DIV		{$$ = DIV_NODE;}
	|   LSHIFT	{$$ = LSHIFT_NODE;}
	|   RSHIFT	{$$ = RSHIFT_NODE;}
	|	BAND	{$$ = BAND_NODE;}
	|	BOR		{$$ = BOR_NODE;}
;
binary_rel	:	
		LAND	{ $$ = BOOL_AND_NODE;}
	|	LOR		{ $$ = BOOL_OR_NODE; }
;
binary_comp	:	
		LT		{ $$ = BOOL_L_NODE;}
	|	GT		{ $$ = BOOL_G_NODE;}
	|	GEQ		{ $$ = BOOL_GE_NODE;}
	|	LEQ		{ $$ = BOOL_LE_NODE;}
	|	EQ 		{ $$ = BOOL_EQ_NODE;}
	|	NEQ 	{ $$ = BOOL_NEQ_NODE;}
;
%%

#include "lex.yy.c"

void yyerror(char *s)
{
	printf("erreur : %s, ligne %d\n", s, yylineno);
	exit (1);
}

int main(int argc, char **argv)
{
	yydebug = 1;
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
		t_tree *ast= yyparse();
		fclose(yyin);
	}
	return 0;
}
