#include "header.h"

int echo_process(char **command, int fd)
{
    int i;
    i = 1;
    int flag = 1;

    if (!command[1])
        ft_putchar_fd('\n',fd);

    if(ft_strncmp(command[i], "-n", 2))
    {
        while(command[i])
        {
            ft_putstr_fd(command[i], fd);
            i++;
        }
        ft_putchar_fd('\n', fd);
    }
    else
    {
        while(command[i])
        { 
            while( !ft_strncmp(command[i], "-n", 2))
                {
                flag = ft_check_n(command[i]);
                if(!flag)
                    i++;
                    else 
                        break;
                }
                if(flag)
                {
                    while(command[i])
                    {
                        ft_putstr_fd(command[i], fd);
                        i++;
                    }
                }
            }
    }
    return(0);
}

int ft_check_n(char *command)
{
    int i;
    i = 1;
    while(command[i])
    {
        if(command[i] ==  'n')
            i++;
        else
            return(1);
    }
    return(0);
}