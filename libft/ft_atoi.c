/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:16:26 by kkouaz            #+#    #+#             */
/*   Updated: 2023/04/17 21:44:24 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] != 0 && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
				i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
		res = res * 10 + (str[i++] - 48);
	if (sign == 1 && res >= 9223372036854775807)
	{
		printf("exit\n");
		printf(" exit: %s: numeric argument required\n",str);
		exit(255);
	}
	if (sign == -1 && res > 9223372036854775807)
	{
		printf("exit\n");
		printf(" exit: %s: numeric argument required\n", str);
		exit(255);
	}
	return (res * sign);
}
