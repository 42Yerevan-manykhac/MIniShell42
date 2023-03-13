/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:28:25 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/13 23:02:09 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execve_cmd2(t_env **env, char **str)
{
	t_env	*path;
	char	**splited_path;
	char	*new_str;
	char	**mx_env;
	int		i;

	i = 0;
	path = get_env(env, "PATH");
	if (path)
	{
		splited_path = ft_split(path->value, ':');
		new_str = ft_strjoin("/", str[0]);
		create_the_paths(splited_path, new_str);
		free(new_str);
		new_str = 0;
		mx_env = t_env_to_matrix(env);
		new_str = cheack_access(splited_path, str, mx_env);
		ft_execv(new_str, mx_env, str);
		matrix_free(mx_env);
		matrix_free(splited_path);
	}
	return ;
}


void	execve_cmd(t_env **env, char **str)
{
	t_env	*path;
	char	**splited_path;
	char	*new_str;
	char	**mx_env;
	int		pid;

	pid = 0;
	path = get_env(env, "PATH");
	if (path)
	{
		splited_path = ft_split(path->value, ':');
		new_str = ft_strjoin("/", str[0]);
		create_the_paths(splited_path, new_str);
		free(new_str);
		mx_env = t_env_to_matrix(env);
		pid = fork();
	
		if (pid == 0)
		{
			
			sig_control(0);
			new_str = cheack_access(splited_path, str, mx_env);
			ft_execv(new_str, mx_env, str);
		}
		else
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
			processing_status( 1);
			//else_wait();
		}
		matrix_free(mx_env);
		matrix_free(splited_path);
	}
	else
		print_error(str[0], "No such file or directory", 127);
	return ;
}
