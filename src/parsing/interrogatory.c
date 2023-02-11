#include "minishell.h"

void	interrogatory(char **str)
{
    int i;
    char *tmp;
    char *ptr;
    int j;

    j = 0;
    i = 0;
    char *num;

    num = ft_itoa(exit_code);
printf("----num-----%s\n", num);
    while((*str)[i] && (*str)[i+1] )// nm $? hyt $?//i=3
    {
        
        if((*str)[i] == '$' && (*str)[i+1]=='?')
        {
            tmp = ft_substr(*str,j,i-j);
          //  printf("----tmp-----%s\n", tmp);
            ptr = ft_strjoin(tmp, num);
            i = i+2;
            j = i+2;
            free(tmp);
        }
         else i++;
    }
    printf("j = %d  i = %d\n", j , i);
     tmp = ft_substr(*str,j,i-j);
    printf("----tmp-----%s\n", tmp);
    // ptr = ft_strjoin(ptr, tmp);
printf("----ptr-----%s\n", ptr);
}