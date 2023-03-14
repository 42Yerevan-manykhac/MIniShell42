/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:49:22 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/14 12:57:01 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	processing_status(int size)
{
	pid_t	pid;
	int		i;
	int		status;

	i = -1;
	status = 0;
	while (++i < size)
	{
	pid = waitpid(-1, &status, 0);
		if (!WTERMSIG(status))
			exit_code = WEXITSTATUS(status);
		else
		{
		exit_code = WTERMSIG(status) + 128;
			if (exit_code == 130)
				write(1, "\n", 1);
			else if (exit_code == 131)
				ft_putstr_fd1("Quit 3", 1, 1);
		}
	}
}

void	running_pipe(t_tokens **token, t_env **env)
{
	int			(*fd)[2];
	pid_t		*child;
	t_tokens	*tk;

	tk = *token;
	fd = ft_calloc(sizeof(int *), (*token)->token_count - 1);
	child = malloc(sizeof(int) * (*token)->token_count);
	ft_pipe_call(fd, (*token)->token_count);
	func_red(token);
	run_p(child, token, env, fd);
	(*token) = tk;
	fd_close(fd, (*token)->token_count);
	processing_status_pipe(child, (*token)->token_count);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	free(child);
	free(fd);
}

void	run_p(pid_t *child, t_tokens **token, t_env **env, int (*fd)[2])
{
	int			i;

	i = 0;
	while ((*token))
	{
		child[i] = fork();
		if (child[i] == -1)
		{
			child_error(i, child);
			break ;
		}
		else if (child[i] == 0)
		{
			sig_control(0);
			running_p((token), env, fd, i);
			exit(1);
		}
		i++;
		(*token) = (*token)->next;
	}
}

void	processing_status_pipe(pid_t *a, int size)
{
	pid_t	pid;
	int		i;
	int		status;

	i = -1;
	status = 0;
	while (++i < size)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == a[size - 1])
		{
			if (!WTERMSIG(status))
				exit_code = WEXITSTATUS(status);
			else
			{
				exit_code = WTERMSIG(status) + 128;
				if (exit_code == 130)
					write(1, "\n", 1);
				else if (exit_code == 131)
					ft_putstr_fd1("Quit 3", 1, 1);
			}
		}
	}
}
