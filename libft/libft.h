/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:08:06 by adadoun           #+#    #+#             */
/*   Updated: 2023/05/21 12:06:15 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h> //printf
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin_char(const char *s1,char s2);
char	**ft_split(const char *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_str_env_cmp(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif
