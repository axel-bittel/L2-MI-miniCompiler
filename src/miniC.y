%{
	#include "compiler.h"
	#include <stdio.h>
	#define YYDEBUG 1
	#define YYSTYPE int
%}
%union	
{
	int 	type;
	int		constante;
	char	*id:
	t_tree	*tree;
};
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
%type <type>	type binary_op binary_rel binary_comp
%%
programme	:	
		liste_declarations liste_fonctions { $$ = create_parent_tree($1, $2, ROOT_NODE, NULL);}
;
liste_declarations	:	
		liste_declarations declaration 	   { 
												t_tree *node = $2;
											 	node->f_a = $1;
											 	$$ = node;
										   }
	|										{	return NULL;	}	
;
liste_fonctions	:	
		liste_fonctions fonction			{
												create_parent_tree($1, $2, LIST_FUNCTION_NODE, NULL);
											}	
|               fonction					{
												$$ = $1;
											}
;
declaration	:	
		type liste_declarateurs ';'		{	$$ = $2;	}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur	{
												t_tree*	dec = $3;
												dec->f_a = $1;
												$$ = dec;
											}
	|	declarateur							{	$$ = $1;	}
;
declarateur	:	
		IDENTIFICATEUR							{
													t_declaration* dec = malloc(sizeof(t_declaration));
													dec->type = TYPE_INT;
													dec->name = yylval.id;
													$$ = create_parent_tree(NULL, NULL, VAR_DECLARATION_NODE, dec);\
												
												}
	|	IDENTIFICATEUR '[' CONSTANTE ']'		{	
													t_declaration* dec = malloc(sizeof(t_declaration));
													dec->type = TYPE_TAB_INT;
													dec->name = yylval.id;
													$$ = create_parent_tree(NULL, NULL, VAR_DECLARATION_NODE, dec);\
												}
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}'
		{
			t_declaration *func = malloc(sizeof(t_declaration));
			func->name = yylval.id;
			func->type_dec = $1;
			$$ = create_parent_tree($4, create_parent_tree($7, $8, BLOCK_FUN_NODE, NULL), FUNC_NODE, func);
		}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' 	{
																t_declaration	*fun = malloc(sizeof(t_declaration));
																fun->name = yylval.id;
																fun->type = $2;
																create_parent_tree($5, NULL, EXTERN_FUNCTION_NODE, fun);
															}
;
type	:	
		VOID	{ $$ = TYPE_VOID;}
	|	INT		{ $$ = TYPE_INT;}
;
liste_parms	:	
		liste_parms ',' parm	{}
	|	
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
	|
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
		FOR '(' affectation ';' condition ';' affectation ')' instruction
	|	WHILE '(' condition ')' instruction
;
selection	:	
		IF '(' condition ')' instruction %prec THEN			{ $$ = create_parent_tree($3, $5, IF_NODE, NULL); }
	|	IF '(' condition ')' instruction ELSE instruction	{ $$ = create_parent_tree(create_parent_tree($7, NULL, ELSE_NODE, NULL), $5, IF_NODE, $3); }
	|	SWITCH '(' expression ')' instruction
	|	CASE CONSTANTE ':' instruction
	|	DEFAULT ':' instruction
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
		IDENTIFICATEUR '(' liste_expressions ')' ';'	{ $$ = create_parent_tree(yylval.id, $3, CALL_NODE, NULL); }
;
variable	:	
		IDENTIFICATEUR				{
										t_declaration	*dec = malloc(sizeof(t_declaration));
										dec->name = yylval.id;
										dec->name = yylval.id;
										dec->type = TYPE_INT;
										$$ = create_parent_tree(NULL, NULL, VAR_NODE, dec);	
									}
	|	variable '[' expression ']'	{	return NULL;	}
;
expression	:	
		'(' expression ')'
	|	expression binary_op expression %prec OP	{ $$ = create_parent_tree($1, $3, $2, NULL);}
	|	MOINS expression							{ $$ = create_parent_tree(NULL, $2, OPP_NODE, NULL);}
	|	CONSTANTE									{
														int *constante = malloc(sizeof(int));
														*constante = yylval.constante;
														$$ = create_parent_tree(NULL, NULL, CONST_NODE, yylval.constante);
													}
	|	variable									{ $$ = create_parent_tree(NULL, $1, ID_NODE, NULL);}
	|	IDENTIFICATEUR '(' liste_expressions ')'	{ $$ = create_parent_tree(yylval.id, $3, CALL_NODE, NULL); }
;
liste_expressions	:	
		liste_expressions ',' expression			{ $$ = create_parent_tree($3, $1, EXP_LIST_NODE, NULL); }
	|
;
condition	:	
		NOT '(' condition ')'						{ $$ = create_parent_tree(NULL, $3, NOT_NODE, NULL);}	
	|	condition binary_rel condition %prec REL	{ $$ = create_parent_tree($1, $3, $2, NULL);		}
	|	'(' condition ')'							{ $$ = create_parent_tree(NULL, $2, COND_NODE, NULL);)}
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
		LAND	{ $$ = LAND_NODE;}
	|	LOR		{ $$ = LOR_NODE; }
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
	yydebug = 1;
	for (int i = 1; i < argc; i++)
	{
		yyin = fopen(argv[i], "r");
		if (yyin == NULL)
		{
			fprintf(stderr, "compiler: impossible d'ouvrir le fichier %s\n", argv[i]);
			continue ; 
		}
		yyparse();
		fclose(yyin);
	}
	return 0;
}
