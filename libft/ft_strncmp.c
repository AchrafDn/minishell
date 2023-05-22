/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:56:29 by adadoun           #+#    #+#             */
/*   Updated: 2023/05/21 12:06:03 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *f, char *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((f[i] || s[i]) && i < n)
	{
		if (f[i] == s[i])
			i++;
		else
			return ((unsigned char)f[i] - (unsigned char)s[i]);
	}
	return (0);
}
