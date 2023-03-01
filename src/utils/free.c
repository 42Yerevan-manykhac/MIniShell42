
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
(void)hrd_next;
	i = 0;


	while ((*token))
	{
		i = 0;
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
//if(hrd_next==NULL)
//printf("------flag====\n");

				if ((*token)->head_redct->del)
					free((*token)->head_redct->del);
			

				
				free((*token)->head_redct);
				(*token)->head_redct = hrd_next;
			}

		//	(*token)->head_redct = NULL;
		}
		next = (*token)->next;
	free((*token)->cmd);

		free(*token);
		(*token) =next;
	}
	//	free(*token);
	token = NULL;
}