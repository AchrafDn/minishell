#ifndef HEADER_H
# define HEADER_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_files
{
	char				*files;
	int					type;
}						t_files;

typedef struct t_cmd
{
	int					index;
	char				**command;
	struct t_files		**files;
	struct t_cmd	*next;
}						t_cmd;

typedef struct t_args
{
	int cmd_index;
	int	number_cmd;
	int	i;
}		t_args;

void	create_list(t_cmd *p, char **str);
t_cmd			*ft_lstnew(char *content, int value);
t_cmd			*ft_lstlast(t_cmd *lst);
void			ft_lstadd_back(t_cmd **lst, t_cmd *new);
#endif