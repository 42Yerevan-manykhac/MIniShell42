
#include "minishell.h"

// char *get_wrld(int i, char *str)
// {

// }
int if_single_quote(char *str, int i)
{
	(void)i;
	printf("char = %c\n", str[i]);
	while (str[i] && str)
	//while (str[i] && str[i] )
	return (0);
}

int	dolar_pars(char *str, t_env **env)
{
	int	i;
	int x;
	const char *world;
	char *back;
	(void)env;
	i = 0;
	while (str[i] && str[i])
	{
		if (str[i] == '$')
		{
			x = ++i;
			while (str[i] != ' ' && str[i])
				i++;
		if (if_single_quote(str, x))
				return (1);
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