/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:13:31 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/07 13:13:34 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	itoa_dig(long n)
{
	char	k;

	k = 0;
	k = (n % 10) + '0';
	return (k);
}

static int	itoa_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		++len;
		n = n * (-1);
	}
	while (n != 0)
	{
		n = n / 10;
		++len;
	}
	return (len);
}

static char	*is_zero(char *str)
{
	str[0] = '0';
	str[1] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	w;

	w = n;
	len = itoa_len(w);
	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * (2));
		return (is_zero(str));
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (w < 0)
	{
		str[0] = '-';
		w = w * -1;
	}
	while (w > 0)
	{
		str[--len] = itoa_dig(w);
		w = w / 10;
	}
	return (str);
}
