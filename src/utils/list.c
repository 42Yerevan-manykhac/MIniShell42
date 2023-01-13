#include "minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_list	*node;

	node = *lst;
	if (!node)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(node)->next = new;
}