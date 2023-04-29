%{
	#include "compiler.h"
	#include <stdio.h>
	#include <unistd.h>
	#define YYDEBUG 1
	//t_stack_symbol_table *stack_table = create_stack_symbol_table(NULL);
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
%type <tree> programme liste_declarations liste_fonctions declaration liste_declarateurs declarateur fonction liste_parms parm liste_instructions instruction iteration selection saut affectation bloc appel variable expression liste_expressions condition function_param parm_call_function_list_expression
%type <inttype>	type binary_op binary_rel binary_comp


%%
<<<<<<< Updated upstream
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
=======


programme :
		liste_declarations liste_fonctions 					{
																t_tree	*end =  create_parent_tree($1, $2, ROOT_NODE, NULL);
																print_tree(end, 0);
																
																//t_symbol_table *programme_table = create_symbol_table(SYMBOL_TYPE_GLOBAL);
																//symbol_list_declaration_rec ($1, programme_table);

																$$ = end;
															}
;

liste_declarations :	
		liste_declarations declaration 	   					{ 
																$$ = create_parent_tree($1, $2, LIST_DECLARATION_NODE, NULL); 
															}
	|	declaration											{	
																$$ = $1; 
															}
	|														{ 	$$ = (t_tree*)0;	}	
;

liste_fonctions :	
		liste_fonctions fonction							{
																$$ = create_parent_tree($1, $2, LIST_FUNCTION_NODE, NULL);
															}	
	|	fonction 											{	$$ = $1;	}
	|   													{
																$$ = (t_tree*)0;
															}
>>>>>>> Stashed changes
;

declaration :	
		type liste_declarateurs ';'							{	$$ = $2;	}
;

liste_declarateurs :	
		liste_declarateurs ',' declarateur					{
																$$ = create_parent_tree($1, $3, LIST_DECLARATION_NODE, NULL);
															}
	|	declarateur											{	$$ = $1;	}
;
<<<<<<< Updated upstream
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
=======

declarateur :	
		IDENTIFICATEUR										{
																t_declaration* dec = malloc(sizeof(t_declaration));
																dec->type = TYPE_INT;
																dec->name = yylval.id;
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

																//t_symbol_table *current_table = stack_table->table;
																//t_symbol_table_elem *current_elem = create_symbol_table_element(dec->name, dec->type, char type_symbol)

															}
;

fonction :	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}'
															{
																t_declaration *func = malloc(sizeof(t_declaration));
																func->name = yylval.id;
																func->type = $1;
																printf("func = %p\n", $4);
																//t_symbol_table *function_table = create_symbol_table(SYMBOL_TYPE_FUNCTION);
																//t_symbol_table_elem  *new_elem = create_symbol_table_element(func->name, func->type, TYPE_FUNCTION, ???);
																//create_symbol_table_function(list_parms, fonction_table)
																//create_symbol_table_function(list_declaration, fonction_table)
																//add_element_in_symbol_table(*function_table, *new_elem);
																//t_stack_symbol_table *function_stack = create_stack_symbol_table(function_table);
																//*stack_table = push_stack_symbol_table(*stack_table, *function_stack);
																t_tree *res = create_parent_tree($4, create_parent_tree($7, $8, BLOCK_FUN_NODE, NULL), FUNCTION_NODE, func);
																// Link table with node
																((t_node*)res->content)->table = res;
																$$ = res;
															}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' 	{
																t_declaration	*fun = malloc(sizeof(t_declaration));
																fun->name = yylval.id;
																fun->type = $2;
																$$ = create_parent_tree($5, NULL, EXTERN_FUNCTION_NODE, fun);
																//t_symbol_table *ext_function_table = create_symbol_table(SYMBOL_TYPE_FUNCTION);
																//t_symbol_table_elem  *new_elem = create_symbol_table_element(func->name, func->type, TYPE_EXTERN_FUNCTION, ???);
																//add_element_in_symbol_table(*ext_function_table, *new_elem);
																//t_stack_symbol_table *ext_function_stack = create_stack_symbol_table(*ext_function_table);
																//*stack_table = push_stack_symbol_table(*stack_table, *ext_function_stack);
															}
