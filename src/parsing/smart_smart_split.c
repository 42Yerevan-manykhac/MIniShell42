#include "minishell.h"



int any_quote(char *str, int i)
{
    if (str[i] == '\'')
        i = find_end_of_single_quote(str, i);
    else if (str[i] == '\"')
        i = find_end_of_double_quote(str, i);
    return (i);
}

char *ignore_quote(char *str)
{
    int		i;
    int		j;
    char	*tmp;

    tmp = NULL;    // exit
	i = 0;
	j = 0;
    while(str[i])
    {
        if (str[i]=='\'' || str[i]=='\"' ) // e"x"it // i= 5; j = 2
        	j++;
    i++;
    }
    tmp = malloc(sizeof(char *) * (i - j + 1));
    tmp[i - j] = 0;
    i = 0;
    j = 0;
    while(str[i])
    {
        if(str[i] != '\'' && str[i] != '\"')
        {
            tmp[j] = str[i];
            j++;
        }
        i++;
    } 
    free(str);
    return(tmp);
}


void ft_smart_sub(t_tokens **tk, char *rdl, t_tokens **hert) 
{
    char    *tmp;
	// char	*smt;
	 char 	*ptr;
    int i;
    int j;
	(void)tk;
    j = 0;
    i = 0;
    tmp= NULL;
	(void)ptr;
    while (rdl[i])
    {
        while (rdl[i] && rdl[i] == ' ')
            i++;
        if (rdl[i] && rdl[i + 1] && rdl[i] == '<' && rdl[i + 1] == '<')
        {
            i += 2;
            while (rdl[i] && rdl[i] == ' ')
                i++;
            j = i;
            while (rdl[i] && rdl[i] != ' ')
                i++;
           ft_fill_red(tk, 2, ft_substr(rdl, j, i - j));
	
        }
        else if(rdl[i] && rdl[i + 1] && rdl[i] == '>' && rdl[i + 1] == '>')
        {
            i+=2;
             while (rdl[i] && rdl[i] == ' ')
                i++;
            j = i;
            while (rdl[i] && rdl[i] != ' ')
                i++;
           ft_fill_red(tk, 4, ft_substr(rdl, j, i - j));
        }

         else if(rdl[i] && rdl[i] == '>' )
        {
            i+=1;
             while (rdl[i] && rdl[i] == ' ')
                i++;
            j = i;
            while (rdl[i] && rdl[i] != ' ')
                i++;
           ft_fill_red(tk, 3, ft_substr(rdl, j, i - j));
        }
         else if(rdl[i] && rdl[i] == '<' )
        {
            i+=1;
             while (rdl[i] && rdl[i] == ' ')
                i++;
            j = i;
            while (rdl[i] && rdl[i] != ' ')
                i++;
            ft_fill_red(tk, 1, ft_substr(rdl, j, i - j));
        }
        else 
        {
            j = i;
            while (rdl[i] != '<' && rdl[i] != '>' &&  rdl[i] != '\0')
            {
                if (rdl[i] == '\'')
                    i = find_end_of_single_quote(rdl, i);
                else if (rdl[i] == '\"')
                    i = find_end_of_double_quote(rdl, i);
                    i++;
			}
              tmp= ft_strjoin(tmp, ft_substr(rdl, j, i - j));
		
        }
    }

(void)hert;
    if(tmp)
	{
		ptr= ignore_quote(tmp);
		//tmp = ptr;
		(*hert)->cmd = smart_split(ptr, ' ');
		free(ptr);
	
	}
}

void smart_smart_split(t_tokens **token)
{


	
    t_tokens *tk;
    tk = *token;
    while (tk)
    {
        ft_smart_sub(token, tk->rdl, &tk);
		
        tk = tk->next;
    }
//	printf("het rect = %s\n", )
}