/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:19:06 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/03 14:51:40 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void  sighandle(int num)
{
    if (num == SIGINT)
    {
        rl_on_new_line();
        write(1, "\n", 1);
        rl_replace_line("", 0);
        rl_redisplay();
    }
    // else if (num == SIGQUIT)
    // {
    //     ft_putstr_fd("exit", 1);
    //     exit(0);
    // }
}
void heredoc_handle(int num)
{
if(num == SIGINT)
    exit(0);
}