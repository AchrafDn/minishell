#include "header.h"

void	init_arguments(t_args *args, t_vars *vars)
{
	args->cmd_index = 1;
	vars->i_2d = 0;
}

void	fill_cmd(t_cmd **lst, t_args *args, t_vars *vars)
{
	vars->i_file = 0;
	vars->i_cmd = 0;
	(*lst)->index = args->cmd_index++;
	while (vars->ar_2d[vars->i_2d] && vars->ar_2d[vars->i_2d][0] != '|')
	{
		if (vars->ar_2d[vars->i_2d][0] && ft_strcmp(vars->ar_2d[vars->i_2d],
				"<") == 0)
			ft_input_redirection(lst, vars);
		else if (vars->ar_2d[vars->i_2d][0]
				&& ft_strcmp(vars->ar_2d[vars->i_2d], ">") == 0)
			ft_output_redirection(lst, vars);
		else if (vars->ar_2d[vars->i_2d][0]
				&& ft_strcmp(vars->ar_2d[vars->i_2d], "<<") == 0)
			ft_herdoc(lst, vars);
		else if (vars->ar_2d[vars->i_2d][0]
				&& ft_strcmp(vars->ar_2d[vars->i_2d], ">>") == 0)
			ft_append(lst, vars);
		else
			ft_command(lst, vars);
	}
}

// void	resit_args(t_cmd **lst, t_args *args, t_vars *vars)
// {

// }
void	fill_lst(t_cmd **lst, t_args *args, t_vars *vars)
{
	t_cmd *temp1;
	t_cmd *temp2;

	vars->i_2d = 0;
	(*lst) = ft_lstnew();
	temp = (*lst);
	while (vars->ar_2d[vars->i_2d])
	{
		alloc_cmd(&temp, vars);
		alloc_files(&temp, vars);
		fill_cmd(&temp, args, vars);
		if (!vars->ar_2d[vars->i_2d])
			break;
		temp->next = ft_lstnew();
	}
}

void	create_list(t_vars *vars)
{
	t_args args;
	t_cmd *lst;

	init_arguments(&args, vars);
	// aloc_nodes(&lst, &args, vars);
	fill_lst(&lst, &args, vars);
}