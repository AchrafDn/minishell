/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:37:30 by adadoun           #+#    #+#             */
/*   Updated: 2023/05/29 15:37:33 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	special_char(char c)
{
	if (c == '`' || c == '$' || c == '.' || c == '+' || c == '-'
		|| c == '*' || c == '/' || c == '?' || c == '!' || c == '>'
		|| c == '<' || c == ',' || c == ';' || c == ':' || c == '\\'
		||c == '"' || c == '\'' || c == '=' || c == '+' || c == '-'
		|| c == ')' || c == '(' || c == '&' || c == '^' || c == '%'
		|| c == '#' || c == '@' || c == ' ' || c == '\t')
		return (0);
	return (1);
}

t_list	*my_env(char	**env)
{
	int		i;
	t_list	*list;

	i = 0;
	list = NULL;
	while (env[i])
	{
		ft_lstadd_back_env(&list, ft_lstnew_env(env[i]));
		i++;
	}
	return (list);
}

char	*get_env_value(char *str)
{
	char	*variable;
	char	*value;
	t_list	*list;

	list = g_global;
	variable = ft_strjoin_char(str, '=');
	while (list)
	{
		value = ft_str_env_cmp(variable, list->content);
		if (value)
		{
			free (variable);
			return (value);
		}
		list = list->next;
	}
	free (variable);
	if (value)
		free (value);
	return (NULL);
}

char	*expand(t_vars *vars)
{
	char	*temp;

	vars->i_2d = 0;
	while (vars->ar_2d[vars->i_2d])
	{
		vars->str_exp = malloc(1);
		vars->str_exp[0] = '\0';
		vars->i_xp = 0;
		while (vars->ar_2d[vars->i_2d][vars->i_xp])
		{	
			if (vars->ar_2d[vars->i_2d][vars->i_xp] == '\'')
				single_quotes(vars);
			else if (vars->ar_2d[vars->i_2d][vars->i_xp] == '\"')
				double_quotes(vars);
			else
				no_quotes(vars);
		}
		temp = vars->ar_2d[vars->i_2d];
		vars->ar_2d[vars->i_2d] = vars->str_exp;
		vars->str_exp = NULL;
		vars->i_2d++;
		free (temp);
	}
	return (vars->str_exp);
}
