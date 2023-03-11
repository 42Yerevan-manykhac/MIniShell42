/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:36:58 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/11 12:30:08 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_cmd(t_env **l_env)
{
	t_env	*tmp;

	tmp = get_env(l_env, "PWD");
	if (tmp == NULL)
		print_error("PWD", "No such file or directory", 127);
	else
		printf("%s\n", tmp->value);
}

void	env_cmd(t_env *env)
{
	while (env)
	{
		if (env && env->flag)
		{
			printf("%s", env->key);
			printf("=");
			if (env->value)
				printf("%s\n", env->value);
			else
				printf("\n");
		}
		env = env->next;
	}
}