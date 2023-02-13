
#include "minishell.h"

void	matrix_free(char **env_split)
{
	int	j;

	j = 0;
	while ( env_split && env_split[j])
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
	(void) *token;
 	int	i;
	t_tokens *next;
	t_redirects *hrd_next;

	i = 0;
	if ((*token)->hrd_count)
		free((*token)->hrd_count);
	while ((*token))
	{
		next = (*token)->next;
		if ((*token)->rdl)
			free((*token)->rdl);
		if ((*token)->cmd)
		{
			while ((*token)->cmd[i])
			{
				free((*token)->cmd[i]);
					i++;
			}
		}
		if ((*token)->head_redct)
		{
			while ((*token)->head_redct)
			{
				hrd_next = (*token)->head_redct->next;
				if ((*token)->head_redct->del)
					free((*token)->head_redct->del);
				free((*token)->head_redct);
				(*token)->head_redct = hrd_next;
			}
			free((*token)->head_redct);
			(*token)->head_redct = NULL;
		}
		free(*token);
		(*token) = next;
	}
	token = NULL;
}