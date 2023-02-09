#include "minishell.h"



void ft_fill_red(t_tokens **token, int flag, char *str)
{

    t_tokens *tk;
    t_redirects *red = NULL;
    
    tk = *token;
    red = new_t_redirects(flag, str, NULL);

    t_redirects_add_back(&(*token)->head_redct, red);

}

int any_quote(char *str, int i)
{
    if (str[i] == '\'')
        i = find_end_of_single_quote(str, i);
    else if (str[i] == '\"')
        i = find_end_of_double_quote(str, i);
    return (i);
}


void ft_smart_sub(t_tokens **tk, char *rdl, t_tokens **hert) 
{
    char    *tmp;
    int i;
    int j;
    int k;

    tmp= NULL;
    k = 0;
    i = 0;
    j = 0;


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
            while (rdl[i]!='<' && rdl[i]!='>' &&  rdl[i]!='\0')
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
    printf(",TMP,%s\n", tmp);
    
         (*hert)->cmd = smart_split(tmp, ' ');
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
}