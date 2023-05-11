#include "header.h"

void	ft_input_redirection(t_cmd **lst, t_vars *vars)
{
	(*lst)->files[vars->i_file].arr_file = ft_strdup(vars->ar_2d[vars->i_2d + 1]);
	(*(lst))->files[vars->i_file].type = 0;
	printf("--> input --> %i\n",(*(lst))->files[vars->i_file].type);
	printf("--> input --> %s\n",(*(lst))->files[vars->i_file].arr_file);
	vars->i_file++;
	vars->i_2d += 2;
}

void	ft_output_redirection(t_cmd **lst, t_vars *vars)
{
	(*(lst))->files[vars->i_file].arr_file = ft_strdup(vars->ar_2d[vars->i_2d
			+ 1]);
	(*(lst))->files[vars->i_file].type = 1;
	printf("--> input --> %i\n",(*(lst))->files[vars->i_file].type);
	printf("--> input --> %s\n",(*(lst))->files[vars->i_file].arr_file);
	vars->i_file++;
	vars->i_2d += 2;
}

void	ft_herdoc(t_cmd **lst, t_vars *vars)
{
	(*(lst))->files[vars->i_file].arr_file = ft_strdup(vars->ar_2d[vars->i_2d
			+ 1]);
	(*(lst))->files[vars->i_file].type = 2;
	printf("--> input --> %i\n",(*(lst))->files[vars->i_file].type);
	printf("--> input --> %s\n",(*(lst))->files[vars->i_file].arr_file);
	vars->i_file++;
	vars->i_2d += 2;
}

void	ft_append(t_cmd **lst, t_vars *vars)
{
	(*(lst))->files[vars->i_file].arr_file = ft_strdup(vars->ar_2d[vars->i_2d
			+ 1]);
	(*(lst))->files[vars->i_file].type = 3;
	printf("--> input --> %i\n",(*(lst))->files[vars->i_file].type);
	printf("--> input --> %s\n",(*(lst))->files[vars->i_file].arr_file);
	vars->i_file++;
	vars->i_2d += 2;
}

void	ft_command(t_cmd **lst, t_vars *vars)
{
	(*lst)->command[vars->i_cmd] = ft_strdup(vars->ar_2d[vars->i_2d]);
	vars->i_cmd++;
	vars->i_2d++;
}