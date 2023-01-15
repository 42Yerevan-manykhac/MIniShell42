#include "minishell.h"

t_env	*ft_lstlast(t_env *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
		//if (!lst->key)
			return (lst);
		//lst = lst->next;
	//}
		printf("smt\n");
	return (lst);
}

// while (lst -> next)
// 		lst = lst->next;
// 	return (lst);
// }

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*node;

	node = *lst;
	if (!node)
	{
		*lst = new;
		return ;
	}
	//printf("1 == %s\n", new->key);
	//printf("1 == %s\n", new->value);
	node = ft_lstlast(*lst);
	node->next = new;
}