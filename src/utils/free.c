/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:14:16 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/07 13:14:51 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	matrix_free(char **env_split)
{
	int	j;

	j = 0;
	while (env_split && env_split[j])
	{
		free(env_split[j]);
		j++;
	}
	free(env_split);
}

void	one_node_free(t_env **rtv)
{
	free((*rtv)->value);
	free((*rtv)->key);
	free((*rtv));
}

void	free_t_list(t_tokens **token)
{

	
	int			i;
	t_tokens	*next;
	t_redirects	*hrd_next;
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
		while ((*token)->head_redct && (*token)->head_redct->flag)
			{
	
	
				hrd_next = (*token)->head_redct->next;
				if ((*token)->head_redct->del)
					free((*token)->head_redct->del);
					free((*token)->head_redct);
				(*token)->head_redct = hrd_next;
			}
		free((*token)->head_redct );
		next = (*token)->next;
		free((*token)->cmd);
		free(*token);
		(*token) = next;
	}

	token = NULL;
}
