/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:12:26 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/07 13:12:29 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcrcmp(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strrchr(char *str, int c)
{
	int				k;
	unsigned char	*s;

	s = (unsigned char *)str;
	k = ft_strlen(str);
	if (c == '\0')
		return ((char *)(s + k));
	while (--k >= 0)
	{
		if (s[k] == (unsigned char)c)
			return ((char *)(s + k));
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	iff;
	size_t	len;
	char	*trm;

	iff = 0;
	while (s1[iff] && ft_strchr(set, s1[iff]))
		++iff;
	len = ft_strlen(s1);
	while (len && ft_strrchr(set, s1[len]))
		--len;
	trm = ft_substr(s1, iff, len - iff + 1);
	return (trm);
}

int	ft_int_strchr(char *str, char c)
{
	unsigned int	i;
	unsigned char	*s;
	int				len;

	s = (unsigned char *) str;
	len = ft_strlen(str);
	i = 0;
	if (c == 0)
		return (len);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (0);
}
