/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:06:04 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/14 01:17:15 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_env(t_env **l_env, char *new_key)
{
	t_env	*env;

	env = *l_env;
	while (env)
	{
		if (ft_strcmp1(new_key, env->key))
			env = env->next;
		else
			return (env);
	}
	return (0);
}


int	find_key(t_env **l_env, char *new_key)
{
	t_env	*env;

	env = *l_env;
	while (env)
	{
		if (ft_strcmp1(new_key, env->key) != 0 && env)
			env = env->next;
		else
			return (1);
	}
	return (0);
}

void	already_exist(char **splited, t_env *rtv)
{
	if (splited[1])
	{
		rtv->value = splited[1];
		rtv->flag = 1;
		free(splited[0]);
	}
	else
	{
		free(splited[0]);
		rtv->flag = 1;
	}
}

void	key_not_exist(char **splited, t_env *env, int i, int len)
{
	if (splited[1])
	{
		env->flag = 1;
		env->value = splited[1];
	}
	else if (i && i == len - 1)
	{	
			env->flag = 1;
			env->value = 0;
	}
	else
	{
		env->flag = 0;
		env->value = 0;
	}
	env->next = NULL;
}

void	export_cmd(t_env **l_env, char *str)
{
	int		i;
	t_env	*env;
	int		len;
	char	**splited;

	len = ft_strlen(str);
	i = ft_int_strchr(str, '=');
	splited = split_export(str);
	if (export_pars(splited[0]))
	{
		matrix_free(splited);
		return ;
	}
	if (!if_key_already_exist(l_env, splited))
	{
		env = malloc(sizeof(t_env));
		env->key = splited[0];
		key_not_exist(splited, env, i, len);
		ft_lstadd_back(l_env, env);
	}
	free(splited);
}

