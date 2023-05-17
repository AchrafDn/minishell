/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:02:57 by adadoun           #+#    #+#             */
/*   Updated: 2023/05/14 16:02:59 by adadoun          ###   ########.fr       */
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
		if ((*lst)->files[i].arr_file)
		{
			while ((*lst)->files[i].arr_file)
			{
				if ((*lst)->files[i].arr_file)
					free((*lst)->files[i].arr_file);
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

int	main(void)
{
	t_vars	vars;
	t_cmd	*lst;
	char	*input;

	lst = NULL;
	while (1)
	{
		input = readline("$minishell>: ");
		add_history(input);
		if (input[0] == '\0')
		{
			free(input);
			continue ;
		}
		parssing(&lst, &vars, input);
		// excution(&lst, vars, env);
		ft_free_allocation(&lst, &vars, input);
	}
	return (0);
}
