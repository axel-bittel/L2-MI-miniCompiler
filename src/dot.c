#include "compiler.h"

void    extend_string(char **string1, char *string2)
{
    char *tmp;

    tmp = *string1;
    *string1 = malloc(strlen(*string1) + strlen(string2) + 1);
    strcpy(*string1, tmp);
    strcat(*string1, string2);
    free(tmp);
}

int decl_dot(t_tree *tree, int nb)
{
	int type;
    char    new_line;

    if (!tree || !tree->content)
        return (nb);

    type = ((t_node*)tree->content)->type;
    switch (type)
	{
        case IF_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"IF\" shape=diamond];\n",nb);
            fflush(fileResult_decla);
            break;

        case RETURN_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"RETURN\" shape=trapezium color=blue];\n",nb);
            fflush(fileResult_decla);
            break;

        case CALL_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"%s\" shape=septagon];\n",nb,((t_declaration*)((t_node*)tree->content)->datas)->name);
            fflush(fileResult_decla);
            break;

        case ADD_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"+\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case MINUS_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"-\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case MULT_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"*\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case DIV_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"/\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case ASSIGN_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\":=\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case RSHIFT_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\">>\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case LSHIFT_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"<<\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case BAND_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"&\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case BOR_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"|\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case NOT_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"!\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case BOOL_EQ_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"==\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case BOOL_L_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"<\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case BOOL_G_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\">\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case BOOL_LE_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"<=\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case BOOL_GE_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\">=\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case BOOL_AND_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"&&\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case BOOL_OR_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"||\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case BOOL_NEQ_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"!=\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case FUNCTION_NODE:
            fprintf(fileResult_decla, "\tnode_%d [label=\"%s, %d\" shape=invtrapezium color=blue];\n",nb, ((t_declaration*)((t_node*)tree->content)->datas)->name, ((t_declaration*)((t_node*)tree->content)->datas)->type);
            fflush(fileResult_decla);
			break;

        case WHILE_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"WHILE\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        case FOR_NODE:
            fprintf(fileResult_decla,"\tnode_%d [label=\"FOR\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

		case CONST_NODE:
			fprintf(fileResult_decla,"\tnode_%d [shape=ellipse label=\"%d\"];\n",nb, *(int*)((t_node*)tree->content)->datas);
            fflush(fileResult_decla);
			break;

        case VAR_NODE:
            fprintf(fileResult_decla,"\tnode_%d [shape=ellipse label=\"%s\"];\n",nb,((t_declaration*)((t_node*)tree->content)->datas)->name);
            fflush(fileResult_decla);
			break;

        case BLOCK_NODE:
			fprintf(fileResult_decla,"\tnode_%d [label=\"BLOC\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
			break;

        case BREAK_NODE:
			fprintf(fileResult_decla,"\tnode_%d [label=\"BREAK\" shape=box];\n",nb);
            fflush(fileResult_decla);
            break;

        case SWITCH_NODE:
			fprintf(fileResult_decla,"\tnode_%d [label=\"SWITCH\" shape=ellipse];\n",nb);
            fflush(fileResult_decla);
            break;

        default:
            return (0);
            break;
	}
    fflush(fileResult_decla);
    nbNode++;
    return (nb);
}


int link_dot(int node_1, int node_2)
{
    if (node_1 == 0 || node_2 == 0
        || node_1 == node_2)
        return (0);
	fprintf(fileResult_link,"\tnode_%d ->  node_%d;\n", node_1, node_2);
    fflush(fileResult_link);
	return(0);
}