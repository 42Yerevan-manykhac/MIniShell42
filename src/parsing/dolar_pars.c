
#include "minishell.h"

int go_until_spasce(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}
char	*join_dolar_str(char *str, char *world, int x, int z)
{
	int	len_s;
	char *new_str;
	(void)z;

	len_s = ft_strlen(str);
	new_str = ft_substr(str, 0, x - 1);
	if (world)
		new_str = ft_strjoin(new_str, world);
	new_str = ft_strjoin(new_str, ft_substr(str, x + z - 1, len_s));
	free(str);
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

void	dolar_pars(char **str, t_env **env)
{
	int		i;
	int		x;
	char	*world;
	char	*back;
	(void)env;

	i = 0;
	x = 0;
	while ((*str)[i] != 0)
	{
		if ((*str)[i] == '\'')
			i = find_end_of_single_quote(*str, i);
		if ((*str)[i] == '<' && (*str)[i + 1] && (*str)[i + 1] == '<' )
			i = go_until_spasce(*str, i);
		if ((*str)[i] == '$' && (*str)[i + 1] != ' ' && (*str)[i + 1])
		{
			x = ++i;
			while ((*str)[i] != ' ' && (*str)[i] && (*str)[i] != '$' && (*str)[i] != '"')
				i++;
			world = ft_substr(*str, x, i - x);
			back = getenv(world);
			*str = join_dolar_str(*str, back, x, i - x + 1);
			if ((*str)[i] == '$')
				i--;
			i = x - 1;
			free(world);
		}
		i++;
	}
}
//dolar , export unset