#include "header.h"

// void	aloc_nodes(t_cmd **lst, t_args *args, t_vars *vars)
// {
// 	int	i;

// 	i = 0;
// 	args->numberofnodes = 1;
// 	while (vars->ar_2d[i])
// 	{
// 		if (vars->ar_2d[i][0] == '|')
// 			args->numberofnodes++;
// 		i++;
// 	}
// 	// printf("Number cmd	:	%i\n", args->number_cmd);
// 	(*lst) = malloc(sizeof(t_cmd) * (args->numberofnodes + 1));
// 	if (!(*lst))
// 		exit(1);
// }

void	alloc_cmd(t_cmd **lst, t_vars *vars)
{
	int	i;
	int	n_cmd;

	i = vars->i_2d;
	n_cmd = 0;
	while (vars->ar_2d[i] && vars->ar_2d[i][0] != '|')
	{
		if (vars->ar_2d[i][0] == '>' || vars->ar_2d[i][0] == '<')
			i += 2;
		else
		{
			n_cmd++;
			i++;
		}
	}
	printf("Number cmd	:	%i\n", n_cmd);
	(*lst)->command = malloc(sizeof(char *) * (n_cmd + 1));
	if (!((*lst)->command))
		exit(1);
}

void	alloc_files(t_cmd **lst, t_vars *vars)
{
	int	i;
	int	n_files;

	i = vars->i_2d;
	n_files = 0;
	while (vars->ar_2d[i] && vars->ar_2d[i][0] != '|')
	{
		if (vars->ar_2d[i][0] == '>' || vars->ar_2d[i][0] == '<')
		{
			n_files++;
			i += 2;
		}
		else
			i++;
	}
	printf("Number files	:	%i\n", n_files);
	(*lst)->files = malloc(sizeof(t_files) * (n_files + 1));
	if (!((*lst)->files))
		exit(1);
}
