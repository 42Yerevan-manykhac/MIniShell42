#include "minishell.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if(str[i]=='-' || str[i]=='+' )
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}