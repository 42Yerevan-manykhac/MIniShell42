#include "minishell.h"

void ft_fill_red(t_tokens *tk, int flag, char *str)
{

    static int rld = 0;
   // t_tokens *tk;

    //tk = *token;
    if (rld == 0)
    {
        printf("CCCCCC\n");
       tk->head_redct = malloc(sizeof(t_redirects));
        rld = 1;
    }
    printf(",STR,%s\n", str);
    tk->head_redct->del = str;

    tk->head_redct->flag = flag;
    //tk->head_redct->next = NULL;
   tk->head_redct =  tk->head_redct->next;
      printf("FFFFF\n");
     tk->head_redct = malloc(sizeof(t_redirects));
printf("DDDDD\n");
}

int any_quote(char *str,int i)
{
    if (str[i] == '\'')
		i = find_end_of_single_quote(str, i);
	else if (str[i] == '\"')
		    i = find_end_of_double_quote(str, i);
    return (i);
}

void ft_smart_sub1(t_tokens *tk, char *rdl)
{
    int i;
    int j;
    int cmd;

    //t_tokens *tk;
    //tk = *token;
    cmd = 0;
    i = 0;
    j = 0;
  
(void)cmd;
    while (rdl[i])
    {
        if (rdl[i] != '>' && rdl[i] != 0 && rdl[i] != ' ')
        {
            while (rdl[i] && rdl[i] != ' ' && rdl[i] != '>' && rdl[i] != '<')
            {
                i = any_quote(rdl, i);
                i++;
            }
            tk->cmd[cmd] = ft_substr(rdl, j, i);
            // printf("i = %d, j = %d\n", i, j);
            //  printf("cmd=%s, int=%d\n", tk->cmd[cmd], cmd);
            cmd++;
        }
        j = i;
        // if(rdl[i] == '\"' && rdl[i] == '\'')
        // {
        //     i = any_quote(rdl, i);
        //     tk->cmd[i] = ft_substr(rdl, j, i);
        // }
        j = i;
        if (rdl[i] == '>' && rdl[i + 1] != '>')
        {
            while (rdl[i] && rdl[i] != ' '  && rdl[i] != '\''  && rdl[i] != '\"')
                i++;
            ft_fill_red(tk, 3, ft_substr(rdl, j, i));
        }
        if (rdl[i] == '<' && rdl[i + 1] == '<')
        {
            while (rdl[i] && rdl[i] != ' ')
                i++;
            ft_fill_red(tk, 3, ft_substr(rdl, j, i));
            tk->head_redct->del = ft_substr(rdl, j, i);
        }
        if (rdl[i] == '>')
        {
            while (rdl[i] && rdl[i] != ' ')
                i++;
            tk->head_redct->del = ft_substr(rdl, j, i);
            tk->head_redct->flag = 1;
            tk->head_redct->next = NULL;
             tk->head_redct =  tk->head_redct->next;
        }
             i++;
        }
}














void ft_smart_sub(t_tokens *tk, char *rdl)
{
    int i;
    int j;
    int cmd;
(void)tk;
    cmd = 0;
    i = 0;
    j = 0;
  

    while (rdl[i])
    {
        printf("--------------------------\n");
        while(rdl[i]==' ')
            i++;
        if(rdl[i] && rdl[i+1] && rdl[i] == '<' && rdl[i+1] == '<' )
        {
            i+=2;
            while(rdl[i] && rdl[i]==' ')
            i++;
            j = i;
            printf(",J,%d\n", j);
            while(rdl[i] && rdl[i]!=' ')
            i++;
            printf(",I,%d\n", i);
           //   printf(",RDL,%s\n", rdl);
           // printf(",SUBSTR,%s\n", ft_substr(rdl, j, i-j));
           ft_fill_red(tk, 3, ft_substr(rdl, j, i-j));
            // tk->head_redct->del = ft_substr(rdl, j, i-j);
        } else i++;
        // if (rdl[i] != '>' && rdl[i] != 0 && rdl[i] != ' ')
        // {
        //     while (rdl[i] && rdl[i] != ' ' && rdl[i] != '>' && rdl[i] != '<')
        //     {
        //         i = any_quote(rdl, i);
        //         i++;
        //     }
        //     tk->cmd[cmd] = ft_substr(rdl, j, i);
        //     // printf("i = %d, j = %d\n", i, j);
        //     //  printf("cmd=%s, int=%d\n", tk->cmd[cmd], cmd);
        //     cmd++;
        // }
        // j = i;
        // // if(rdl[i] == '\"' && rdl[i] == '\'')
        // // {
        // //     i = any_quote(rdl, i);
        // //     tk->cmd[i] = ft_substr(rdl, j, i);
        // // }
        // j = i;
        // if (rdl[i] == '>' && rdl[i + 1] != '>')
        // {
        //     while (rdl[i] && rdl[i] != ' '  && rdl[i] != '\''  && rdl[i] != '\"')
        //         i++;
        //     ft_fill_red(tk, 3, ft_substr(rdl, j, i));
        // }
        // if (rdl[i] == '<' && rdl[i + 1] == '<')
        // {
        //     while (rdl[i] && rdl[i] != ' ')
        //         i++;
        //     ft_fill_red(tk, 3, ft_substr(rdl, j, i));
        //     tk->head_redct->del = ft_substr(rdl, j, i);
        // }
        // if (rdl[i] == '>')
        // {
        //     while (rdl[i] && rdl[i] != ' ')
        //         i++;
        //     tk->head_redct->del = ft_substr(rdl, j, i);
        //     tk->head_redct->flag = 1;
        //     tk->head_redct->next = NULL;
        //      tk->head_redct =  tk->head_redct->next;
        // }
        //      i++;
        // }
}
}
void smart_smart_split(t_tokens **token)
{
    t_tokens *tk;
    tk = *token;
    while (tk)
    {
     //  tk->head_redct = malloc(sizeof(t_redirects));
       printf("BBBBBBB\b");
        ft_smart_sub(tk, tk->rdl);
        tk= tk->next;
    }    
}