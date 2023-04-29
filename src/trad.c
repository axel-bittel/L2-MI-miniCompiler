#include "compiler.h"
/*
int create_dot(t_tree *tree)
{
    FILE *f;
    f = fopen("./test.txt", "w");
    fprintf(f, "digraph mon_programme {\n");
    int type = ((t_node*)tree->content)->type;
    switch (type)
    {
        case FUNCTION_NODE:
            fprintf(f, "\tnode_mafonction [label=\"%d, %d\" shape=invtrapezium color=blue];\n\tnode_reste [shape=triangle label=\"...\" style=dotted];\n\tnode_mafonction ->  node_reste\n\t", ((t_node*)tree->content)->datas, ((t_node*)tree->content)->type);
            break;
    }
}
*/