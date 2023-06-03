/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 02:58:49 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/02 21:25:56 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

char *get_env(char *s)
{
	t_list *tmp;
	int	i;
	i = 0;
	char *str;

	tmp = gllobal.global;
	s = ft_strjoin(s, "=");
	while(tmp)
	{
		if(!ft_strncmp(tmp->content, s, ft_strlen(s)))
		{
			str= tmp->content;
			while(str[i] == s[i])
				i++;
			return(str+i);
		}
		tmp = tmp->next;
	}
	return(NULL);
}

void	ft_check(char *cmd)
{
	int	i;
	
	i = 0;
	if(cmd[0] == '-' || cmd[0] == '+')
		i++;
	while(cmd[i])
	{
		if( cmd[i] <= '9' && cmd[i] >=  '0')
			i++;
		else
		{
			printf("exit\n");
			printf(" exit: %s: numeric argument required\n", cmd);
			exit(255);
		}
	}
}

void remove_list(t_list **head, char *key)
 {
    t_list *temp = *head, *prev;

    if (temp != NULL && !ft_strncmp(temp->content , key, ft_strlen(key))) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && ft_strncmp(temp->content , key, ft_strlen(key)))
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    printf("removed\n");
    free(temp);
}


int ft_parse(char *cmd)
{
    int i;
    int flag ;
    char **var;
    char *str;
    i = 0;
    flag = 0;

    str= malloc(20);
    if(!ft_isalpha(cmd[0]))
    {
        return(1);
    }
    while(cmd[i])
    {   
         if(cmd[i] == '=' && cmd[i-1]== '+')
            flag = 2;
       else if(cmd[i] == '=')
        {
            flag = 3;
        }
        i++;
    }
    var = ft_split(cmd, '=');
    i = 0;
    while(var[0][i])
        i++;
    if(flag == 2)
         i = i - 1 ;
    int j= 0;
    while(j < i)
    {
    printf(":YES HERE i=%d j=%d \n",j,i);
        str[j] = var[0][j];
        j++;
    }
    str[j]='\0';
    printf("str= %s \n", str);
    i = 0;
   while(str[i])
   {
        if(ft_isalnum(str[i]) || str[i]== '_' )
            i++;
        else
        {
            return(1);
        }

   }
    
    if(!flag)
        return(0);
    return(flag);
}

void selection_sort(char **arr, int n) {
    int i, j, min_idx;
    char *temp;
    i = 0 ;
    while (i < n-1) 
    {
        min_idx = i;
        j = i+1;
        while ( j < n) 
        {
            if (ft_strcmp(arr[j], arr[min_idx]) < 0)
            {
                min_idx = j;
            }
            j++;
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
        i++;
    }
}