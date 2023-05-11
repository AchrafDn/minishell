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

t_cmd	*ft_lstnew()
{
	t_cmd *p;

	p = malloc(sizeof(t_cmd)); //free
	if (!p)
		return (NULL);
	p->next = NULL;
	return (p);
}