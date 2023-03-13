/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:20:24 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/14 02:24:00 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_tokens	*new_t_tokens(char *rdl, char **cmd,
	int *hrd_count, int count_token)
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