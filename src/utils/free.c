
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
	int	i;
	t_tokens *tk;
	t_redirects *hrd;
(void) hrd;
	i = 0;
	tk = *token;
	if ((*token)->hrd_count)
		free((*token)->hrd_count);
	while ((*token))
	{
		if (tk->rdl)
		{
			free(tk->rdl);
			//tk->rdl = NULL;
		}
		if ((*token)->cmd && (*token)->cmd[i])
		{
			while ((*token)->cmd[i])
			{
				free((*token)->cmd[i]);
				i++;
			}
			//(*token)->cmd = NULL;
		}
	if ((*token)->head_redct)
	{
		while ((*token)->head_redct)
		{
			if ((*token)->head_redct->del)
				free((*token)->head_redct->del);
			if ((*token)->head_redct->pathname)
				free((*token)->head_redct->pathname);
			hrd = (*token)->head_redct->next;
			free((*token)->head_redct);
			//free((*token)->head_redct);
		}
	}
		// i = 0;
		free((*token)->cmd);
		(*token) = (*token)->next;
	}
	//free(token);
}