
#include "minishell.h"

void	matrix_free(char **env_split)
{
	int	j;

	j = 0;
	while (env_split[j])
	{
		free(env_split[j]);
		j++;
	}
	free(env_split);
}

void one_node_free(t_env **rtv)
{
	free((*rtv)->value);
	free((*rtv)->key);
	free((*rtv));
}

void free_t_list(t_tokens **token)
{
	int	i;

	i = 0;
	//free((*token)->hrd_count);
	while ((*token))
	{
		if ((*token)->rdl)
			free((*token)->rdl);
		while ((*token)->cmd[i])
		{
			free((*token)->cmd[i]);
			i++;
		}
		free((*token)->cmd);
		free(token);
		i = 0;
	}

}