/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:08:06 by adadoun           #+#    #+#             */
/*   Updated: 2022/11/01 14:11:44 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stddef.h>
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<string.h> //printf
# include<fcntl.h> 

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *s, char c);

#endif