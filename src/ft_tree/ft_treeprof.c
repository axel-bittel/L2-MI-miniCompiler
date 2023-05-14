#include "ft_tree.h"

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_treeprof(t_tree *t)
{
	if (!t)
		return (0);
	return (max(ft_treeprof(t->f_a), ft_treeprof(t->f_b)) + 1);
}
