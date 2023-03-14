/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:28:34 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/14 13:45:49 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;
	unsigned char	*s;
	int				len;

	s = (unsigned char *) str;
	len = ft_strlen(str);
	i = 0;
	if (c == 0)
		return ((char *)s + len);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

int	ft_strcmp_part2(char *str, char *cmd, int len)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	j = 0;
	while (cmd && str && cmd[j] && str[i])
	{
		while (str[i++] == cmd[j++])
		{
			if (j == len - 1)
				return (1);
		}
		if (j == 0)
				flag = 1;
			j = 0;
		if (flag)
		{
			i++;
			flag = 0;
		}
	}
	return (0);
}

int	ft_strcmp(char *str, char *cmd)
{
	int	len;
	int	result;

	len = ft_strlen(cmd);
	if (len != ft_strlen(str))
		return (0);
	result = ft_strcmp_part2(str, cmd, len);
	return (result);
}

int	ft_strcmp1(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
