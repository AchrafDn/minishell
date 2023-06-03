/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:45:57 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/03 01:54:26 by kkouaz           ###   ########.fr       */
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
# include "gcl/get_next_line.h"
# include <signal.h>
#include <sys/stat.h>



typedef struct t_norm
{
	int flag;
} t_norm;

typedef struct  t_list
{
	char *content;
	struct t_list  *next;
} t_list;

 typedef struct g_global
 { 
 	t_list *global;
 	int status;
 } g_global;
 g_global gllobal;
typedef struct t_files
{
	char			*file;
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

void  sighandle(int num);
void sigint_handle(int sig_num);
int ft_check_n(char *command);
void printf_env(char **arr, int i);
int					*open_infiles(t_cmd *cmd);
int					ft_strcmp(char *s1, char *s2);
int					heredoc_process(t_files cmd);
int					check_heredoc(t_cmd *cmd,  t_norm **var);
void				exec(t_cmd *cmd, int i);
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
t_cmd				*ft_lstnew_1(int i);
t_cmd				*ft_lstlast_1(t_cmd *lst);
void				ft_lstadd_back_1(t_cmd **lst, t_cmd *new);
t_cmd				*ft_lstlast_1(t_cmd *lst);
void				error(char *s, int fd, int ex);
t_list				*ft_lstnew(char *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	lstsize(t_list *tmp);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
//void	heredoc_process(t_cmd *cmd);
int open_outfiles(t_cmd *cmd);
void	process(t_cmd *cmd, int in, int out, int count, int ends , t_norm *var, int *pid, int index);
void	child_process(t_cmd *cmd, int in,int out, int *fds, int count, int end , t_norm *var);
char  **fill_arr(void);
t_list	*my_env(char **env);
void	ft_execute(t_cmd *cmd, char ** arr);
void	not_found(char *s1, char *s2, int ex);
void	protection(char **command, char **arr);
char	**find_path(char **arr);
char	**myfree(char **p);
int	is_builtin(char **cmd );
void builtins(char **command , int fd);
int echo_process(char **command, int fd);
int 	cd_process(char **command);
int pwd_process(int fd);
int exit_process(char **command);
int unset_process(char **command);
int env_process(char **command , int fd);
int export_process(char **command,  int fd);
char 	*get_env(char *s);
void	ft_check(char *cmd);
void remove_list(t_list **head, char *key);
int ft_parse(char *cmd);
void selection_sort(char **arr, int n);
void export1(char **command, char **arr, int fd);
void export2(char *command, char **arr, char *var, char **fd);
char  *search(char **arr, char *command);
void	process(t_cmd *cmd, int in, int out, int count ,int ends,  t_norm *var, int *pid, int index);
// readline :
void rl_replace_line(const char *text, int a);
void heredoc_handle(int num);
#endif

//