>>>>>>> Stashed changes
;

type :	
		VOID												{	$$ = TYPE_VOID;	}
	|	INT													{	$$ = TYPE_INT;	}
;
<<<<<<< Updated upstream
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
=======

liste_parms	:	
		liste_parms ',' parm								{
																$$ = create_parent_tree($1, $3, LIST_PARAM_NODE, NULL);
															}
	|	parm												{
																$$ = $1;
															}	
	|														{	$$ = (t_tree*)0;	}
>>>>>>> Stashed changes
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
		liste_instructions instruction						{ 
																$$ = create_parent_tree($1, $2, LIST_INSTRUCTION_NODE, NULL);
															}
	|														{	$$ = (t_tree*)0;	}
;
<<<<<<< Updated upstream
instruction	:	
		iteration 		{ $$ = $1;}
	|	selection		{ $$ = $1;}
	|	saut			{ $$ = $1;}
	|	affectation ';'	{ $$ = $1;}
	|	bloc			{ $$ = $1;}
	|	appel ';'		{ $$ = $1;}
=======

instruction :	
		iteration 											{	$$ = $1;	/*here*/}
	|	selection											{	$$ = $1;	/*here*/} 
	|	saut												{	$$ = $1;	}
	|	affectation ';'										{	$$ = $1;	}
	|	bloc												{	$$ = $1;	/*here*/}
	|	appel												{	$$ = $1;	}
>>>>>>> Stashed changes
;

iteration :	
		FOR '(' affectation ';' condition ';' affectation ')' instruction 
															{
																$$ = create_parent_tree(create_parent_tree(create_parent_tree($3, $5, FOR_NODE, NULL), $7, FOR_NODE, NULL), $9, FOR_NODE, NULL);
																//t_symbol_table *for_table = create_symbol_table(SYMBOL_TYPE_LOCAL);
																//t_stack_symbol_table *for_stack = create_stack_symbol_table(*local_block_table);
																//*stack_table = push_stack_symbol_table(*stack_table, *local_block_stack);
															}
	|	WHILE '(' condition ')' instruction 				{
																$$ = create_parent_tree($3, $5, WHILE_NODE, NULL);
															}
;

selection :	
		IF '(' condition ')' instruction %prec THEN			{ 	$$ = create_parent_tree($3, $5, IF_NODE, NULL);	}
	|	IF '(' condition ')' instruction ELSE instruction	{ 	$$ = create_parent_tree(create_parent_tree($3,$5,IF_NODE, NULL),create_parent_tree($7, NULL, ELSE_NODE, NULL),IF_NODE,NULL); }
	|	SWITCH '(' expression ')' instruction				{ 	$$ = create_parent_tree($3, $5, SWITCH_NODE, NULL);	}
	|	CASE CONSTANTE ':' instruction						{ 
																int	*constante = malloc(sizeof(int));
																*constante = yylval.inttype;
																$$ = create_parent_tree(NULL, $4, CASE_NODE, constante);
															}
	|	DEFAULT ':' instruction								{	$$ = create_parent_tree(NULL, $3, DEFAULT_NODE, NULL);	}
;

saut :	
		BREAK ';'											{	$$ = create_parent_tree(NULL, NULL, BREAK_NODE, NULL);	}
	|	RETURN ';'											{	$$ = create_parent_tree(NULL, NULL, RETURN_NODE, NULL);	}
	|	RETURN expression ';'								{	$$ = create_parent_tree(NULL, $2, RETURN_NODE, NULL);	}
;

affectation	:	
		variable '=' expression								{	$$ = create_parent_tree($1, $3, ASSIGN_NODE, NULL);	}
;
<<<<<<< Updated upstream
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
=======

bloc :	
		'{' liste_declarations liste_instructions '}'	
															{ 
																$$ = create_parent_tree($2, $3, BLOCK_NODE, NULL);
																//t_symbol_table *local_block_table = create_symbol_table(SYMBOL_TYPE_LOCAL);
																//t_stack_symbol_table *local_block_stack = create_stack_symbol_table(*local_block_table);
																//*stack_table = push_stack_symbol_table(*stack_table, *local_block_stack);
															}
