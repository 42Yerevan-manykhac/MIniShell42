
#include "minishell.h"

int	cheack_front(char *str, int *x)
{
	int	i;

	i = *x;
	while (str[*x] == ' ')
			(*x)++;
	while (!ft_strchr(METACHARS, str[*x]) && str[*x])
		(*x)++;
	if (*x - i - 1 <= 0)
		return (1);
	return (0);
}

int	cheack_back(char *str, int x)
{
	int	i;

	while (str[x] == ' ')
			x--;
	i = x;
	while (!ft_strchr(METACHARS, str[x]) && str[i])
		x--;
	if (i - x <= 0)
		return (1);
	return (0);
}
