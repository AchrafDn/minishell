/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:40:10 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/03 01:45:42 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	process(t_cmd *cmd, int in, int out, int count ,int ends,  t_norm *var, int *pid, int index)
{
	// int		id;
    int fds[2];
	t_cmd *tmp = cmd;

	if(is_builtin(tmp->command ) == 1 && tmp->index == 1 && !tmp->next)
	{
		builtins(tmp->command, out);
			return;
	}
	if (pipe(fds) == -1)
		error("error", 2, 1);
	pid[index] = fork();
	if (pid[index] == 0)
	{
		child_process(cmd, in, out, fds, count, ends, var);
	}
	if (pid[index] == -1){
		perror("Bash : ");
	}
		// error("error", 2, 1);
	close(fds[1]);
	dup2(fds[0], 0);
	close(fds[0]);

	//waitpid(pid[i],NULL, 0);
	// int ji= 0;
	// while (ji < count )
	// {
	// 	waitpid(pid[ji],NULL, 0);
	// 	ji++;
	// }
	
}
void	child_process(t_cmd *cmd, int in,int out, int *fds, int count, int end, t_norm *var)
{
    char **arr;
	t_cmd *tmp;
   arr = NULL;
   arr = fill_arr();
   tmp = cmd;
	

		if (cmd->index == 1)
		{	 
			if (in == -1)
				exit(1);

			if(var->flag == 3 || in == -2)
			{
				dup2(end, 0);
				close(end);
			}
			// if (in != 0)
			// 	dup2(in ,0);
		}
		if (cmd->index == count)
		{
			if (in != 0)
				dup2(in ,0);
			if (out == -1)
				exit(1);
			if (out != 1)
				if (dup2(out, 1) == -1)
					error("erroorrrr", 2, 1);
		}
		else 
		{
			if (in != 0)
				dup2(in ,0);
			if (out != 1)
			{
				dup2(out, 1);
				close(fds[1]);
			}
			else
			{
				dup2(fds[1],1);
				// dup2(fds[0], 0);
				// close(fds[0]);
				// // close(fds[1]);
			}
			
		}
		close(fds[0]);
		close(fds[1]);
		ft_execute(cmd, arr);
	}

void	ft_execute(t_cmd *cmd, char ** arr)
{
	char	**paths;
	char	*joined;
	char	*path;
	int		i;
	i = 0;
	if (!cmd->command || cmd->command[0][0] == '\0')
		not_found("command not found: ", cmd->command[0], 127);
	
	if (cmd->command[0][0] == '/')
		protection(cmd->command, arr);
	paths = find_path(arr);
	
	while (paths && paths[i])
	{
	
		joined = ft_strjoin(paths[i++], "/");
		path = ft_strjoin(joined, cmd->command[0]);
		
		 if(is_builtin(cmd->command ) == 1 )
  		 {
   		builtins(cmd->command, 1);
		exit(0);
   		}
		else if (access(path, X_OK) == 0)
		{
			if (execve(path, cmd->command, arr) == -1)
				fprintf(stderr, "errrro0oooooor\n");
			}
		// free(path);
		// free(joined);
	}
	//printf("%s---\n", cmd->command[0]);
	myfree(paths);
	perror(cmd->command[0]);
	//printf("whats wrong\n");
	//not_found("command not found: ", cmd->command[0], 127);
	myfree(cmd->command);
	exit(127);
}
