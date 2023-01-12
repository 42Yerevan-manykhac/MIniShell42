
#include "minishell.h"

char	*join_dolar_str(char *str, char *world, int x, int z)
{
	int	i;
	int	j;
	int	len_s;
	//int	len_w;
	char *new_str;
	(void)z;
	i = 0;
	j = 0;
//	printf("\nx= %d\n",x);
	len_s = ft_strlen(str);
//	printf("w == %s\n", world);
	//len_w = ft_strlen(world);
	new_str = ft_substr(str, 0, x - 1);
	//len_s = ft_strlen(new_str);
	if (world)
	new_str = ft_strjoin(new_str, world);
	new_str = ft_strjoin(new_str,ft_substr(str, x + z - 1, len_s));
	//free(str);
	str = new_str;
	return (new_str); 
}

int	find_end_of_single_quote(char *str, int i)
{
	i++;
	while (str[i] != '\'')
		i++;
	return (i);
}

char	*dolar_pars(char *str, t_env **env)
{
	int		i;
	int		x;
	char	*world;
	char	*back;
	(void)env;
	i = 0;
	x = 0;
	while (str[i] && str[i])
	{
		if (str[i] == '\'')
			i = find_end_of_single_quote(str, i);
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1])
		{
			x = ++i;
			printf("x = %d\n",x);
			while (str[i] != ' ' && str[i] && str[i] != '$' && str[i] != '"')
				i++;
			world = ft_substr(str, x, i - x);
			printf("world = %s\n", world);
		back = getenv(world);
				str = join_dolar_str(str, back, x, i - x + 1);
			if (str[i] == '$')
				i--;
			free(world);
			i = x - 1;
		}
		i++;
	}
	return (str);
}
//dolar , export unset