/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:14:05 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/02 21:24:06 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t				i;
	unsigned const char	*a1;
	unsigned const char	*a2;

	a1 = (unsigned const char *)s1;
	a2 = (unsigned const char *)s2;
	i = 0;
	while ((a1[i] != '\0' || a2[i] != '\0'))
	{
		if (a1[i] != a2[i])
			return (a1[i] - a2[i]);
		i++;
	}
	return (0);
}

void	error(char *s, int fd, int ex)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	exit (ex);
}
char  **fill_arr(void)
{
	int	i;
	int j;
	t_list *tmp;
	char **arr;
	i = 0;
	j = 0;
	

	tmp = gllobal.global;
	while(tmp)
	{
		tmp =tmp->next;
		i++;
	}
	arr = malloc(i * (sizeof(char *)) + 1);
	tmp = gllobal.global;
	i = 0;
	while(tmp && tmp->content)
	{
		arr[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	arr[i]= NULL;
	return(arr);
}
t_list	*my_env(char **env)
{
	int	i;
	t_list	*list;

	i = 0;
	list = NULL;
	while(env[i])
	{
		ft_lstadd_back( &list ,ft_lstnew(env[i]));
		i++;
		
	}
	return(list);
}
void	not_found(char *s1, char *s2, int ex)
{
	// //write(1,"hey\n",4);
	// ft_putstr_fd(s1, 2);
	// ft_putstr_fd(s2, 2);
	// write(1, "\n", 1);
	//printf("ex = %d\n", ex);
	(void)s2;
	perror(s1);

	exit(ex);
}
void	protection(char **command, char **arr)
{
	if (access(command[0], X_OK) == 0)
		execve(command[0], command, arr);
	else
		not_found(command[0], ": command not found", 127);
}
char	**find_path(char **arr)
{
	char	**mypath;
	int		i;

	i = 0;
	while (arr[i])
	{
	
		if (ft_strnstr(arr[i], "PATH=", 5))
		{
			mypath = ft_split(arr[i] + 5, ':');
			return (mypath);
		}
		i++;
	}
	return (NULL);
}
char	**myfree(char **p)
{
	int	i;

	i = 0;
	if (!p)
		return (NULL);
	while (p[i])
	{
		free (p[i]);
		p[i] = (NULL);
		i++;
	}
	free(p);
	p = NULL;
	return (p);
}