 #include "minishell.h"

int	check_longlongd3(char *str)
{
	int		i;
	char	*max1;

	i = 0;
	max1 = "9223372036854775807";
	while (i <= 18)
	{
		if (str[i] == max1[i] || str[i] < max1[i])
		{
			if (i == 18)
				return (1);
			i++;
		}
		else if (str[i] > max1[i])
			return (0);
	}
	return (0);
}

int	check_longlongd2(char *str)
{
	int		i;
	char	*max;

	i = 1;
	max = "+9223372036854775807";
	while (i <= 19)
	{
		if (str[i] == max[i] || str[i] < max[i])
		{
			if (i == 19)
				return (1);
				i++;
		}
		else if (str[i] > max[i])
			return (0);
	}
	return (0);
}

int	check_longlongd1(char *str)
{
	int		i;
	char	*min;

	min = "-9223372036854775808";
	i = 1;
	while (i <= 19)
	{
		if (str[i] == min[i] || str[i] < min[i])
		{
			if (i == 19)
				return (1);
				i++;
		}
		else if (str[i] > min[i])
			return (0);
	}
	return (0);
}

int	check_longlongd(char *str)
{
	if ((str[0] == '-' && ft_strlen(str) < 20)
		|| (str[0] == '+' && ft_strlen(str) < 20))
		return (1);
	if ((str[0] == '-' && ft_strlen(str) > 20)
		|| (str[0] == '+' && ft_strlen(str) > 20))
		return (0);
	if (str[0] != '-' && str[0] != '+' && ft_strlen(str) > 19)
		return (0);
	if (str[0] == '-' && ft_strlen(str) == 20)
		return (check_longlongd1(str));
	else if (str[0] == '+' && ft_strlen(str) == 20)
		return (check_longlongd2(str));
	else if (str[0] != '+' && str[0] != '-' && ft_strlen(str) == 19)
		return (check_longlongd3(str));
	return (1);
}

int exit_cmd(char **c)
{

    char *str;
    long long num;
    if(!c[1])
    {
		//exit_code = 5 ;
        printf("exit\n");
        exit(0); //hamapatasxan exit_code-ov
    }
	if(!ft_isdigit(c[1]))
	{
		 ft_putstr_fd("exit\n", 2);
         ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
		 exit(0); //hamapatasxan exit_code-ov
	}

        if(c[2]  && ft_isdigit(c[1]) )
    {
         ft_putstr_fd("\n", 2);
         ft_putstr_fd("minishell: exit: too many arguments\n", 2);
         return (0); //durs chi galis // statusy poxel 1
    }
         if(c[2]  && !ft_isdigit(c[1]) )
    {
         ft_putstr_fd("exit\n", 2);
         ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
         exit(255);
    }
    str = ft_cat_str(c[1]); //+000654
 

 if(check_longlongd(str))
 {
    num = ft_atoi(str);
    if(num<0)
    {
  ft_putstr_fd("exit\n", 2);
        exit(256-(num*(-1)%256)); //hamapatasxan exit_code-ov //256-(num*(-1)%256)

    }
    else if(num>=0)
    {
     ft_putstr_fd("exit\n", 2);
	exit(num%256); //hamapatasxan exit_code-ov //num%256)
    }
 }
 else 
 {
    ft_putstr_fd("exit\n", 2);
    ft_putstr_fd("minishell:  exit: numeric argument required\n", 2); //bash: exit: f: numeric argument required
    exit(255);
 }
    free(str);
 



    return (0);
}


//-9223372036854775808  9223372036854775807


