#include "minishell.h"

void	export_no_args(t_env **env)
{
	t_env	*current;
	t_env	*index;
	char	*temp;

	current = *env;
	index = NULL;
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
	only_export(env);
}