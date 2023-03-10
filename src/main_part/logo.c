/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:51:42 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/10 21:51:47 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_logo(void)
{
	printf("\033[0;34m");
	printf("\n\n              __          __          __                __ __      __    __  ______  \n");
	printf("             |  \\        |  \\        |  \\              |  \\  \\    |  \\  |  \\/      \\ \n");
	printf(" ______ ____  \\▓▓_______  \\▓▓ _______| ▓▓____   ______ | ▓▓ ▓▓    | ▓▓  | ▓▓  ▓▓▓▓▓▓\\\n");
	printf("|      \\    \\|  \\       \\|  \\/       \\ ▓▓    \\ /      \\| ▓▓ ▓▓    | ▓▓__| ▓▓\\▓▓__| ▓▓\n");
	printf("| ▓▓▓▓▓▓\\▓▓▓▓\\ ▓▓ ▓▓▓▓▓▓▓\\ ▓▓  ▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓\\  ▓▓▓▓▓▓\\ ▓▓ ▓▓    | ▓▓    ▓▓/      ▓▓\n");
	printf("| ▓▓ | ▓▓ | ▓▓ ▓▓ ▓▓  | ▓▓ ▓▓\\▓▓    \\| ▓▓  | ▓▓ ▓▓    ▓▓ ▓▓ ▓▓     \\▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓ \n");
	printf("| ▓▓ | ▓▓ | ▓▓ ▓▓ ▓▓  | ▓▓ ▓▓_\\▓▓▓▓▓▓\\ ▓▓  | ▓▓ ▓▓▓▓▓▓▓▓ ▓▓ ▓▓          | ▓▓ ▓▓_____ \n");
	printf("| ▓▓ | ▓▓ | ▓▓ ▓▓ ▓▓  | ▓▓ ▓▓       ▓▓ ▓▓  | ▓▓\\▓▓     \\ ▓▓ ▓▓          | ▓▓ ▓▓     \\\n");
	printf(" \\▓▓  \\▓▓  \\▓▓\\▓▓\\▓▓   \\▓▓\\▓▓\\▓▓▓▓▓▓▓ \\▓▓   \\▓▓ \\▓▓▓▓▓▓▓\\▓▓\\▓▓           \\▓▓\\▓▓▓▓▓▓▓▓\n\n\n");
}