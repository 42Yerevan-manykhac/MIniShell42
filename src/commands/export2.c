/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:48:06 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/14 01:17:01 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	if_key_already_exist(t_env **l_env, char **splited)
{
	t_env	*rtv;

	rtv = 0;
	if (if_need_to_add(l_env, splited))
		return (1);
	if (find_key(l_env, splited[0]))
	{
		rtv = get_env(l_env, splited[0]);
		if (rtv->value)
		{
			free(rtv->value);
			free(splited[0]);
			rtv->flag = 1;
			rtv->value = splited[1];
		}
		else
		{
			already_exist(splited, rtv);
		}
		return (1);
	}
	return (0);
}

void	only_export(t_env **node)
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

void	need_to_add(t_env **l_env, char **splited, t_env *rtv, char *tmp)
{
	if (!splited[1])
	{
		free(splited[0]);
		return ;
	}
	rtv = get_env(l_env, splited[0]);
	free(splited[0]);
	if (!rtv->value)
			rtv->value = splited[1];
	else
	{
		tmp = rtv->value;
		rtv->value = ft_strjoin(tmp, splited[1]);
		free(splited[1]);
		free(tmp);
	}
}

int	if_need_to_add(t_env **l_env, char **splited)
{
	int		len;
	t_env	*rtv;
	char	*tmp;

	rtv = 0;
	len = ft_strlen(splited[0]);
	if (splited[0][len - 1] == '+')
	{
		tmp = splited[0];
		splited[0] = ft_strtrim(splited[0], "+");
		free(tmp);
		if (find_key(l_env, splited[0]))
		{
			need_to_add(l_env, splited, rtv, tmp);
			return (1);
		}
	}
	return (0);
}