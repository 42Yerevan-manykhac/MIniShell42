/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_harcakan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:05:57 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/11 11:29:54 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollar_harcakan(void)
{
	char	*tiv;

	tiv = ft_itoa(exit_code);
	exit_code = 127;
	write(1, tiv, ft_strlen(tiv));
	write(1, ":", 1);
	write(1, "command not found", 18);
}
