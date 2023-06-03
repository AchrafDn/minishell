/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:48:13 by kkouaz            #+#    #+#             */
/*   Updated: 2023/05/17 04:15:57 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rest(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!ft_strchr(str, '\n'))
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(ft_strlen(str) - i + 1);
	if (!res)
		return (NULL);
	i++;
	while (str[i])
	{
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	free(str);
	return (res);
}

char	*ft_myline(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (free(str), free(line), NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(char *var, int fd)
{
	char	*buffer;
	int		rd;

	rd = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(var), NULL);
	while (!ft_strchr(var, '\n') && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			free(var);
			return (NULL);
		}
		buffer[rd] = '\0';
		var = ft_strjoin_g(var, buffer);
	}
	free(buffer);
	return (var);
}

char	*get_next_line(int fd)
{
	static char	*var;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	var = ft_read(var, fd);
	if (!var)
		return (NULL);
	line = ft_myline(var);
	var = ft_rest(var);
	return (line);
}
