/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:21:23 by kkouaz            #+#    #+#             */
/*   Updated: 2023/05/17 04:03:25 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*stj;

	i = 0;
	if (!s1 || !s2)
		return (0);
	j = ft_strlen_j(s1);
	stj = malloc(sizeof(char) * (ft_strlen_j(s1) + ft_strlen_j(s2) + 1));
	if (!stj)
		return (0);
	while (s1[i])
	{
		stj[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		stj[i + j] = s2[i];
		i++;
	}
	stj[i + j] = '\0';
	return (stj);
}
