/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:05:38 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/10 21:58:16 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_oldpwd(t_env **l_env)
{
	t_env	*env;

	env = get_env(l_env, "OLDPWD");
	if (env)
	{
		env->flag = 1;
		free(env->value);
		env->value = ft_strdup(get_env(l_env, "PWD")->value);
	}
}

void	update_pwd(t_env **l_env)
{
	t_env	*env;
	char	*tmp;
	char	cwd[256];

	env = get_env(l_env, "PWD");
	tmp = env->value;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		env->value = ft_strdup(getcwd(cwd, sizeof(cwd)));
	free(tmp);
}

void	cd_cmd(t_env **l_env, char **str)
{
	update_oldpwd(l_env);
	if ((ft_strcmp("cd", str[0]) && !str[1]) || ft_strcmp("~", str[1]))
		chdir(get_env(l_env, "HOME")->value);
	else
	{
		if (chdir(str[1]) == -1)
			print_error(str[1], "No such file or directory", 1);
	}
	update_pwd(l_env);
}
