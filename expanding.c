/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:57:54 by adadoun           #+#    #+#             */
/*   Updated: 2023/05/29 15:58:17 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	detect_2(t_vars *vars, char *value, int nb)
{
	char	*temp;

	temp = vars->str_exp;
	if (nb == 1)
		vars->str_exp = ft_strjoin_char(vars->str_exp, '$');
	else
		vars->str_exp = ft_strjoin(vars->str_exp, value);
	free (temp);
}

void	detect_variable(t_vars *vars)
{
	char	*variable;
	char	*value;
	int		i;

	vars->i_xp++;
	i = vars->i_xp;
	if (vars->ar_2d[vars->i_2d][i] == '\0'
		|| special_char(vars->ar_2d[vars->i_2d][i]) == 0)
	{
		detect_2(vars, NULL, 1);
		return ;
	}
	while (vars->ar_2d[vars->i_2d][vars->i_xp]
			&& special_char(vars->ar_2d[vars->i_2d][vars->i_xp]) != 0)
		vars->i_xp++;
	variable = ft_substr(vars->ar_2d[vars->i_2d], i, vars->i_xp - i);
	value = get_env_value(variable);
	if (value)
		detect_2(vars, value, 2);
	free (variable);
	free (value);
}

void	no_quotes(t_vars *vars)
{
	char	*temp;

	while (vars->ar_2d[vars->i_2d][vars->i_xp]
			&& vars->ar_2d[vars->i_2d][vars->i_xp] != '\''
			&& vars->ar_2d[vars->i_2d][vars->i_xp] != '"')
	{
		if (vars->ar_2d[vars->i_2d][vars->i_xp] == '$')
			detect_variable(vars);
		else
		{
			temp = vars->str_exp;
			vars->str_exp = ft_strjoin_char(vars->str_exp,
					vars->ar_2d[vars->i_2d][vars->i_xp]);
			vars->i_xp++;
			free (temp);
		}
	}
}

void	double_quotes(t_vars *vars)
{
	char	*temp;

	vars->i_xp++;
	while (vars->ar_2d[vars->i_2d][vars->i_xp]
			&& vars->ar_2d[vars->i_2d][vars->i_xp] != '"')
	{
		if (vars->ar_2d[vars->i_2d][vars->i_xp] == '$')
			detect_variable(vars);
		else
		{
			temp = vars->str_exp;
			vars->str_exp = ft_strjoin_char(vars->str_exp,
					vars->ar_2d[vars->i_2d][vars->i_xp]);
			vars->i_xp++;
			free (temp);
		}
	}
	vars->i_xp++;
}

void	single_quotes(t_vars *vars)
{
	char	*temp;

	vars->i_xp++;
	while (vars->ar_2d[vars->i_2d][vars->i_xp]
			&& vars->ar_2d[vars->i_2d][vars->i_xp] != '\'')
	{
		temp = vars->str_exp;
		vars->str_exp = ft_strjoin_char(vars->str_exp,
				vars->ar_2d[vars->i_2d][vars->i_xp]);
		vars->i_xp++;
		free (temp);
	}
	vars->i_xp++;
}
