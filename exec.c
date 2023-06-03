/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:56:36 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/03 14:52:20 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void exec(t_cmd *cmd, int i)
{
	int in;
	int status;
	int out;
	int ends;
	//g_global global;
	in = 0;
	t_cmd *tmp;
	t_norm *var;
	var = malloc(sizeof(&var));
	tmp = cmd;
	ends = 0;
	int *pid;

	pid = malloc(i *(sizeof(int)));

	int *fds;
	if( tmp  )
	{
		ends = check_heredoc(tmp ,&var);
	}
 	if( ends == 0 && (!cmd || !cmd->command[0]))
	{
		printf("%d\n", ends);
		perror(cmd->files[0].file);
	}
	else 
	{
		int ka = 0;
		while(cmd && cmd->command[0])
		{
			fds = open_infiles(cmd);
			in = fds[0];
			out = fds[1];

			process(cmd,in,out,i, ends, var, pid, ka);

			if(cmd->next)
				cmd = cmd->next;
			else
				break;
			ka++;
		}
	}
	 int ji= 0;

	while (waitpid(pid[ji], &status, 0) != -1)
	{
		if(WIFEXITED(status))
			gllobal.status =  WEXITSTATUS (status);
		else if(WIFSIGNALED(status))
			gllobal.status = WTERMSIG(status) + 128;
		ji++;
	}
	
}

int	check_heredoc(t_cmd *cmd,  t_norm **var)
{
	int i;
	int ends;
	// dprintf(2, " here  : %s\n", *cmd->command);
	i = 0;
    while(cmd && cmd->command)
    {
		i = 0;
		while(cmd && cmd->files[i].type!= -1)
		{
        	if(cmd->files[i].type == 2)
			{
				(*var)->flag = 3;
				ends = heredoc_process(cmd->files[i]);
				signal(SIGINT, sighandle);
			}
			i++;
		}
       	cmd = cmd->next;
    }
    return(ends);
}	

int heredoc_process(t_files files)
{
    int fds[2];
    char *line;
    pipe(fds);

	files.file = ft_strjoin(files.file, "\n");
	
	line = "";
	while (line)
	{
		
		ft_putstr_fd("pipe heredoc> ", 1);
		line = get_next_line(0);
		if(!line)
		{
		//ft_putchar_fd('\n', 1);
			break;
			}
		if (ft_strcmp(line, files.file) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line,fds[1]);
		free(line);
	}
	close(fds[1]);
return(fds[0]);
}
