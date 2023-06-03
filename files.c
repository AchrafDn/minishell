/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:01:55 by kkouaz            #+#    #+#             */
/*   Updated: 2023/05/31 02:14:51 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int *open_infiles(t_cmd *cmd)
{
    int *fd;
   
    int i = 0;
    
    fd = malloc(8);

    fd[0] = 0;
    fd[1] = 1;

    while(cmd->files && cmd->files[i].type != -1)
    {
        if(cmd->files[i].type == 0)
        {
            fd[0] =  open(cmd->files[i].file , O_RDWR , 0644);
            if(fd[0] < 0)
            {
                perror(cmd->files[i].file);
                fd[0] = -1;
                fd[1] = -1;
                break;
            }
        }
        if(cmd->files[i].type == 1)
        {
            fd[1] =  open(cmd->files[i].file ,  O_CREAT |O_TRUNC| O_RDWR, 0644);
    
            if(fd[1] < 0)
            {
                perror(cmd->files[i].file);
               fd[0] = -1;
                fd[1] = -1;
                break;
            }
        }
        if ( cmd->files[i].type == 2)
        {
            fd[0] = -2;
        }
        if ( cmd->files[i].type == 3)
        {
            fd[1] = open(cmd->files[i].file, O_CREAT | O_APPEND | O_RDWR , 0644);
            if(fd < 0)
            {
                perror(cmd->files[i].file);
                fd[0] = -1;
                fd[1] = -1;
                break;
            }
        }
        i++;
    }
    return(fd);
}
int open_outfiles(t_cmd *cmd)
{
    int fd = 1;
    int i = 0;
   
    // if(cmd->files[i].type == -1)
    //     fd=1;
    while(cmd->files[i].type != -1)
    {
        //close(fd);
        if(cmd->files[i].type == 1)
        {
            fd =  open(cmd->files[i].file ,  O_CREAT |O_TRUNC| O_RDWR, 0644);
    
            if(fd < 0)
            {
                perror(cmd->files[i].file);
                return (-2);
            }
        }
        if ( cmd->files[i].type == 3)
        {
            fd = open(cmd->files[i].file, O_CREAT | O_APPEND | O_RDWR , 0644);
            if(fd < 0)
            {
                perror(cmd->files[i].file);
                return (-2);
            }
        }
        i++;
    }
    return(fd);
}