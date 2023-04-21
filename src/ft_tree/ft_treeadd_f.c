#include "ft_tree.h"

void	ft_treeadd_f(t_tree *t, t_tree *f, int is_a)
{
	if (!t)
		return ;
	if (is_a)
		t->f_a = (struct s_tree *)f;
	else
		t->f_b = f;
}