;

appel :	
		IDENTIFICATEUR '(' liste_expressions ')' ';'		{ 
																t_declaration	*dec = malloc(sizeof(t_declaration));
																dec->name = yylval.id;
																$$ = create_parent_tree(NULL, $3, CALL_NODE, dec);
															}
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
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
=======

expression :	
		'(' expression ')'									{	$$ = $2;	}
	|	expression binary_op expression %prec OP			{ 
																t_tree *node1 = $1;
																int type = $2;
																t_tree *node3 = $3;
																$$ = create_parent_tree(node1, node3, type, NULL);
															}
	|	MOINS expression									{	$$ = create_parent_tree(NULL, $2, OPP_NODE, NULL);	}
	|	CONSTANTE											{
																int *constante = malloc(sizeof(int));
																*constante = yylval.inttype;
																$$ = create_parent_tree(NULL, NULL, CONST_NODE, constante);
															}
	|	variable											{	$$ = $1;	}
	|	IDENTIFICATEUR '(' liste_expressions ')'			{ 
																t_declaration	*dec = malloc(sizeof(t_declaration));
																dec->name = yylval.id;
																$$ = create_parent_tree(NULL, $3, CALL_NODE, dec); 
															}
;

liste_expressions :	
		liste_expressions ',' expression					{	$$ = create_parent_tree($3, $1, LIST_EXPRESSION_NODE, NULL);	}
	|	expression											{	$$ = $1;														}
	|														{	$$ = (t_tree*)0;												}
>>>>>>> Stashed changes
;

condition :	
		NOT '(' condition ')'								{	$$ = create_parent_tree(NULL, $3, NOT_NODE, NULL);				}	
	|	condition binary_rel condition %prec REL			{	$$ = create_parent_tree($1, $3, $2, NULL);						}
	|	'(' condition ')'									{	$$ = $2; }
	|	expression binary_comp expression					{	$$ = create_parent_tree($1, $3, $2, NULL);						}
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
	printf("erreur : %s, ligne %d\n", s, yylineno);
	exit (1);
}


