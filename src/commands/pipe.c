
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
	while(i < count - 1)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}



void	child_pr(int (*fd)[2], int i, int count)
{
	if(i == 0)
	{
		dup2(fd[0][1], 1);
	}
	else if (i == count - 1)
	{
		dup2(0, fd[i - 1][0]);
	}
	else
	{
		dup2(fd[i - 1][0], 0);
		dup2(fd[i][1], 1);
	}
	fd_close(fd, count);
}


// void	running_pipe(t_tokens **token, t_env **env)
// {
// 	int			(*fd)[2];
// 	int			i;
// 	pid_t		*child;
// 	t_tokens	*tk;
// 	t_count		*all_count;
// 	tk = *token;

// 	i = 0;
// 	all_count = NULL;
// 	all_count = count_all(token);
// 	child = malloc(sizeof(int)* (*token)->token_count);
// 	fd = ft_calloc(sizeof(int *), (*token)->token_count - 1);
// 	ft_pipe_call(fd, (*token)->token_count);
// 	while (tk)
// 	{
// 		child[i] = fork();
// 		if (child[i] == -1)
// 		{
// 			child_error(i, child );// petqa 
// 			break;
// 		}
// 		else if(child[i] == 0)
// 		{
// 			printf("i = %d\n", i);
// 			printf("--tok--=>%s\n", (*token)->cmd[0]);
// 			child_pr(fd, i, (*token)->token_count);
// 			//exit(0);// eli petq a dzel
// 			// if (i == 0)
// 			// 	close(fd[0][1]);
// 			// else if ((*token)->token_count - 1 == 1)
// 			// 	close(fd[0][0]);
// 			// else
// 			// 	{
// 			// 		close(fd[i - 1][0]);
// 			// 		close(fd[i][1]);
// 			// 	}
// 			running_p(&tk, env, fd, i);
// 		}
// 	i++;
// 		tk = tk->next;
// 	}
// 	// 	while(++i < 3)
// 	// {
// 	// 	close(fd[i][0]);
// 	// 	close(fd[i][1]);
// 	// }
// 	fd_close(fd, (*token)->token_count);
// 	while(wait(0) != -1)
// 	;
// 	printf("\n");
// }




// Manyyy es chatGPT i aracna vrody ashxatuma bayc sega qcum 



void child_prr(int (*fd)[2], int i, int count)
{
    if (i == 0)
    {
        // Redirect stdout to write end of first pipe
        dup2(fd[0][1], STDOUT_FILENO);

        // Close read end of first pipe
        close(fd[0][0]);
    }
    else if (i == count - 1)
    {
        // Redirect stdin to read end of last pipe
        dup2(fd[i - 1][0], STDIN_FILENO);

        // Close write end of last pipe
        close(fd[i - 1][1]);
    }
    else
    {
        // Redirect stdin to read end of current pipe
        dup2(fd[i - 1][0], STDIN_FILENO);

        // Redirect stdout to write end of next pipe
        dup2(fd[i][1], STDOUT_FILENO);

        // Close read end of current pipe
        close(fd[i - 1][1]);

        // Close write end of next pipe
        close(fd[i][0]);
    }
}

void running_pipe(t_tokens **token, t_env **env)
{
    int (*fd)[2];
    int i;
    pid_t *child;
    t_tokens *tk;
    t_count *all_count;
	(void)env;
    tk = *token;
    i = 0;
    all_count = NULL;
    all_count = count_all(token);
    child = malloc(sizeof(pid_t) * tk->token_count);
    fd = ft_calloc(sizeof(int *), tk->token_count - 1);

    // Check if pipe was successfully created
    ft_pipe_call(fd, tk->token_count);
    // {
    //     perror("pipe");
    //     return;
    // }

    while (tk)
    {
        child[i] = fork();
        if (child[i] == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (child[i] == 0)
        {
            child_prr(fd, i, tk->token_count);

            // Execute child command
            execvp(tk->cmd[0], tk->cmd);

            // If execvp returns, there was an error
            perror("execvp");
            exit(EXIT_FAILURE);
        }

        i++;
        tk = tk->next;
    }

    // Close all pipe file descriptors
    fd_close(fd, tk->token_count);

    // Wait for all child processes to finish
    for (i = 0; i < tk->token_count; i++)
    {
        waitpid(child[i], NULL, 0);
    }
}


