#include "minishell.h"

int export_print(char *str, int z)
{
	(void)str;
	exit_code = z;
	printf("bash: export: `%s': not a valid identifier\n", str);
	return (1);
}

int export_pars(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len = ft_strlen(str);
	if (!(str[0] >= 'a' && str[0] <= 'z') 
	&& !(str[0] >= 'A' && str[0] <= 'Z'))
	{
			export_print(str, 1);
			return (1);
	}
	while (i < len)
	{
		if ((ft_strcrcmp(METAE, str[i]) || (str[i] == '+' && i != len -1)))
		{
			export_print(str, 1);
			return (1);
		}
		i++;
	}
	return (0);
}