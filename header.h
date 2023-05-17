/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:45:57 by adadoun           #+#    #+#             */
/*   Updated: 2023/05/14 15:46:00 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct t_files
{
	char			*arr_file;
	int				type;
}					t_files;

typedef struct t_cmd
{
	int				index;
	char			**command;
	struct t_files	*files;
	struct t_cmd	*next;
}					t_cmd;

typedef struct t_args
{
	int				cmd_index;
}					t_args;

typedef struct t_vars
{
	int				word;
	char			*mask;
	char			**ar_2d;
	int				i_2d;
	int				i_file;
	int				i_cmd;
}					t_vars;
/**/
void				ft_input_redirection(t_cmd **lst, t_vars *vars);
void				ft_output_redirection(t_cmd **lst, t_vars *vars);
void				ft_herdoc(t_cmd **lst, t_vars *vars);
void				ft_append(t_cmd **lst, t_vars *vars);
void				ft_command(t_cmd **lst, t_vars *vars);
/**/
void				aloc_nodes(t_cmd **lst, t_args *args, t_vars *vars);
void				alloc_cmd(t_cmd **lst, t_vars *vars);
void				alloc_files(t_cmd **lst, t_vars *vars);
/**/
char				*create_list(t_cmd **lst, t_vars *vars);
char				*create_2d_array(t_vars *vars, char *str);
/**/
t_cmd				*ft_lstnew(int i);
t_cmd				*ft_lstlast(t_cmd *lst);
void				ft_lstadd_back(t_cmd **lst, t_cmd *new);
#endif

//
