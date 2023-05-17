/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:32:36 by adadoun           #+#    #+#             */
/*   Updated: 2022/10/31 20:45:38 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include "libft.h"

t_cmd	*ft_lstnew(int i)
{
	t_cmd	*p;

	i = 0;
	p = malloc(sizeof(t_cmd));
	if (!p)
		return (NULL);
	p->next = NULL;
	return (p);
}
