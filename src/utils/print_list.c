#include "minishell.h"


static void print_list_added(t_env **node)
{
	t_env	*curr;

	curr = (*node);
	while (curr)
	{
		printf("declare -x %s", curr->key);
		if (curr->value)
			printf("=\"%s\"\n", curr->value);
		else
			printf("\n");
		curr = curr->next;
	}
}

void	sortlist(t_env **env) // export_no_args()
{
	t_env	*current = *env;
	t_env	*index = NULL;  
	char	*temp;

	if (env == NULL)
		return ;
	while (current != NULL)
	{
		index = current->next;
		while (index != NULL)
		{
			if (ft_strcmp(current->key, index->key) > 0)
			{
				temp = current->key;
				current->key = index->key;
				index->key = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
	print_list_added(env);
}