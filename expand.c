#include "header.h"
#include <stdio.h>

int	special_char(char c)
{
	if (c == '$' || c == '.' || c == '+' || c == '-' || c == '*' || c == '/'
		|| c == '?' || c == '>' || c == '<' || c == ',' || c == ';' || c == ':'
		|| c == '"' || c == '\'' || c == '=' || c == '+' || c == '-' || c == ')'
		|| c == '(' || c == '&' || c == '^' || c == '%' || c == '#' || c == '@')
		return(0);
	return (1);
}
char	*get_env_value(char *str)
{
	char	*variable;
	t_list	*list;

	list = global;
	variable = ft_strjoin_char(str, '=');
	while(list)
	{
		if(ft_strncmp(variable, list->content, ft_strlen(variable)))
			return(list->content + (ft_strlen(variable)));
		list = list->next;
	}
	return(NULL);
}

int	detect_variable(t_vars *vars, char **new_str, int j)
{
	char	*variable;
	char	*value;
	char	*temp;
	int		i;

	j++;
	i = j;
	while(vars->ar_2d[vars->i_2d][j] && special_char(vars->ar_2d[vars->i_2d][j]) != 0)
		j++;
	variable = ft_substr(vars->ar_2d[vars->i_2d], i, j);
	temp = (*new_str);
	value = get_env_value(variable);
	(*new_str) = ft_strjoin((*new_str), value);
	free(temp);
	return(j);
} 

int	no_quotes(t_vars *vars, char **new_str, int j)
{
	char	*temp;

	while (vars->ar_2d[vars->i_2d][j] && vars->ar_2d[vars->i_2d][j] != '\'', vars->ar_2d[vars->i_2d][j] != '"')
	{
		temp = (*new_str);
		if (vars->ar_2d[vars->i_2d][j] == '$')
			j = detect_variable(vars, new_str, j);
		else
		{
			(*new_str) = ft_strjoin_char((*new_str), vars->ar_2d[vars->i_2d][j]);
			j++;
		}
		free (temp);
	}
}
char    *expand(t_vars *vars)
{
	char	*new_str;
	int		q;
	int		i;
	int		j;

	q = 0;
	i = 0;
	vars->i_2d = 0;
	new_str = malloc(1);
	new_str[0] = '\0';
	while(vars->ar_2d[vars->i_2d])
	{
		j = 0;
		while(vars->ar_2d[vars->i_2d][j])
		{	
			// if (vars->ar_2d[vars->i_2d][j] == '\'')
			// 	j = single_quotes(vars, &new_str, j);
			// else if(vars->ar_2d[vars->i_2d][j] == '\"')
			// 	j = double_quotes(vars, &new_str, j);
			// else
				j = no_quotes(vars, &new_str, j);
			j++;
		}
		vars->ar_2d[vars->i_2d] = (*new_str);
		vars->i_2d++;
	}
}