/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:05:30 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/14 01:49:57 by lter-zak         ###   ########.fr       */
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
