/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:30:37 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/13 19:51:55 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirection_output(char *file, int i)
{
	int	len;
	int	fd;

	len = ft_strlen(file);
	if (len == 0)
	{
		printf("minishell: : No such file or directory\n");
	}
	else
	{
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (i)
		{
			dup2(fd, 1);
		}
		close(fd);
	}
}

void	redirection_output_append(char *file, int i)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (i)
	{
		dup2(fd, 1); 
	}
	close(fd);
}

void	redirection_input(char *file, int i)
{
	int	fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd < 0)
	{
		printf("error\n");
		close(fd);
		return ;
	}
	if (i)
		dup2(fd, 0); 
	close(fd);
}

int	status_check(char *file, char *s)
{
	if (exit_code == -14)
	{
		exit_code = 1;
		free(file);
		free(s);
		return (1);
	}
	return (0);
}

void	heredoc(char *key, int i)
{
	char	*file;
	char	*hrd;
	int		fd;

	file = ft_strjoin(".hrd", key);
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		sig_control(2);
		hrd = readline("heredoc> ");
		if (!hrd)
			break ;
		if (status_check(file, hrd))
			return ;
		if (ft_strcmp1(key, hrd) == 0)
		{
			free(hrd);
			break ;
		}
		write(fd, hrd, ft_strlen(hrd));
		write(fd, "\n", 1);
		free(hrd);
	}
	if (i)
	{
		close(fd);
		fd = open(file, O_RDONLY);
		dup2(fd, 0);
		close(fd);
	}
	unlink(file);
	free(file);
}
