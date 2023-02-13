#include "minishell.h"

void	interrogatory(char **str)
{
    int     i;
    char    *num;

    i = 0;

    num = ft_itoa(exit_code);
    while((*str)[i] && (*str)[i+1] )// nm $? hyt $?//i=3
    {
        if((*str)[i] == '$' && (*str)[i+1]=='?')
        {
            *str = join_dolar_str(*str,  num, i + 1,  2);
            i++;
        }
         else i++;
    }
	free (num);
}