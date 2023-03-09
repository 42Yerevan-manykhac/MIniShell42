/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:15:12 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/07 13:31:01 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	count_hrd(char **str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str && str[0][i])
	{
		if (str[0][i] == '\'')
			i = find_end_of_single_quote(*str, i);
		else if (str[0][i] == '\"')
			i = find_end_of_double_quote(*str, i);
		if (str[0][i] == '<' && str[0][i + 1] && str[0][i + 1] == '<')
			count++;
		i++;
	}
	return (count);
}

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

t_redirects	*new_t_redirects(int flag, char *del, char *pathname)
{
	t_redirects	*new_red;

	new_red = malloc(sizeof(t_redirects));
	new_red->flag = flag;
	new_red->del = del;
	new_red->pathname = pathname;
	new_red->next = NULL;
	return (new_red);
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

t_tokens	*new_t_tokens(char *rdl, char **cmd, int *hrd_count, int count_token)
{
	t_tokens	*new_node;
	(void)cmd;
	(void)hrd_count;

	new_node = malloc(sizeof(t_tokens));
	new_node->rdl = rdl;
	new_node->cmd = NULL;
	new_node->head_redct = NULL;
	new_node->head_redct = malloc(sizeof(t_redirects));
	new_node->head_redct->flag = 0;
	new_node->head_redct->del = NULL;
	new_node->head_redct->pathname = NULL;
	new_node->head_redct->next = NULL;
	new_node->token_count = count_token;
	new_node->next = NULL;
	return (new_node);
}

t_tokens	*ft_lstlast1(t_tokens *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
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

void	fill_t_token(t_tokens **token, char **tokenized, int *hrd_c, int count_token)
{
	int	i;

	i = 0;

	while (tokenized && tokenized[i])
	{
		t_tokens_add_back(token, new_t_tokens(tokenized[i],
				NULL, hrd_c, count_token));
		i++;
	}

		// printf("------%s\n",() );
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

	
	free(tokenized); // tokenized[i]-ery dranq hteo darnum en tokeni rdlnery/ petq chi dranq maqrel
	 smart_smart_split(token);

	ftft(token);
	
}
