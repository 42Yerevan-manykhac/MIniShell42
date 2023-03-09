
#include "minishell.h"

int	cheack_front(char *str, int *x)
{
	int	i;
	
	while (str[*x] && str[*x] == ' ')
			(*x)++;
	i = *x;
	while (str[*x] && !ft_strchr(METACHARS, str[*x]))
		(*x)++;
		//printf("lal => %d\n", *x-i);
	if (*x - i <= 0)
		return (1);
	return (0);
}

int	cheack_back(char *str, int x)
{
	int	i;
	if (x == 0)
		return (1);
	while (str[x] && str[x] == ' ')
			x--;
	i = x;
	while (!ft_strchr(METACHARS, str[x]) && str[i])
		x--;
	if (i - x <= 0)
		return (1);
	return (0);
}
