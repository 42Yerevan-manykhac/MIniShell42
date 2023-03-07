/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:01:02 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/07 13:01:18 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_longlongd3(char *str)
{
	int		i;
	char	*max1;

	i = 0;
	max1 = "9223372036854775807";
	while (i <= 18)
	{
		if (str[i] == max1[i] || str[i] < max1[i])
		{
			if (i == 18)
				return (1);
			i++;
		}
		else if (str[i] > max1[i])
			return (0);
	}
	return (0);
}

int	check_longlongd2(char *str)
{
	int		i;
	char	*max;

	i = 1;
	max = "+9223372036854775807";
	while (i <= 19)
	{
		if (str[i] == max[i] || str[i] < max[i])
		{
			if (i == 19)
				return (1);
				i++;
		}
		else if (str[i] > max[i])
			return (0);
	}
	return (0);
}

int	check_longlongd1(char *str)
{
	int		i;
	char	*min;

	min = "-9223372036854775808";
	i = 1;
	while (i <= 19)
	{
		if (str[i] == min[i] || str[i] < min[i])
		{
			if (i == 19)
				return (1);
				i++;
		}
		else if (str[i] > min[i])
			return (0);
	}
	return (0);
}

int	check_longlongd(char *str)
{
	if ((str[0] == '-' && ft_strlen(str) < 20)
		|| (str[0] == '+' && ft_strlen(str) < 20))
		return (1);
	if ((str[0] == '-' && ft_strlen(str) > 20)
		|| (str[0] == '+' && ft_strlen(str) > 20))
		return (0);
	if (str[0] != '-' && str[0] != '+' && ft_strlen(str) > 19)
		return (0);
	if (str[0] == '-' && ft_strlen(str) == 20)
		return (check_longlongd1(str));
	else if (str[0] == '+' && ft_strlen(str) == 20)
		return (check_longlongd2(str));
	else if (str[0] != '+' && str[0] != '-' && ft_strlen(str) == 19)
		return (check_longlongd3(str));
	return (1);
}
