/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:16:04 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/14 02:18:51 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ftft(t_tokens **token)
{
	int			i;
	t_tokens	*tk;

	i = 0;
	tk = *token;
	while (tk)
	{
		i = 0;
		while (tk && tk->cmd && tk->cmd[i])
		{
			tk->cmd[i] = ignore_quote(tk->cmd[i]);
			i++;
		}
		tk = tk->next;
	}
}

int	ft_count_pipe(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i = find_end_of_single_quote(str, i);
		else if (str[i] == '\"')
			i = find_end_of_double_quote(str, i);
		if (str[i] == '|')
			count++;
		i++;
	}
	return (count);
}

int	ft_count_tokens(char **token)
{
	int	i;

	i = 0;
	while (token[i])
		i++;
	return (i);
}

int	check_error(char **tokenized, char *str)
{
	int	count_pipe;
	int	count_tokens;

	count_pipe = ft_count_pipe(str);
	count_tokens = ft_count_tokens(tokenized);
	if (count_pipe && count_tokens - 1 != count_pipe)
	{
		exit_code = 258;
		write(2, "Minishell: syntax error near unexpected token `|'\n", 50);
		return (1);
	}
	return (0);
}