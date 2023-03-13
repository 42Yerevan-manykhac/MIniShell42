/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:15:12 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/14 02:24:19 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fill_red(t_tokens **token, int flag, char *str)
{
	t_tokens	*tk;
	t_redirects	*red;

	red = NULL;
	tk = *token;
	if ((*token)->head_redct->flag == 0)
	{
		(*token)->head_redct->del = str;
		(*token)->head_redct->flag = flag;
		(*token)->head_redct->pathname = NULL;
		(*token)->head_redct->next = NULL;
	}
	else
	{
		red = new_t_redirects(flag, str, NULL);
		t_redirects_add_back(&(tk)->head_redct, red);
	}
}

void	t_redirects_add_back(t_redirects **head, t_redirects *new_node)
{
	t_redirects	*tmp;

	tmp = *head;
	if ((*head)->flag == 0)
	{
		*head = new_node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	t_tokens_add_back(t_tokens **head, t_tokens *new)
{
	t_tokens	*node;

	node = *head;
	if (!node)
	{
		*head = new;
		return ;
	}
	ft_lstlast1(node)->next = new;
}

void	fill_t_token(t_tokens **token, char **tokenized,
	int *hrd_c, int count_token)
{
	int	i;

	i = 0;
	while (tokenized && tokenized[i])
	{
		t_tokens_add_back(token, new_t_tokens(tokenized[i],
				NULL, hrd_c, count_token));
		i++;
	}
}

void	tokenization(t_tokens **token, char **str)
{
	char	**tokenized;
	int		*hrd_c;
	int		count_token;

	hrd_c = 0;
	tokenized = smart_split(*str, '|');
	count_token = matrix_len(tokenized);
	check_error(tokenized, str[0]);
	fill_t_token(token, tokenized, hrd_c, count_token);
	free(tokenized);
	smart_smart_split(token);
	ftft(token);
}
