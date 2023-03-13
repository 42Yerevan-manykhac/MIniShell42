/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_smart_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:16:13 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/13 14:07:58 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	any_quote(char *str, int i)
{
	if (str[i] == '\'')
	i = find_end_of_single_quote(str, i);
	else if (str[i] == '\"')
		i = find_end_of_double_quote(str, i);
	return (i);
}

char	*ignore_quote(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = NULL;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			j++;
		i++;
	}
	tmp = malloc(sizeof(char *) * (i - j + 1));
	tmp[i - j] = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	free (str);
	return (tmp);
}

void	ft_smart_sub(t_tokens **tk, char *rdl, t_tokens **hert) 
{
	char	*tmp;
	char	*ptr;
	int		i;
	int		j;
	char *result;
	(void)*tk;
	
	j = 0;
	i = 0;
	tmp = NULL;
	result = NULL;
	while (rdl[i])
	{
		while (rdl[i] && rdl[i] == ' ')
		i++;
		if (rdl[i] && rdl[i + 1] && rdl[i] == '<' && rdl[i + 1] == '<')
		{
			i += 2;
			while (rdl[i] && rdl[i] == ' ')
			i++;
			j = i;
			if (rdl[i] == '\'')
			i = find_end_of_single_quote(rdl, i);
			else if (rdl[i] == '\"')
			i = find_end_of_double_quote(rdl, i);
			while (rdl[i] && rdl[i] != ' ')
			i++;
			ft_fill_red(hert, 2, ignore_quote(ft_substr(rdl, j, i - j)));
		}
		else if (rdl[i] && rdl[i + 1] && rdl[i] == '>' && rdl[i + 1] == '>')
		{
			i += 2;
			while (rdl[i] && rdl[i] == ' ')
			i++;
			if (rdl[i] == '\'')
			i = find_end_of_single_quote(rdl, i);
			else if (rdl[i] == '\"')
			i = find_end_of_double_quote(rdl, i);
			j = i;
			while (rdl[i] && rdl[i] != ' ')
			i++;
			ft_fill_red(hert, 4, ignore_quote(ft_substr(rdl, j, i - j)));
		}
		else if (rdl[i] && rdl[i] == '>')
		{
			i += 1;
			while (rdl[i] && rdl[i] == ' ')
			i++;
			j = i;
			if (rdl[i] == '\'')
			i = find_end_of_single_quote(rdl, i);
			else if (rdl[i] == '\"')
			i = find_end_of_double_quote(rdl, i);
			while (rdl[i] && !ft_strcrcmp(REDE, rdl[i]))
			i++;
			ft_fill_red(hert, 3, ignore_quote(ft_substr(rdl, j, i - j)));
		}
		else if (rdl[i] && rdl[i] == '<')
		{
			i += 1;
			while (rdl[i] && rdl[i] == ' ')
			i++;
			j = i;
			while (rdl[i] && rdl[i] != ' ')
			i++;
			ft_fill_red(hert, 1, ignore_quote(ft_substr(rdl, j, i - j)));
		}
		else
		{
			j = i;
			while (rdl[i] != '<' && rdl[i] != '>' && rdl[i] != '\0')
			{
				if (rdl[i] == '\'')
					i = find_end_of_single_quote(rdl, i);
				else if (rdl[i] == '\"')
                    i = find_end_of_double_quote(rdl, i);
				i++;
			}		
		char *esim;
		ptr = ft_substr(rdl, j, i - j);

		esim = tmp;
		tmp = ft_strjoin1(tmp, ptr);
			free(esim);
			if (ptr)
				free(ptr);
		}
	}
	if (tmp)
	{
		(*hert)->cmd = smart_split(tmp, ' ');
		free(tmp);
	}
}

void	smart_smart_split(t_tokens **token)
{
	t_tokens	*tk;

	tk = *token;
	while (tk)
	{
		ft_smart_sub(token, tk->rdl, &tk);
		tk = tk->next;
	}
}