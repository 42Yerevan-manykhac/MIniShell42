#include "minishell.h"
int any_quote(char *str,int i)
{
     if (str[i] == '\'')
		i = find_end_of_single_quote(str, i);
	else if (str[i] == '\"')
		    i = find_end_of_double_quote(str, i);
    return (i);
}

void ft_smart_sub(t_tokens **token, char *str)
{
    int i;
    int j;
    int cmd;

    t_tokens *tk;
    tk = *token;
    cmd = 0;
    i = 0;
    j = 0;
    while (str[i])
    {
        //i = any_quote(str, i);
        if (str[i] != '>' && str[i] != '<' && str[i] != ' ')
        {
            while (str[i] && str[i] != ' ' && str[i] != '>' && str[i] != '<')
                i++;
            tk->cmd[cmd] = ft_substr(str, j, i);
            printf("cmd=%s, int=%d\n", tk->cmd[cmd], cmd);
            cmd++;
        }
        j = i;
        // if(str[i] == '\"' && str[i] == '\'')
        // {
        //     i = any_quote(str, i);
        //     tk->cmd[i] = ft_substr(str, j, i);
        // }
        j = i;
        if (str[i] == '>' && str[i + 1] != '>')
        {
            while (str[i] && str[i] != ' ')
                i++;
                printf("gg\n");
            tk->head_redct->del = ft_substr(str, j, i);
             printf("red=%s\n",  tk->head_redct->del);
            tk->head_redct->flag = 3;
            tk->head_redct->next = NULL;
            tk->head_redct =  tk->head_redct->next;

        }
        if (str[i] == '<' && str[i + 1] == '<')
        {
            while (str[i] && str[i] != ' ')
                i++;
            tk->head_redct->del = ft_substr(str, j, i);
            tk->head_redct->flag = 2;
            tk->head_redct->next = NULL;
             tk->head_redct =  tk->head_redct->next;
        }
        if (str[i] == '>')
        {
            while (str[i] && str[i] != ' ')
                i++;
            tk->head_redct->del = ft_substr(str, j, i);
            tk->head_redct->flag = 1;
            tk->head_redct->next = NULL;
             tk->head_redct =  tk->head_redct->next;
        }
             i++;
        }
}

void smart_smart_split(t_tokens **token)
{
    t_tokens *tk;
    tk = *token;
    while (tk)
    {
        ft_smart_sub(token, tk->rdl);
        tk= tk->next;
    }    
}

// while (tk->rdl[i])
//         {
//             if (tk->rdl[i] == '\'')
// 		    i = find_end_of_single_quote(tk->rdl, i);
// 	        else if (tk->rdl[i] == '\"')
// 		    i = find_end_of_double_quote(tk->rdl, i);
//             if (tk->rdl[i] != '>' && tk->rdl[i] != '<')
//             {
//                 while (tk->rdl[i] && tk->rdl[i] != ' ' && tk->rdl[i] != '>' && tk->rdl[i] != '<')
//                     i++;
//                 tk->cmd[cmd] = ft_substr(tk->rdl, j, i);
//                 printf("cmd =>%s, int = %d\n",  tk->cmd[cmd], cmd);
//                 cmd++;
//             }
//             j = i;
//             if (tk->rdl[i] == '\'')
// 		    i = find_end_of_single_quote(tk->rdl, i);
// 	        else if (tk->rdl[i] == '\"')
// 		    i = find_end_of_double_quote(tk->rdl, i);
//             if (tk->rdl[i] == '>' && tk->rdl[i + 1] != '>')
//             {
//                 while (tk->rdl[i] != ' ')
//                     i++;
//             }
//              if (tk->rdl[i] == '<' && tk->rdl[i + 1] == '<')
//             {
//                 while (tk->rdl[i] != ' ')
//                     i++;
//             }
//              if (tk->rdl[i] == '>')
//             {
//                 while (tk->rdl[i] != ' ')
//                     i++;
//             }
//              i++;
//         }