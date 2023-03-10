/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:22:56 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/13 13:06:55 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	go_until_spasce(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

char	*join_dolar_str(char *str, char *world, int x, int z)
{
	int		len_s;
	char	*new_str;
	char	*rtv;
	char	*tmp;

	len_s = ft_strlen(str);
	new_str = ft_substr(str, 0, x - 1);
	rtv = new_str;
	if (world)
	{
		new_str = ft_strjoin(new_str, world);
		free(rtv);
		rtv = new_str;
	}
	tmp = ft_substr(str, x + z - 1, len_s);
	rtv = new_str;
	new_str = ft_strjoin(new_str, tmp);
	free(tmp);
	free(rtv);
	free(str);
	return (new_str);
}

int	find_end_of_single_quote(char *str, int i)
{
	i++;
	while (str[i] && str[i] != '\'' )
		i++;
	return (i);
}

int	find_end_of_double_quote(char *str, int i)
{	
	i++;
	while (str[i] && str[i] != '\"')
		i++;
	return (i);
}

void	dolar_pars(char **str, t_env **env)
{
	int		i;
	int		x;
	char	*world;
	char	*back;
	int		len;

	(void)env;
	i = 0;
	x = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'')
			i = find_end_of_single_quote(*str, i);
		if ((*str)[i] == '<' && (*str)[i + 1] && (*str)[i + 1] == '<' )
			i = go_until_spasce(*str, i + 2);
		if ((*str)[i] == '$' && (*str)[i + 1] == '?')
			i = i + 2;
		if ((*str)[i] == '$' && (*str)[i + 1] != ' '
			&& (*str)[i + 1] && (*str)[i + 1] != '\"')
		{
			x = ++i;
			while ((*str)[i] != ' ' && (*str)[i] && (*str)[i] != '$'
			&& (*str)[i] != '"' && (*str)[i] != '/'
			&& (*str)[i] != '\'' && (*str)[i] != '=')
				i++;
			world = ft_substr(*str, x, i - x);
			back = getenv(world);
			*str = join_dolar_str(*str, back, x, i - x + 1);
			len = ft_strlen(str[0]);
			free(world);
		}
		i++;
	}
}