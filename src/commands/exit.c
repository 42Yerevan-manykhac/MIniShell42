#include "minishell.h"


int	exit_cmd(char **str)
{
	if (!str[1])
	{
		write(2, "exit\n", 6);
		exit(0);
	}
	else

}