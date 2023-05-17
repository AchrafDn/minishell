/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:12:31 by adadoun           #+#    #+#             */
/*   Updated: 2022/10/27 23:38:38 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nword(const char *s, char c)
{
	int		nb;
	size_t	i;
	int		j;
	int		v;

	i = 0;
	nb = 0;
	v = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c && s[i + j] != '"')
			j++;
		if (j != 0)
		{
			i = i + j;
			nb = nb + 1;
		}
		if (s[i] && s[i] == '"')
		{
			i++;
			while (s[i] != '"')
				i++;
			i++;
		}
		else
			i++;
	}
	return (nb);
}

static void	ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

static char	**ft_res(char **ptr, char *s, char c, int k)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c && s[i + j] != '"')
			j++;
		if (j != 0)
		{
			if (s[i + j] == '"')
				j--;
			ptr[k] = ft_substr(s, i, j);
			if (!ptr[k])
			{
				ft_free(ptr);
				return (NULL);
			}
			i = i + j;
			k++;
		}
		if (s[i] && s[i] == '"')
		{
			j = 1;
			while (s[i + j] != '"')
				j++;
			ptr[k] = ft_substr(s, i, j + 1);
			if (!ptr[k])
			{
				ft_free(ptr);
				return (NULL);
			}
			i = j + 2;
			k++;
		}
		else
			i++;
	}
	ptr[k] = 0;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		nb;

	if (!s)
		return (NULL);
	nb = nword(s, c);
	ptr = malloc(sizeof(char *) * (nb + 1));
	if (!ptr)
		return (NULL);
	return (ft_res(ptr, (char *)s, c, 0));
}