char decl_dot(t_tree *tree, FILE *f, int nb)
{
	int type = ((t_node*)tree->content)->type;
    switch (type)
	nb += 1;
	{
		case COND_NODE:
            


        case IF_NODE:
            fprintf(f,"node_%d [shape=diamond label=\"IF\"]\n",nb);
            return("node_%d");

        case ELSEIF_NODE:
            


        case ELSE_NODE:
            


        case RETURN_NODE:
            printf(f,"\tnode_%d [label=\"RETURN\" shape=trapezium color=blue];\n",nb);
            return("node_%d");

        case CALL_NODE:
            fprintf(f,"\tnode_%d [label=\"%s\" shape=septagon];\n",nb,(t_node*)tree->content);
            return("node_%d");

        case ADD_NODE:
            fprintf(f,"\tnode_%d [label=\"+\" shape=ellipse];\n",nb);
            return("node_%d");

        case MINUS_NODE:
            fprintf(f,"\tnode_%d [label=\"-\" shape=ellipse];\n",nb);
            return("node_%d");

        case MULT_NODE:
            fprintf(f,"\tnode_%d [label=\"*\" shape=ellipse];\n",nb);
            return("node_%d");

        case DIV_NODE:
            fprintf(f,"\tnode_%d [label=\"/\" shape=ellipse];\n",nb);
            return("node_%d");

        case ASSIGN_NODE:
            fprintf(f,"\tnode_%d [label=\":=\" shape=ellipse];\n",nb);
            return("node_%d");

        case RSHIFT_NODE:
            fprintf(f,"\tnode_%d [label=\">>\" shape=ellipse];\n",nb);
            return("node_%d");

        case LSHIFT_NODE:
            fprintf(f,"\tnode_%d [label=\"<<\" shape=ellipse];\n",nb);
            return("node_%d");

        case BAND_NODE:
            fprintf(f,"\tnode_%d [label=\"&\" shape=ellipse];\n",nb);
            return("node_%d");

        case BOR_NODE:
            fprintf(f,"\tnode_%d [label=\"|\" shape=ellipse];\n",nb);
            return("node_%d");

        case NOT_NODE:
            fprintf(f,"\tnode_%d [label=\"!\" shape=ellipse];\n",nb);
            return("node_%d");

        case OPP_NODE:
            


        case BOOL_EQ_NODE:
            fprintf(f,"\tnode_%d [label=\"==\" shape=ellipse];\n",nb);
            return("node_%d");

        case BOOL_L_NODE:
            fprintf(f,"\tnode_%d [label=\"<\" shape=ellipse];\n",nb);
            return("node_%d");

        case BOOL_G_NODE:
            fprintf(f,"\tnode_%d [label=\">\" shape=ellipse];\n",nb);
            return("node_%d");

        case BOOL_LE_NODE:
            fprintf(f,"\tnode_%d [label=\"<=\" shape=ellipse];\n",nb);
            return("node_%d");

        case BOOL_GE_NODE:
            fprintf(f,"\tnode_%d [label=\">=\" shape=ellipse];\n",nb);
            return("node_%d");

        case BOOL_AND_NODE:
            fprintf(f,"\tnode_%d [label=\"&&\" shape=ellipse];\n",nb);
            return("node_%d");

        case BOOL_OR_NODE:
            fprintf(f,"\tnode_%d [label=\"||\" shape=ellipse];\n",nb);
            return("node_%d");

        case BOOL_NEQ_NODE:
            fprintf(f,"\tnode_%d [label=\"!=\" shape=ellipse];\n",nb);
            return("node_%d");

        case INSTRUCTION_NODE:
            


        case FUNCTION_NODE:
            


        case EXTERN_FUNCTION_NODE:
            


        case LIST_FUNCTION_NODE:
            


        case WHILE_NODE:
            fprintf(f,"\tnode_%d [label=\"WHILE\" shape=ellipse];\n",nb);
            return("node_%d");

        case FOR_NODE:
            fprintf(f,"\tnode_%d [label=\"FOR\" shape=ellipse];\n",nb);
            return("node_%d");

		case CONST_NODE:
			fprintf(f,"\tnode_%d [shape=ellipse label=\"%s\"]\n",nb,((t_node*)tree->content)->datas);
			return ("node_%d",nb);

        case VAR_DECLARATEUR_NODE:
            fprintf(f,"\tnode_%d [shape=ellipse label=\"%s\"]\n",nb,((t_node*)tree->content)->datas);
			return ("node_%d",nb);

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

        default:
            printf("%d", type);
            break;
	}
	
}


int link_dot(char node_1, char node_2, FILE *f)
{
	fprintf(f,"%s ->  %s\n", node_1, node_2);
	return(0);
}


int create_dot(t_tree *tree, FILE *f_decla, FILE *f_link, FILE *f, int nb)
{
	char node_parent = decl_dot(tree, f_decla, nb);
	char node_f1 = decl_dot(tree->f_a, f_decla, nb);
	char node_f2 = decl_dot(tree->f_b, f_decla, nb);
	link_dot(node_parent, node_f1, f_link);
	link_dot(node_parent, node_f2, f_link);
	create_dot(tree->f_a, f_decla, f_link, f, nb);
	create_dot(tree->f_b, f_decla, f_link, f, nb);
	fclose(f_decla);
	fclose(f_link);
	char ctn;
	f_decla = fopen("./decla.txt", "r");
	f_link = fopen("./link.txt", "r");
	while((ctn = getc(f_decla)) != EOF)
        putc(ctn, f);
	while((ctn = getc(f_link)) != EOF)
        putc(ctn, f);
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
		t_tree *ast = yyparse();
		fclose(yyin);
	}

	t_tree	*tree = create_parent_tree(NULL, NULL, FUNCTION_NODE, "Fonction");

	FILE *f_decla, *f_link, *f;
    f_decla = fopen("./decla.txt", "w");
	f_link = fopen("./link.txt", "w");
	f = fopen("./test.txt", "w");
	fprintf(f, "digraph mon_programme {\n");
	create_dot(tree, f);
	fprintf(f, "\n}");
	fclose(f_decla);
	fclose(f_link);
	fclose(f);
	return 0;
}
