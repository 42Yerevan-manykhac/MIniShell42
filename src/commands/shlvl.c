/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:57:57 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/11 17:26:43 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_level(t_env **env)
{
	t_env	*rtv;
	int		tmp;

	rtv = get_env(env, "SHLVL");
	tmp = ft_atoi(rtv->value);
	free(rtv->value);
	rtv->value = ft_itoa(tmp + 1);
}