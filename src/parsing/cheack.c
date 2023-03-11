/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:24:39 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/11 17:24:44 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cheack_front(char *str, int *x)
{
	int	i;

	while (str[*x] && str[*x] == ' ')
			(*x)++;
	i = *x;
	while (str[*x] && !ft_strchr(METACHARS, str[*x]))
		(*x)++;
	if (*x - i <= 0)
		return (1);
	return (0);
}

int	cheack_back(char *str, int x)
{
	int	i;

	if (x == 0)
		return (1);
	while (str[x] && str[x] == ' ')
			x--;
	i = x;
	while (!ft_strchr(METACHARS, str[x]) && str[i])
		x--;
	if (i - x <= 0)
		return (1);
	return (0);
}
