#include "minishell.h"


//Redirecting Output
void	redirection_output(char *file, int i) //>
{

	// char *str;
	// str = malloc(sizeof(char ) *1 );

	// str[0] = file[0];
	int	fd;
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (i)
	{
		dup2(fd, 1);
	}
	close(fd);
	// printf("zzzz%s\n", file);

}

void	redirection_output_append(char *file, int i) // >>
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (i)
	{
		dup2(fd, 1); // 1 = stdout
	}
	close(fd);
}


//Redirecting Input

void	 redirection_input(char *file, int i) //  cat < filename
{
	int	fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd < 0)
	{
		printf("error\n");
		close(fd);
		return ;
	}
	if	(i)
		dup2(fd, 0); // 0 = stdin
	close(fd);
}

//heredoc

void	heredoc(char *key, int i)
{
	char	*file;
	char	*hrd;
	int		fd;

	file = ft_strjoin(".hrd", key);
	// ft_signal_handling(1);
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		hrd = readline("heredoc> ");

		if (!hrd)
			break ;
		if (ft_strcmp1(key, hrd) == 0)
		{
			free(hrd);
			break ;
		}
	
		write(fd, hrd, ft_strlen(hrd));
		write(fd, "\n", 1);
		free(hrd);
	}
	// if (hrd == 0)
	// 	 	handleterm(0);
	if (i)
	{
		close(fd);
		fd = open(file, O_RDONLY);
		dup2(fd, 0);
		close(fd);
	}
	 unlink(file);
	free(file);
	
}
