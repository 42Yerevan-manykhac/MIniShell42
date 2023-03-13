/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:05:30 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/13 23:13:30 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_call(int (*fd)[2],int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		pipe(fd[i]);
		i++;
	}
}

void	child_error(int i, pid_t *child )
{
	while (i >= 0)
	{
		kill(child[i], SIGKILL);
		waitpid(child[i], NULL, WUNTRACED);
		i--;
	}
	ft_putstr_fd("fork error\n", 2);
}

void	fd_close(int (*fd)[2], int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

void	child_pr(int (*fd)[2], int i, int count)
{
	if (i == 0)
	{
		dup2(fd[0][1], 1);
	}
	else if (i == count - 1)
	{
		dup2(fd[i - 1][0], 0);
	}
	else
	{
		dup2(fd[i - 1][0], 0);
		dup2(fd[i][1], 1);
	}
	fd_close(fd, count);
}

void	func_red(t_tokens **token)
{
	t_count		*all_count;

	all_count = NULL;
	all_count = count_all((token));
	call_heredoc((token), all_count->count_herdoc);
	free(all_count);
}

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
	int			i;
	pid_t		*child;
	t_tokens	*tk;

	tk = *token;
	i = 0;
	fd = ft_calloc(sizeof(int *), (*token)->token_count - 1);
	child = malloc(sizeof(int) * (*token)->token_count);
	ft_pipe_call(fd, (*token)->token_count);
	func_red(token);
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
			exit(1);//exit anel statusov voch te 1-ov
		}
		i++;
		(*token) = (*token)->next;
	}
	(*token) = tk;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	processing_status_pipe(child, (*token)->token_count);
	fd_close(fd, (*token)->token_count);
	i = 0;
	while (i < (*token)->token_count)
	{
		waitpid(child[i], NULL, 0);
		i++;
	}
	free(child);
	free(fd);
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
				else if (exit_code== 131)
					ft_putstr_fd1("Quit 3", 1, 1);
			}
		}
	}
}