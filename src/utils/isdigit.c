#include "minishell.h"

int	ft_isdigit(int argument)
{
	if (argument >= '0' && argument <= '9')
		return (1);
	return (0);
}