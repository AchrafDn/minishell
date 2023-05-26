/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:44:29 by adadoun           #+#    #+#             */
/*   Updated: 2022/10/27 00:08:40 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(const char *s1,char s2)
{
	size_t	i;
	char	*p;

	p = (char *)malloc(ft_strlen(s1) + 2);
	if (!p)
		return (NULL);
	i = 0;
	if (s1)
	{	
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
	}
	p[i] = s2;
	p[i + 1] = '\0';
	return (p);
}
