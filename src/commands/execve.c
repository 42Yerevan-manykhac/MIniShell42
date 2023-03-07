/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:06:58 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/07 12:39:03 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_the_paths(char **splited_path, char *new_str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (splited_path[i])
	{
		tmp = splited_path[i];
		splited_path[i] = ft_strjoin(tmp, new_str);
		free(tmp);
		tmp = NULL;
		i++;
	}
}

void	else_wait(void)
{
	int	num;

	wait(&num);
	if (WIFEXITED(num))
		exit_code = WEXITSTATUS(num);
}

char	*cheack_access(char **path, char **str, char **mx_env)
{
	int	i;

	(void)mx_env;
	i = 0;
	while (path[i])
	{
		if (access(path[i], F_OK) == 0)
		{
			return (path[i]);
		}
		i++;
	}
	return (str[0]);
}

void	ft_execv(char *new_str, char **mx_env, char **str)
{
	int	i;

	(void)new_str;
	i = 0;
	if (str[0][0] == '/' || str[0][0] == '.')
		i = execve(str[0], str, mx_env);
	else
		i = execve(new_str, str, mx_env);
	if (i == -1)
	{
		print_error(str[0], "command not found", 127);
		exit(127);
	}
}


char	**t_env_to_matrix(t_env **env)
{
	t_env	*l_env;
	char	*tmp;
	char	**new_env;
	int		i;

	i = 0;
	l_env = *env;
	new_env = malloc(sizeof(char *) * (env_len(env) + 1));
	while (l_env && l_env->key && l_env->value)
	{
		tmp = ft_strjoin(l_env->key, "=");
		new_env[i] = ft_strjoin(tmp, l_env->value);
		l_env = l_env->next;
		i++;
		free(tmp);
	}
	new_env[i] = 0;
	return (new_env);
}
