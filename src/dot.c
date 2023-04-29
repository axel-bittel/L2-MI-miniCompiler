#include "compiler.h"

int decl_dot(t_tree *tree, FILE *f, int nb)
{
	int type = ((t_node*)tree->content)->type;
    nb += 1;
    switch (type)
	{
        case IF_NODE:
            fprintf(f,"node_%d [shape=diamond label=\"IF\"];\n",nb);
            return(nb);

        case RETURN_NODE:
            printf(f,"\tnode_%d [label=\"RETURN\" shape=trapezium color=blue];\n",nb);
            return(nb);

        case CALL_NODE:
            fprintf(f,"\tnode_%d [label=\"%s\" shape=septagon];\n",nb,((t_declaration*)((t_node*)tree->content)->datas)->name);
            return(nb);

        case ADD_NODE:
            fprintf(f,"\tnode_%d [label=\"+\" shape=ellipse];\n",nb);
            return(nb);

        case MINUS_NODE:
            fprintf(f,"\tnode_%d [label=\"-\" shape=ellipse];\n",nb);
            return(nb);

        case MULT_NODE:
            fprintf(f,"\tnode_%d [label=\"*\" shape=ellipse];\n",nb);
            return(nb);

        case DIV_NODE:
            fprintf(f,"\tnode_%d [label=\"/\" shape=ellipse];\n",nb);
            return(nb);

        case ASSIGN_NODE:
            fprintf(f,"\tnode_%d [label=\":=\" shape=ellipse];\n",nb);
            return(nb);

        case RSHIFT_NODE:
            fprintf(f,"\tnode_%d [label=\">>\" shape=ellipse];\n",nb);
            return(nb);

        case LSHIFT_NODE:
            fprintf(f,"\tnode_%d [label=\"<<\" shape=ellipse];\n",nb);
            return(nb);

        case BAND_NODE:
            fprintf(f,"\tnode_%d [label=\"&\" shape=ellipse];\n",nb);
            return(nb);

        case BOR_NODE:
            fprintf(f,"\tnode_%d [label=\"|\" shape=ellipse];\n",nb);
            return(nb);

        case NOT_NODE:
            fprintf(f,"\tnode_%d [label=\"!\" shape=ellipse];\n",nb);
            return(nb);

        case BOOL_EQ_NODE:
            fprintf(f,"\tnode_%d [label=\"==\" shape=ellipse];\n",nb);
            return(nb);

        case BOOL_L_NODE:
            fprintf(f,"\tnode_%d [label=\"<\" shape=ellipse];\n",nb);
            return(nb);

        case BOOL_G_NODE:
            fprintf(f,"\tnode_%d [label=\">\" shape=ellipse];\n",nb);
            return(nb);

        case BOOL_LE_NODE:
            fprintf(f,"\tnode_%d [label=\"<=\" shape=ellipse];\n",nb);
            return(nb);

        case BOOL_GE_NODE:
            fprintf(f,"\tnode_%d [label=\">=\" shape=ellipse];\n",nb);
            return(nb);

        case BOOL_AND_NODE:
            fprintf(f,"\tnode_%d [label=\"&&\" shape=ellipse];\n",nb);
            return(nb);

        case BOOL_OR_NODE:
            fprintf(f,"\tnode_%d [label=\"||\" shape=ellipse];\n",nb);
            return(nb);

        case BOOL_NEQ_NODE:
            fprintf(f,"\tnode_%d [label=\"!=\" shape=ellipse];\n",nb);
            return(nb);

        case FUNCTION_NODE:
            fprintf(f, "\tnode_%d [label=\"%s, %s\" shape=invtrapezium color=blue];\n",nb, ((t_declaration*)((t_node*)tree->content)->datas)->name, ((t_declaration*)((t_node*)tree->content)->datas)->type);
			return(nb);

        case WHILE_NODE:
            fprintf(f,"\tnode_%d [label=\"WHILE\" shape=ellipse];\n",nb);
            return(nb);

        case FOR_NODE:
            fprintf(f,"\tnode_%d [label=\"FOR\" shape=ellipse];\n",nb);
            return(nb);

		case CONST_NODE:
			fprintf(f,"\tnode_%d [shape=ellipse label=\"%s\";]\n",nb,((t_node*)tree->content)->datas);
			return(nb);

        case VAR_NODE:
            fprintf(f,"\tnode_%d [shape=ellipse label=\"%s\"];\n",nb,((t_node*)tree->content)->datas);
			return(nb);

        case BLOCK_NODE:
			fprintf(f,"\tnode_%d [label=\"BLOC\" shape=ellipse];\n",nb);
			return(nb);

        case BLOCK_FUN_NODE:


        case BREAK_NODE:
			fprintf(f,"\tnode_%d [label=\"BREAK\" shape=box];\n",nb);
			return(nb);

        case SWITCH_NODE:
			fprintf(f,"\tnode_%d [label=\"SWITCH\" shape=ellipse];\n",nb);
			return(nb);

        default:
            printf("%d", type);
            break;
	}
	
}


int link_dot(int node_1, int node_2, FILE *f)
{
	fprintf(f,"\tnode_%d ->  node_%d\n", node_1, node_2);
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
