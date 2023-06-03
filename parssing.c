/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:02:57 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/02 22:42:56 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	ft_free_2d_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_free_lst(t_cmd **lst)
{
	int		i;
	t_cmd	*temp;

	while ((*lst))
	{
		i = 0;
		ft_free_2d_array((*lst)->command);
		if ((*lst)->files[i].file)
		{
			while ((*lst)->files[i].file)
			{
				if ((*lst)->files[i].file)
					free((*lst)->files[i].file);
				i++;
			}
		}
		free((*lst)->files);
		(*lst)->files = NULL;
		temp = (*lst);
		(*lst) = (*lst)->next;
		free(temp);
	}
}

char	*parssing(t_cmd **lst, t_vars *vars, char *input)
{
	if (!create_2d_array(vars, input))
		return (NULL);
	if (!create_list(lst, vars))
		return (NULL);
	return ("Good");
}

void	ft_free_allocation(t_cmd **lst, t_vars *vars, char *input)
{
	if ((*lst))
		ft_free_lst(lst);
	if (vars->ar_2d)
		ft_free_2d_array(vars->ar_2d);
	if (input)
		free (input);
	input = NULL;
	if (vars->mask)
		free(vars->mask);
}
int	main(int ac, char **av, char  **envp)
{
	(void) av;
	(void) ac;
	t_vars	vars;
	t_cmd	*lst;
	t_list *env;
	char	*input;
	t_cmd  *tmp;
	env = my_env(envp);
	gllobal.global = env;
	lst = NULL;
	int fi = dup(0);
	int fo = dup(1);

	signal(SIGINT, sighandle);
	signal(SIGQUIT, SIG_IGN);
	
	//signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		
		input = readline("$minishell>: ");
		if (input == NULL)
		{
			free(input);
			ft_putstr_fd("exit\n", 1);
			//exit (0);
			return(0);
		}
		if (input && input[0])
		{
			add_history(input);
			parssing(&lst, &vars, input);
			tmp = lst;
			int list_size;
			list_size = 0;
			while(lst)
			{
				list_size++;
				lst = lst->next;
			}
			if(tmp->command)
				exec(tmp, list_size);
				//signal(SIGINT, sigint_handle);
			dup2(fi, 0);
			dup2(fo, 1);
			 ft_free_allocation(&lst, &vars, input);
			// system("leaks minishell");
		}
		
		//input = NULL;
		}
		return(0);
		}

// int	main(int ac, char **av, char **envp)
// {
// 	(void)ac;
// 	(void)av;

// 	t_vars	vars;
// 	t_cmd	*lst;
// 	t_list *env;
// 	char	*input;
// 	t_cmd *tmp;
// 	env = my_env(envp);
// 	global = env;
// 	lst = NULL;
// 	int fi = dup(0);
// 	int fo = dup(1);
// 	while (1)
// 	{
// 		input = readline("$minishell>: ");
// 		if (input == NULL)
// 		{
// 			free(input);
// 			exit (0);
// 		}
// 		if (input && input[0])
// 		{
// 			add_history(input);
// 			parssing(&lst, &vars, input);
// 			printf("%s--\n", lst->command[0]);
// 			tmp = lst;
// 			int list_size;
// 			list_size = 0;
// 			while(lst)
// 			{
// 				list_size++;
// 				lst = lst->next;
// 			}

// 			//if(tmp->command)
// 				//exec(tmp, list_size);
// 				//signal(SIGINT, sigint_handle);
// 			dup2(fi, 0);
// 			dup2(fo, 1);
// 			 ft_free_allocation(&lst, &vars, input);
// 			 //system("leaks minishell");
// 		}
// 		input = NULL;
// 		// add_history(input);
// 		// if (input[0] == '\0')
// 		// {
// 		// 	free(input);
// 		// 	continue ;
// 		// }
// 		// parssing(&lst, &vars, input);
// 		// // excution(&lst, vars, env);
// 		// ft_free_allocation(&lst, &vars, input);
// 	}
// 	return (0);
// }
