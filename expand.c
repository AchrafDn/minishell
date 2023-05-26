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
	char	*value;
	t_list	*list;

	list = global;
	variable = ft_strjoin_char(str, '=');
	while(list)
	{
		value = ft_str_env_cmp(variable, list->content);
		if(value)
		{
			free (variable);
			return(value);
		}
		list = list->next;
	}
	free (variable);
	free (value);
	return(NULL);
}

void	detect_variable(t_vars *vars)
{
	char	*variable;
	char	*value;
	char	*temp;
	int		i;

	vars->i_xp++;
	i = vars->i_xp;
	while(vars->ar_2d[vars->i_2d][vars->i_xp] && special_char(vars->ar_2d[vars->i_2d][vars->i_xp]) != 0)
		vars->i_xp++;
	variable = ft_substr(vars->ar_2d[vars->i_2d], i, vars->i_xp - i);
	value = get_env_value(variable);
	temp = vars->str_exp;
	vars->str_exp = ft_strjoin(vars->str_exp, value);
	free(variable);
	free(value);
} 

void	no_quotes(t_vars *vars)
{
	while (vars->ar_2d[vars->i_2d][vars->i_xp] && vars->ar_2d[vars->i_2d][vars->i_xp] != '\'' && vars->ar_2d[vars->i_2d][vars->i_xp] != '"')
	{
		if (vars->ar_2d[vars->i_2d][vars->i_xp] == '$')
			detect_variable(vars);
		else
		{
			vars->str_exp = ft_strjoin_char(vars->str_exp, vars->ar_2d[vars->i_2d][vars->i_xp]);
			vars->i_xp++;
		}
	}
}
void	double_quotes(t_vars *vars)
{
	while (vars->ar_2d[vars->i_2d][vars->i_xp] && vars->ar_2d[vars->i_2d][vars->i_xp] != '"')
	{
		if (vars->ar_2d[vars->i_2d][vars->i_xp] == '$')
			detect_variable(vars);
		else
		{
			vars->str_exp = ft_strjoin_char(vars->str_exp, vars->ar_2d[vars->i_2d][vars->i_xp]);
			vars->i_xp++;
		}
	}
}
void	single_quotes(t_vars *vars)
{
	while (vars->ar_2d[vars->i_2d][vars->i_xp] && vars->ar_2d[vars->i_2d][vars->i_xp] != '\'')
	{
		vars->str_exp = ft_strjoin_char(vars->str_exp, vars->ar_2d[vars->i_2d][vars->i_xp]);
		vars->i_xp++;
	}
}

char    *expand(t_vars *vars)
{
	vars->i_2d = 0;
	while(vars->ar_2d[vars->i_2d])
	{
		vars->str_exp = malloc(1);
		vars->str_exp[0] = '\0';
		vars->i_xp = 0;
		while(vars->ar_2d[vars->i_2d][vars->i_xp])
		{	
			if (vars->ar_2d[vars->i_2d][vars->i_xp] == '\'')
				single_quotes(vars);
			else if(vars->ar_2d[vars->i_2d][vars->i_xp] == '\"')
				double_quotes(vars);
			else
				no_quotes(vars);
			vars->i_xp++;
		}
		vars->ar_2d[vars->i_2d] = vars->str_exp;
		vars->str_exp = NULL;
		vars->i_2d++;
	}
	return(vars->str_exp);
}