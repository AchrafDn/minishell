
#include "header.h"


void export_process(char **command, int fd)
{
    t_list *tmp;
    int i;
    i = 0;
    char **arr;

    arr = fill_arr();
    tmp = global;
    while(arr[i])
        i++;
    selection_sort(arr, i);
    if (!command[1])
        printf_env(arr, fd);
    export1(command ,arr, i);
}
void printf_env(char **arr, int fd)
{
    int j;
    char **split;
    j  = 0;
    while(arr[j])
    {
        split = ft_split(arr[j], '=');
        split[1] = ft_strjoin(split[1], "\"");
        split[0]= ft_strjoin(split[0], "=\"");
        arr[j] = ft_strjoin(split[0], split[1]);
        arr[j] = ft_strjoin("declare -x ", arr[j]);
        ft_putstr_fd(arr[j],fd);
        write(fd, "\n", 1);
        j++;
    }
    return;
}
void export1(char **command, char **arr, int fd)
{
    int i;
    int a;
    int flag;
    char **var;
    char *s;

    a = 0;
    i  = 1;
    while(command[i])
    {
        flag = ft_parse(command[i]);
        if(flag == 1)
            not_found(command[i], "", 1);
        var = ft_split(command[i], '=');
        if(flag == 3 || !flag)
            s =ft_strjoin(var[0], "=");
        if(flag == 2)
        {
            while(var[0] && var[0][a++]!= '+')
            {
                s[a] = var[0][a];
            }
        }
        export2(command[i], arr, var[0], var);
    }
}

void export2(char *command, char **arr, char *s, char **var)
{
    int i;
    i = 0;
    int flag;

    flag = ft_parse(command);
    if (flag == 0 && !search(arr, command))
        ft_lstadd_back(&global, ft_lstnew(command));
    if (flag == 2)
    {
        if(!search(arr, s))
            s = ft_strjoin(s, var[1]);
        else if(!search(arr, var[0]))
        {
            s = ft_strjoin(s, "=");
            s = ft_strjoin(s, var[1]);
        }
        else
            s = ft_strjoin(search(arr, s), var[1]);
        ft_lstadd_back(&global, ft_lstnew(s));
    }
    if (flag == 3)
    {
        if(search(arr, s))
            remove_list(&global, search(arr, s));
        ft_lstadd_back(&global, ft_lstnew(s));
    }
}

char *search(char **arr, char *command)
{
    int i;

    i = 0;
    while(arr[i])
    {
        if(!ft_strncmp(command, arr[i], ft_strlen(command)))
            return(arr[i]);
        i++;
    }
    return(NULL);
}