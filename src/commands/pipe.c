/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:05:30 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/07 12:22:27 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	while (i >= 0)
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
	while (i < count - 1)
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
		dup2(fd[i - 1][0], 0);
	}
	else
	{
		dup2(fd[i - 1][0], 0);
		dup2(fd[i][1], 1);
	}
	fd_close(fd, count);
}

void	running_pipe(t_tokens **token, t_env **env)
{
	int			(*fd)[2];
	int			i;
	pid_t		*child;
	t_tokens	*tk;
	t_count		*all_count;
	tk = *token;

	i = 0;
	all_count = NULL;
	all_count = count_all(token);
	fd = ft_calloc(sizeof(int *), (*token)->token_count-1);
	// fd = malloc(sizeof (*fd) * (*token)->token_count - 1);
	child = malloc(sizeof(int) * (*token)->token_count);
	ft_pipe_call(fd, (*token)->token_count);
	while (tk)
	{
		// printf("SMTH -%d-\n", i);
		child[i] = fork();
		if (child[i] == -1)
		{
			child_error(i, child );// petqa 
			break;
		}
		else if (child[i] == 0)
		{
			// printf("(*token)->token_count = %d\n", (*token)->token_count);
		//	sleep(2000);
			running_p(&tk, env, fd, i);
			exit(1);//exit anel statusov voch te 1-ov
		}
		i++;
		tk = tk->next;
	}
	//printf("++SMTH++\n");
	fd_close(fd, (*token)->token_count);
	//while(wait(0) != -1);
	for (i = 0; i < (*token)->token_count; i++)//stex dambul pah kar
    {
        waitpid(child[i], NULL, 0);
    }
	// printf("\n");
}




// Manyyy es chatGPT i aracna vrody ashxatuma bayc sega qcum 





// void running_pipe(t_tokens **token, t_env **env)
// {
//     int (*fd)[2];
//     int i;
//     pid_t *child;
//     t_tokens *tk;
//     t_count *all_count;
// 	(void)env;
//     tk = *token;
//     i = 0;
//     all_count = NULL;
//     all_count = count_all(token);
//     child = malloc(sizeof(pid_t) * tk->token_count);
//     fd = ft_calloc(sizeof(int *), tk->token_count - 1);

//     // Check if pipe was successfully created
//     ft_pipe_call(fd, tk->token_count);
//     // {
//     //     perror("pipe");
//     //     return;
//     // }
      
//     while (tk)
//     {
//         child[i] = fork();
//         if (child[i] == -1)
//         {
//             perror("fork");
//             exit(EXIT_FAILURE);
//         }
//         else if (child[i] == 0)
//         {
//             child_prr(fd, i, tk->token_count);

//             // Execute child command
//             execvp(tk->cmd[0], tk->cmd);

//             // If execvp returns, there was an error
//             perror("execvp");
//             //exit(EXIT_FAILURE);
//         }

//         i++;
//         tk = tk->next;
//     }

//     // Close all pipe file descriptors
//     fd_close(fd, tk->token_count);

//     // Wait for all child processes to finish
//     for (i = 0; i < tk->token_count; i++)
//     {
//         waitpid(child[i], NULL, 0);
//     }
// }


