#include "ft_tree.h"
#include <stdlib.h>
#include <stddef.h>

t_tree	*ft_treenew(void *content)
{
	t_tree	*res;

	res = (t_tree *)malloc(sizeof(t_tree));
	if (!res)
		return (NULL);
	res->f_a = NULL;
	res->f_b = NULL;
	res->content = content;
	return (res);
}
