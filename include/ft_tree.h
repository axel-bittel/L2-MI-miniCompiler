#ifndef FT_TREE_H
# define FT_TREE_H
# include <stdlib.h>
typedef struct s_tree
{
	void			*content;
	struct s_tree	*f_a;
	struct s_tree	*f_b;
}				t_tree;
t_tree	*ft_treenew(void *content);
void	ft_treeadd_f(t_tree *t, t_tree *f, int is_a);
int		ft_treeprof(t_tree *t);
#endif
