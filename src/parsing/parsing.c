#include "minishell.h"

void initializer(t_tokens *token) 
{
	printf("HEllllooooo\n");
	token->count.count_cmd = 0;
	token->count.count_herdoc = 0;
	token->count.count_redirect = 0;
	printf("HEllllooooo\n");
}

void malloc_init(t_tokens *token)
{
	token->redirect = malloc(token->count.count_redirect + 1);
	token->herdoc = malloc(token->count.count_herdoc + 1);
	token->cmd = malloc(sizeof(char) * (token->count.count_cmd + 1));
	//token->redirect[token->count.count_redirect] = 0;
	//token->herdoc[token->count.count_herdoc] = 0;
	//token->cmd[token->count.count_cmd] = 0;

}

void parsing(char *str, t_tokens **token)
{
	int i;
	int j;
	int c_r;
	 int c_c ;
	int c_h;
	t_tokens	*node;

	node = *token;
	j = 0;
	i = 0;
	c_r = 0;
	c_c = 0;
	c_h = 0;
	//malloc_init(node);
	node->cmd = (char **)malloc(sizeof(char *) * (node->count.count_cmd + 1));
	node->herdoc = (char **)malloc(sizeof(char *) * (node->count.count_herdoc + 1));
	node->redirect = (char **)malloc(sizeof(char *) * (node->count.count_redirect + 1));
	node->cmd[node->count.count_cmd] = 0;
	node->herdoc[node->count.count_herdoc]=0;
	node->redirect[node->count.count_redirect]=0;
	while (str && str[i])
	{
		
		if (str[i] == '<' && str[i + 1] != '<')  //< < < <
		{
			i++;
			while( str[i]==' ' )
				i++;
			//printf("str[%d] = -%c-\n", i,str[i]);
			j = i;
			while (!ft_strchr(METACHARS, str[i]) )
				i++;
			//printf("str[%d] = -%c-\n", i,str[i]);
			// char *a = ft_strjoin("<",  ft_substr(str, j, i - j));
			// printf("a=%s\n", a);
			// printf("c_r=%d\n", c_r);
			// node->redirect[c_r++] =  a;
			node->redirect[c_r++] = ft_strjoin("<",  ft_substr(str, j, i - j));
			while( str[i]==' ' )
				i++;
		}  
		else if (str[i] == '<' && str[i + 1] == '<')
		{
			if( str[i + 2] != '<')
			{
				i = i + 2;
				while(str[i] == ' ')
					i++;
				j = i;
				while(!ft_strchr(METACHARS, str[i]))
					i++;
				
			
				node->herdoc[c_h++] = ft_strjoin("<<",  ft_substr(str, j, i - j));
			} 
			else 
			{
				while (str[i] == '<')
					i++;
			}	
		} 
		else if(str[i] == '>' && str[i + 1] != '>')
		{ 	
			i++;
			while(str[i]== ' ')
				i++;
			j = i;
			while(!ft_strchr(METACHARS, str[i]))
				i++;
			

			node->redirect[c_r++] = ft_strjoin(">",  ft_substr(str, j, i - j));
		}
		else if (str[i] == '>' && str[i + 1] == '>')
		{
			if (str[i + 2] != '>'){
				i = i + 2;
				while(str[i] == ' ')
					i++;
				j = i;
				while(!ft_strchr(METACHARS, str[i]))
					i++;
				
				node->redirect[c_r++] = ft_strjoin(">>",  ft_substr(str, j, i - j));
			}
			else 
			{
				while( str[i] == '>')
					i++;
			}
		} 
		else if (str[i]==' ')
		{
			i++;
		} 
		else
		{
			while (str[i] == ' ')
				i++;
			j = i;
			while (str[i] && !ft_strchr(METACHARS, str[i]))
				i++;
			
			node->cmd[c_c] = ft_substr(str, j, i - j);
		
			c_c++;
			// if (c_c == node->count.count_cmd)
			// 	c_c = 0;
		}
	}
	
}

void count_init(char *str, t_tokens **token)
{
	int i;
	int j;
	t_tokens *node;

	node = *token;
	j = 0;
	i = 0;
	initializer(node);
	while (str[i] != '\0')
	{ 
		if (str[i] == '<' && str[i + 1] != '<')
		{ 	
			node->count.count_redirect++;
			i++;
			while(str[i] == ' ')
				i++;
			while(!ft_strchr(METACHARS, str[i]))
				i++;
		}  
		else if (str[i] == '<' && str[i + 1] == '<' )
		{
			if (str[i + 2] != '<')
			{
				i=i+2;
				while(str[i] == ' ')
					i++;
				node->count.count_herdoc++;
				while(!ft_strchr(METACHARS, str[i]))
					i++;
			} 
			else
			{
				while( str[i] == '<')
					i++;
				printf("SyntaxError\n");
			}
		} 
		else if (str[i] == '>' && str[i + 1] != '>')
		{ 	
			i++;
			node->count.count_redirect++;
			while (str[i] == ' ')
				i++;
			while (!ft_strchr(METACHARS, str[i]))
				i++;
		}  
		else if (str[i] == '>' && str[i + 1] == '>' )
		{
			if (str[i + 2] != '>'){
				i = i + 2;
				node->count.count_redirect++;
				while(str[i] == ' ')
					i++;
				while(!ft_strchr(METACHARS, str[i]))
					i++;
			}
			else
			{
				while( str[i] == '>')
					i++;
				printf("SyntaxError\n");
			}
		} 
		else if(str[i] == ' ')
			i++;
		else
		{		
			while(!ft_strchr(METACHARS, str[i]))
				i++;
			node->count.count_cmd++;
			while(str[i] == ' ')
				i++;
		}

	}
	/* 	 i = 0;
		 j = 0;
		 while(i< node->count.count_cmd){
	//	j =0;
	while(node->cmd[i])
	{printf("cmd[%d]!%s!\n",i,node->cmd[i] );


	//printf("cmd[%d]!%s!\n",i,node->cmd[i] );
	i++;}
	}
	i = 0;
	while(i< node->count.count_redirect){
	printf("redirect[%d]!%s!\n",i,node->redirect[i] );
	i++;
	}
	i = 0;
	while(i< node->count.count_herdoc){
	printf("herdoc[%d]!%s!\n",i,node->herdoc[i] );
	i++;
	} */

}


			//printf("firsti=>%d\n", i);
			/* 			printf("c_c=%d\n", c_c);

						char *b = ft_substr(str, j, i - j);
			// token->cmd[c_c] = b;
			int size = ft_strlen(b);
			printf("SIZE%d\n", size);
			// token->cmd[c_c] = malloc(size+1);
			token->cmd[c_c] = malloc(size+1);
			token->cmd[c_c][size] = 0;
			printf("!inside CMD%s!\n", b);
			int k = 0;

			while (b[k])
			{
			//token->cmd[c_c][4]	= 'L';
			printf("-----------------------%d\n", c_c );
			token->cmd[c_c][k] = b[k];
			printf("B%c\n", b[k]);
			k++;
			} */
			//token->cmd[c_c] = b;
			// 	token->cmd[c_c][size] = 0;
			//	printf("token->cmd[c_c]%s\n", token->cmd[c_c]);