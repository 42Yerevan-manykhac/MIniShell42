 #include "minishell.h"


// int	exit_cmd(char **str)
// {
// 	if (!str[1])
// 	{
// 		write(2, "exit\n", 6);
// 		exit(0);
// 	}
// 	else
// 	if (str_len > 2)
// 		if (tiva)
// 			tpel_error nuyn exit kodov inch vor bashum
// 		else 
// 			tpel_error nuyn exit kodov inch vor bashum;
// 	if (str_len == 1) || else
// 		stugel tiva te che
// 		ete long int ic mexa tpel_error nuyn exit kodov inch vor bashum;
// 	else 
// 		if (tiva te che)
// 			if (tivy > 0 && tivy < 256)
// 				exit (tivy)
// 			else if (tivy > 256)
// 					exit (%tivy)
// 				else if (tivy < 0)
// 						exit (256 - ft_abs(tivy))
// }

// aaaaaaaa


int exit_cmd(char **str)
{
    
    long long num;
     num = ft_atoi(str[1]);
        printf("EXIT: %lld\n", num);
    if(!str[1])
    {
        printf("exit\n");
        exit(0); //hamapatasxan exit_code-ov
    }
     if(str[1] && (!ft_isdigit(str[1][0]) && str[1][0]!='-' &&  str[1][0]!='+'  )   )
     {
         ft_putstr_fd("exit\n", 2);
         ft_putstr_fd("minishell:  exit: numeric argument required\n", 2); //bash: exit: f: numeric argument required
         return (0);
     }
    if(str[2])
    {
         ft_putstr_fd("exit\n", 2);
         ft_putstr_fd("minishell: exit: too many arguments\n", 2);
         return (0);
    }

if(str[1][0]=='-')
{
    if((ft_strlen(str[1])==20 && str[1][19]=='9') || ft_strlen(str[1])>20)
      {
         ft_putstr_fd("exit\n", 2);
         ft_putstr_fd("minishell:  exit: numeric argument required\n", 2); //bash: exit: f: numeric argument required
         return (0);
     }
     else
     {
        ft_putstr_fd("exit\n", 2);
        exit(0); //hamapatasxan exit_code-ov //256-(num*(-1)%256)
     }

}


else if(str[1][0]=='+')
{
    if((ft_strlen(str[1])==20 && (str[1][19]=='8' ||  str[1][19]=='9'))  ||  ft_strlen(str[1])>20)
    {
         ft_putstr_fd("exit\n", 2);
        ft_putstr_fd("minishell:  exit: numeric argument required\n", 2); //bash: exit: f: numeric argument required
        return (0);
    }
     else
     {
        ft_putstr_fd("exit\n", 2);
        exit(0); //hamapatasxan exit_code-ov //num%256)
     }
}
else {
    if((ft_strlen(str[1])==19 && (str[1][19]=='8' ||  str[1][19]=='9'))  ||  ft_strlen(str[1])>19)
    {
         ft_putstr_fd("exit\n", 2);
        ft_putstr_fd("minishell:  exit: numeric argument required\n", 2); //bash: exit: f: numeric argument required
        return (0);
    }
     else
     {
        ft_putstr_fd("exit\n", 2);
        exit(0); //hamapatasxan exit_code-ov //num%256)
     }
}

    return (0);
}



