
#include "minishell.h"

void ft_pipe_call(int (*fd)[2],int count)
{
	int i;

	i = 0;
	while(i < count - 1)
	{
		pipe(fd[i]);
		i++;
	}
}

void child_error(int i, pid_t *child )
{
	while(i >= 0)
	{
		kill(child[i], SIGKILL);
		waitpid(child[i], NULL, WUNTRACED);
	i--;
	}
	ft_putstr_fd("fork error\n", 2);
}


void fd_close(int (*fd)[2], int count)
{
	int i;
	i = 0;

	while(i < count)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

void	child_pr(int (*fd)[2], int i, int count)
{
	if(i == 0)
		dup2(fd[0][1], 1);
	else if (i == count - 1)
		dup2(fd[i - 1][0], 0);
	else
	{
		dup2(fd[i - 1][0], 0);
		dup2(fd[i][1], 1);
	}
	fd_close(fd, count);
}

void	execve_for_pipes(t_tokens **token, t_env **env)
{
	t_env *path;
    char **splited_path;
    char *new_str;
    char **mx_env;
    int i;

    i = 0;
    path = get_env(env, "PATH");
    splited_path = ft_split(path->value, ':');
    new_str = ft_strjoin("/", (*token)->cmd[0]);
	create_the_paths(splited_path, new_str);
    free(new_str);
    mx_env = t_env_to_matrix(env);
    cheack_access(splited_path, (*token)->cmd, mx_env);
	exit(0); // exiti codery dzel
    matrix_free(mx_env);
    matrix_free(splited_path);
}

void	running_pipe(t_tokens **token, t_env **env)
{
	int			(*fd)[2];
	int			i;
	pid_t		*child;
	t_tokens	*tk;

	i = 0;
	tk = *token;
	child = malloc(sizeof(int)* (*token)->token_count);
	fd = ft_calloc(sizeof(int *), (*token)->token_count - 1);
	ft_pipe_call(fd, (*token)->token_count);
	while (tk)
	{
		child[i] = fork();
		if (child[i] == -1)
		{
			child_error(i, child );// petqa 
			break;
		}
		else if(child[i] == 0)
		{
			child_pr(fd, i, (*token)->token_count);
			execve_for_pipes(token, env);
			exit(0);// eli petq a dzel
		}
		//printf("%d\n", i);
	i++;
	tk = tk->next;
	}
	fd_close(fd, (*token)->token_count);
	while(wait(0) != -1)
	;
}