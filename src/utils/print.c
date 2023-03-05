
#include "minishell.h"

void	print_error(char *cmd, char *str, int code)
{
	exit_code = code;
	ft_putstr_fd("minishell : ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 1);
}
