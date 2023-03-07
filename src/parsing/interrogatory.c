/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interrogatory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:18:08 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/07 13:20:40 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	interrogatory(char **str)
{
	int		i;
	char	*num;

	i = 0;

	num = ft_itoa(exit_code);
	while ((*str)[i] && (*str)[i + 1])
	{
		if ((*str)[i] == '$' && (*str)[i + 1] == '?')
		{
			*str = join_dolar_str(*str, num, i + 1, 2);
			i++;
		}
		else
			i++;
	}
	free (num);
}