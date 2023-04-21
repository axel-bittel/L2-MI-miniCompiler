%{
	#include "compiler.h"
	#include <stdio.h>
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
%type <tree> programme liste_declarations liste_fonctions declaration liste_declarateurs declarateur fonction liste_parms parm liste_instructions instruction iteration selection saut affectation bloc appel variable expression liste_expressions condition 
%type <inttype>	type binary_op binary_rel binary_comp
%%
programme	:	
		liste_declarations liste_fonctions 	{
												t_tree	*end =  create_parent_tree($1, $2, ROOT_NODE, NULL);
												print_tree(end, 0);
												$$ = end;
											}
;
liste_declarations	:	
		liste_declarations declaration 	   { 
												t_tree *tmp = $1;
												t_tree *node = $2;
												if 	(tmp)
											 		node->f_a = tmp;
											 	$$ = node;
										   }
	|										{	$$ = (t_tree*)0;	}	
;
liste_fonctions	:	
		liste_fonctions fonction			{
												t_tree *f1 = $1;
												t_tree *f2 = $2;
												$$ = create_parent_tree(f1, f2, LIST_FUNCTION_NODE, NULL);
											}	
| 		fonction 							{ $$ = $1; }
|       {
			$$ = (t_tree*)0;
		}
;
declaration	:	
		type liste_declarateurs ';'		{	$$ = $2;	}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur	{
												t_tree *l_dec = $1;
												t_tree*	dec = $3;
												dec->f_b = l_dec;
												$$ = dec;
											}
	|	declarateur							{	$$ = $1;	}
;
declarateur	:	
		IDENTIFICATEUR							{
													t_declaration* dec = malloc(sizeof(t_declaration));
													dec->type = TYPE_INT;
													dec->name = yylval.id;
													$$ = create_parent_tree(NULL, NULL, VAR_DECLARATION_NODE, dec);
												
												}
	|	declarateur'[' CONSTANTE ']'			{	
													int	*constante = nalloc(sizeof(int));
													*constante = yylval.inttype;
													$$ = create_parent_tree(NULL, $1, VAR_DECLARATION_NODE, constante);
												}
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}'
		{
			t_declaration *func = malloc(sizeof(t_declaration));
			func->name = yylval.id;
			func->type = $1;
			printf("func = %p\n", $4);
			$$ = create_parent_tree($4, create_parent_tree($7, $8, BLOCK_FUN_NODE, NULL), FUNCTION_NODE, func);
		}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' 	{
																t_declaration	*fun = malloc(sizeof(t_declaration));
																fun->name = yylval.id;
																fun->type = $2;
																$$ = create_parent_tree($5, NULL, EXTERN_FUNCTION_NODE, fun);
															}
;
type	:	
		VOID	{ $$ = TYPE_VOID;}
	|	INT		{ $$ = TYPE_INT;}
;
liste_parms	:	
		liste_parms ',' parm	{
									t_tree *parm = $1;
									t_tree *node = $3;
									node->f_a = parm;
									$$ = node;
								}
	|	parm					{
									$$ = $1;
								}	
	|							{	$$ = (t_tree*)0;	}
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
											t_tree	*node = $2;
											node->f_a = $1;
											$$ = node;
										}
	|									{	$$ = (t_tree*)0;	}
;
instruction	:	
		iteration 		{ $$ = create_parent_tree(NULL, $1, INSTRUCTION_NODE, NULL);}
	|	selection		{ $$ = create_parent_tree(NULL, $1, INSTRUCTION_NODE, NULL);}
	|	saut			{ $$ = create_parent_tree(NULL, $1, INSTRUCTION_NODE, NULL);}
	|	affectation ';'	{ $$ = create_parent_tree(NULL, $1, INSTRUCTION_NODE, NULL);}
	|	bloc			{ $$ = create_parent_tree(NULL, $1, INSTRUCTION_NODE, NULL);}
	|	appel			{ $$ = create_parent_tree(NULL, $1, INSTRUCTION_NODE, NULL);}
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
	|	IF '(' condition ')' instruction ELSE instruction	{ $$ = create_parent_tree(create_parent_tree($7, NULL, ELSE_NODE, NULL), $5, IF_NODE, $3); }
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
		'{' liste_declarations liste_instructions '}'	{ $$ = create_parent_tree($2, $3, BLOCK_NODE, NULL);}
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';'	{ 
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
										t_declaration	*dec = malloc(sizeof(t_declaration));
										dec->name = yylval.id;
										dec->type = TYPE_TAB_INT;
										$$ = create_parent_tree(NULL, $3, VAR_NODE, dec);		
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
	|	variable									{ $$ = $1; }
	|	IDENTIFICATEUR '(' liste_expressions ')'	{ 
														t_declaration	*dec = malloc(sizeof(t_declaration));
														dec->name = yylval.id;
														$$ = create_parent_tree(NULL, $3, CALL_NODE, dec); 
													}
;
liste_expressions	:	
		liste_expressions ',' expression			{ $$ = create_parent_tree($3, $1, EXP_LIST_NODE, NULL); }
	|	expression									{ $$ = create_parent_tree(NULL, $1, EXP_LIST_NODE, NULL); }
	|												{ $$ = (t_tree*)0; }
;
condition	:	
		NOT '(' condition ')'						{ $$ = create_parent_tree(NULL, $3, NOT_NODE, NULL);}	
	|	condition binary_rel condition %prec REL	{ $$ = create_parent_tree($1, $3, $2, NULL);		}
	|	'(' condition ')'							{ $$ = create_parent_tree(NULL, $2, COND_NODE, NULL);}
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
		t_tree *ast= yyparse();
		create_symbol_tables(ast);
		
		fclose(yyin);
	}
	return 0;
}
