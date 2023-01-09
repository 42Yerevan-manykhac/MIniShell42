
#include "minishell.h"

// char *get_wrld(int i, char *str)
// {

// }
int	if_single_quote(char *str, int i)
{
	int	quote_1;
	int	quote_2;

	quote_1 = 0;
	quote_2 = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			quote_1 += 1;
		if (str[i] == '"')
			quote_2 += 1;
		i++;
	}
	if (quote_1 % 2 != 0 || quote_2 % 2 != 0)
	{
		printf("erorr\n");
		return (1);
	}
	return (0);
}

int	dolar_pars(char *str, t_env **env)
{
	int			i;
	int			x;
	const char	*world;
	char		*back;
	(void)env;
	i = 0;
	x = 0;
	if (if_single_quote(str, x))
			return (1);
	while (str[i] && str[i])
	{
		if (str[i] == '$')
		{
			x = ++i;
		while (str[i] != ' ' && str[i] && str[i] != '$')
				i++;
		if (str[i] == '$')
			i--;
				//printf("\n str[i] = %C", str[i]);
		world = ft_substr(str, x, i);
		printf("str == %s\n", world);
		back = getenv(world);
		printf("str == %s\n", back);
		//char *getenv(const char *name);
		}
		i++;
		//return (0);
	}
	return (0);
}
//dolar , export unset