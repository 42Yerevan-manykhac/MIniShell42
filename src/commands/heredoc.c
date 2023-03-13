/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:13:27 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/14 02:14:01 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_part2(int i, int fd, char *file)
{
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
	heredoc_part2(i, fd, file);
}
