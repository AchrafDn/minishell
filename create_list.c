#include "header.h"
int	ft_input_redirection(t_cmd *p, char **str, int i)
{
    int j;

	j = 0;
    if(str[i][1] && str[i][1] == '<')
		
}
void    init_arguments(t_args *args)
{
    args->i = 0;
    args->cmd_index = 0;
}
void	create_list(t_cmd *p, char **str)
{
	int	i;
	int	j;
    t_args  *args;

	i = 0;
    init_arguments(args);
	while (str[i])
	{
		j = 0;
		if (str[i][j] && str[i][j] == '>')
		{
            ft_output_redirection(p, str, i);
        }
		else if (str[i][j] && str[i][j] == '<')
		{
            ft_input_redirection(p, str, i);
        }
        else if (str[i][j] && str[i][j] == '|')
        {
            ft_pipe(p);
        }
        else
        {
            ft_command(p);
        }
        i++;
	}
}