#include "minishell.h"

void	unset_cmd(t_env **l_env, char *new_key)
{
	t_env	*env;
	t_env	*rtv;

	env = *l_env;
	rtv = 0;
	if (find_key(l_env, new_key))
	{
		rtv = get_env(l_env, new_key);
		while (env->next != rtv)
			env = env->next;
		env->next = rtv->next;
		one_node_free(&rtv);
	}
}

void	echo_cmd(char **str)
{

	// printf(",,%s\n", str[3]);
	int i;
	int flag;

	flag = -1;
	i = 0;
	if(str[1] && str[1][i]=='-')
	{
		
		i++;
		while(str[1][i]){
			if(str[1][i]=='n')
				i++;
				else {
					flag = 1;
					break;
				}	


		if(i!=2)	flag= 0;
		}
	}
if(flag==0)
	{

		i = 2;
			while(str[i])
			{
				printf("%s ",str[i]);
					i++;
			}
	}

	else if (ft_strcmp(str[1], "-n"))
	{
	i = 0;
		if (str[2])
		{
			i = 2;
			while(ft_strcmp(str[i], "-n"))
					i++;
			while(str[i])
			{
				printf("%s ",str[i]);
					i++;
			}
		}
	}
	else
	{



		if (str[1])
		{
			i = 1;
			while(str[i])
			{
				printf("%s ",str[i]);
				i++;
			}
			printf("\n");
		}
		else printf("\n");
	}
}
//Volodyayi case-ery chnayel
