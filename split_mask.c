/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_mask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:00:50 by adadoun           #+#    #+#             */
/*   Updated: 2023/04/30 19:01:00 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_mask(t_vars *vars, char *str)
{
	int	i;

	i = -1;
	vars->mask = malloc((sizeof(char) + 1) * ft_strlen(str));
	if (!vars->mask)
		exit(1);
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			vars->mask[i] = '0';
		else if (str[i] == '|')
			vars->mask[i] = '3';
		else if (str[i] == '<' || str[i] == '>')
			vars->mask[i] = '2';
		else if (str[i] == '"')
		{
			vars->mask[i++] = '1';
			while (str[i] && str[i] != '"')
				vars->mask[i++] = '1';
			vars->mask[i] = '1';
		}
		else
			vars->mask[i] = '1';
	}
	vars->mask[i] = '\0';
}

int	n_word(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->word = 0;
	while (vars->mask[i])
	{
		j = 0;
		while (vars->mask[i + j] && vars->mask[i + j] != '0'
			&& vars->mask[i] == vars->mask[i + j])
			j++;
		if (j != 0)
		{
			vars->word++;
			i += j;
		}
		else
			i++;
	}
	return (vars->word);
}

void	split_mask(t_vars *vars, char *str)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	vars->ar_2d = malloc((sizeof(char *)) * (n_word(vars) + 1));
	if (!vars->ar_2d)
		exit(1);
	while (vars->mask[i])
	{
		j = 0;
		while (vars->mask[i + j] && vars->mask[i + j] != '0'
			&& vars->mask[i] == vars->mask[i + j])
			j++;
		if (j != 0)
		{
			vars->ar_2d[x] = ft_substr(str, i, j);
			i += j;
			x++;
		}
		else
			i++;
	}
	vars->ar_2d[x] = NULL;
}

void	create_2d_array(t_vars *vars, char *str)
{
	create_mask(vars, str);
	split_mask(vars, str);
}
