#include "header.h"

int	is_builtin(char **cmd )
{
	if(!ft_strcmp(cmd[0], "echo") || !ft_strcmp(cmd[0], "cd") ||  !ft_strcmp(cmd[0], "export") 
	||!ft_strcmp(cmd[0] , "unset") || !ft_strcmp(cmd[0], "env") || !ft_strcmp(cmd[0], "pwd") 
	|| ! ft_strcmp(cmd[0], "exit"))
		return(1);
	else 
	return(0);

 }
 void builtins(char **command , int fd)
{

	if (!ft_strcmp(command[0], "echo"))
		echo_process(command, fd);
	if (!ft_strcmp(command[0], "cd"))
		cd_process(command);
	if (!ft_strcmp(command[0], "pwd"))
		pwd_process( fd);
	if (!ft_strcmp(command[0], "export"))
	{
		export_process(command, fd);
		}
	if (!ft_strcmp(command[0], "unset"))
		unset_process(command);
	if (!ft_strcmp(command[0], "env"))
		env_process(command, fd);
	if (!ft_strcmp(command[0], "exit"))
		exit_process(command);

}

int echo_process(char **command, int fd)
{
    int i;
    i = 1;
    int flag = 1;

    if (!command[1])
        ft_putchar_fd('\n',fd);

    else if(ft_strncmp(command[i], "-n", 2))
    {
        while(command[i])
        {
            ft_putstr_fd(command[i], fd);
			ft_putstr_fd(" ", fd);
            i++;
        }
        ft_putchar_fd('\n', fd);
    }
    else
    {
        while(command[i])
        { 
            while ( !ft_strncmp(command[i], "-n", 2))
            {
                flag = ft_check_n(command[i]);
				
                if(!flag)
                    i++;
                else 
				{
				printf(";\n");
                	break;
				}
            }
				printf("%d===\n", i);
				while(command[i])
				{
					ft_putstr_fd(command[i], fd);
					ft_putstr_fd(" ", fd);
					i++;
				}
				return(0);
	
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
// int echo_process(char **command, int fd)
// {
// 	int flag = 1;
// 	int j = 0;
// 	int i = 1;
	
// 	if(!command[1])
// 		ft_putchar_fd('\n',fd);
// 	while (command[i])
// 	{	
// 		j = 0;
// 		if(!ft_strncmp(command[i], "-n", 2))
// 		{
// 			flag = 0;
// 			j++;
			
// 			while(command[i][j])
// 			{
// 				if (command[i][j] != 'n')
// 				{
// 					flag = 1;
// 					i = i - 1;
// 					break;
// 				}
// 				j++;
// 			}
// 		if(flag)
// 			i++;		
// 		}
// 		printf("%d\n", flag);
// 		while(command[i])
// 		{
// 			ft_putstr_fd(command[i], fd);
// 			i++;
// 		}
// 		if(flag)
// 		{
// 			ft_putstr_fd("\n", fd);
// 			return(0);
// 		}
// 		else
// 			return(0);
// 	}
// 	return(0);
// }

int 	cd_process(char **command)
{
	char *dir;
	char *current;
	struct stat	st;
    t_list *tmp;

	tmp = gllobal.global;
	
	current =  getcwd(NULL, 0);

	if(!command[1] || !ft_strcmp(command[1], "~"))
	{
		dir = get_env( "HOME");
		chdir(dir);
	}
	else 
	{	
		if(lstat(command[1], &st)) {
			perror(command[1]);
			return 1;
		}
		dir = command[1];
		if(chdir(dir) == -1)
		{
			perror(dir);
			return 1;
		}
		dir = getcwd(NULL, 0);
	}
	while(tmp)
	{
		if(!ft_strncmp(tmp->content, "OLDPWD", 6))
		{
		 	ft_strlcpy(tmp->content, "OLDPWD=", 8);
			tmp->content =ft_strjoin(tmp->content, current);
			break;
		}
		else
			tmp = tmp->next;
	}
	tmp = gllobal.global;
	while(tmp)
	{
		if(!ft_strncmp(tmp->content,	"PWD", 3))
		{
		 	ft_strlcpy(tmp->content, "PWD=", 5);
			tmp->content= ft_strjoin(tmp->content, dir);
			break;
		}
		else
			tmp = tmp->next;
	}
	return(0);
}

int pwd_process(int fd)
{
	char *dir;

	dir = getcwd(NULL, 0);
	ft_putstr_fd( dir, fd);
	ft_putchar_fd('\n', fd);
	return(0);
}

int exit_process(char **command)
{
	int	nbr;
//	int i = 0;

	// while(command[i])
	// {
	// 	printf("%s-----\n", command[i]);
	// 	i++;
	// }
	
	if(command[1] && command[2])
	{
		// printf("yooo\n");
		printf("exit\n");
		printf("exit: too many arguments\n");
		return(0);
	}
	
	if(!command[1])
	{
		printf("exit\n");
		exit(0);
	}
	if(command[1])
	ft_check(command[1]);
	nbr = ft_atoi(command[1]);
	exit(nbr);
}

int unset_process(char **command)
{
	
	int i;
	char **arr;
	int a;
	a = 0;
int j=  0;

	i = 1;

    arr = fill_arr();
	i = 0;
	while(command[i])
	{
	
		a =  ft_parse(command[i]);
		printf("%d\n", a);
		if(a == 1)
		{
			ft_putstr_fd(command[i], 2);
			ft_putstr_fd(" : not a valid identifier\n", 2);
		}
		j = 0;
		while(arr[j])
		{
			if(!ft_strcmp(ft_split(arr[j], '=')[0], command[i]))
			{
				remove_list(&gllobal.global, arr[j]);
			}
			j++;
		}
		i++;
	}	
return(0);
}

int env_process(char **command , int fd)
{
	t_list *tmp;

	int i = 0;
	tmp = gllobal.global;
	if(command[1])
	{
		ft_putstr_fd("env : ", 2);
		ft_putstr_fd(command[1], 2);
		ft_putstr_fd(": no such file or directory \n", 2);
		exit(127);
	}
	while(tmp)
	{
		i = 0;
		while(tmp->content[i])
		{	
			if(tmp->content[i] == '=')
			{
				ft_putstr_fd(tmp->content, fd);
				ft_putchar_fd('\n', fd);
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
 	return(0);

}

int export_process(char **command, int fd)
{
    t_list *tmp;
    int i;
    i = 0;
    char **arr;

    arr = fill_arr();
		
    tmp = gllobal.global;
    while(arr[i])
        i++;
	//printf("arr :%s--------\n", arr[i- 1]);	
    selection_sort(arr, i);

    if (!command[1])
        printf_env(arr, fd);
	else
   	 export1(command ,arr, i);
	return(0);
}
void printf_env(char **arr, int fd)
{
    int j;
	char *s;
    char **split;
    j  = 0;
    while(arr[j])
    {
        split = ft_split(arr[j], '=');
		if(!split[1])
		{
			if(arr[j][ft_strlen(split[0])] == '=')
				arr[j] = ft_strjoin(arr[j], "\"\"");

			s = ft_strjoin("declare -x ", arr[j]);
		}
		else
		{
			split[1] = ft_strjoin(split[1], "\"");
			split[0]= ft_strjoin(split[0], "=\"");
			s = ft_strjoin(split[0], split[1]);
			s = ft_strjoin("declare -x ", s);
			}
			ft_putstr_fd(s,fd);
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
	(void)fd;
    a = 0;
    i  = 1;
    while(command[i])
    {
        flag = ft_parse(command[i]);
        if(flag == 1)
		{
           ft_putstr_fd(command[i], 2);
           ft_putstr_fd(" : not a valid identifier\n", 2);
		}
        var = ft_split(command[i], '=');
		if (!flag || flag == 3)
		{
			s = ft_strdup(var[0]);
        // if(flag == 3 )
		}
        //     s =ft_strjoin(var[0], "=");
        if(flag == 2)
        {
            while(var[0] && var[0][a] != '\0' && var[0][a]!= '+')
            {
                s[a] = var[0][a];
				a++;
            }
			s[a] = '\0';
        }
        export2(command[i], arr, s, var);
		
		i++;
    }
}

void export2(char *command, char **arr, char *s, char **var)
{
    int i;
    i = 0;
    int flag;
	
    flag = ft_parse(command);
    if (flag == 0 && !search(arr, command))
	{
        ft_lstadd_back(&gllobal.global, ft_lstnew(command));
	}
    if (flag == 2)
    {
	
		arr = fill_arr();
        if(!search(arr, s))
		{ 
			
            s = ft_strjoin(s, ft_strjoin("=" ,var[1]));
		}
    	// else  if(!search(arr, var[0]))
        // {
        //     s = ft_strjoin(s, "=");
        //     s = ft_strjoin(s, var[1]);
        // }
        else
        {
			if(search(arr, s))
			{
                printf("^^^^%s \n", s);
                if(var[1])
                {
                
                    if(search(arr, ft_strjoin(var[0], "=")))
                    {
					printf("yes\n");
                    remove_list(&gllobal.global, search(arr, s));
                    s = ft_strjoin(search(arr, s), "=");
                    s= ft_strjoin(s, var[1]);
                    }
                    else
                    {
                    remove_list(&gllobal.global, search(arr, s));
                    s = ft_strjoin(search(arr, s),var[1]);
                    }
                }
                else
                    s = NULL;
                
			}
        }
        printf("dkheeeeeeelt %s\n", s);
        if(s && *s)
        ft_lstadd_back(&gllobal.global, ft_lstnew(s));
        arr = fill_arr();
    }
    else if (flag == 3)
    {
		arr = fill_arr();
        if(search(arr, s))
		{ 
        printf("%s----..\n", s);
            remove_list(&gllobal.global, search(arr, s));
		}
       
		s= ft_strjoin(s, "=");
		if(var[1])
			s= ft_strjoin(s, var[1]);
        ft_lstadd_back(&gllobal.global, ft_lstnew(s));

		arr = fill_arr();
    }
	//
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

// int export_process(char **command,  int fd)
// {

//     char **arr;
//     t_list *tmp;
//     int flag;
//     char **var;
//     int a = 0;
//     char *s;
//     int i;
//     int j;
//     char *str;
//     t_list *tmps;
// 	int b = 0;

//     i = 0;
//     tmp = global;
//     while(tmp)
//     {
//         tmp = tmp->next;
//         i++;
//     }
	
//     arr = malloc((i + 1) * sizeof(char *));
//     i = 0;
//     tmp = global;
	
//     while(tmp)
//     {
//         arr[i] = ft_strdup(tmp->content);
//         tmp = tmp->next;
//         i++;
//     }
	
//     arr[i] = NULL;
//     selection_sort(arr, i);
//     if(!command[1])
//     {
// 		printf("1\n");
//         j = 0;
//         while(arr[j])
//         {
//             arr[j] = ft_strjoin("declare -x ", arr[j]);
//             if(ft_strchr(arr[j], '=') && !ft_strcmp(ft_strchr(arr[j], '='), "="))
//                 arr[j] = ft_strjoin(arr[j], "\"\"");
//             ft_putstr_fd(arr[j], fd);
// 			//printf("%s\n", arr[j]);
//             write(fd,  "\n", 1);
//             j++;
//         }
// 	}
//     j  = 1;
//     i = 0;
//     str= NULL; 
//     while (command[j])
//     {
//     i = 0;
//        flag = ft_parse(command[j]);
//         if(flag == 1)
//         {
//             perror(command[j]);
//             break;
//         }
//         var = ft_split(command[j], '=');
//         s = malloc(ft_strlen(var[0]) + 1);
        
//         if(flag == 3  || flag == 0)
//             s = ft_strjoin(var[0], "=");
//         if (flag == 2)
//         {
//             while( var[0] && var[0][a] && var[0][a]!= '+')
//             {
//                 s[a] = var[0][a];
//                 a++;
// 			}
//         }
//        i = 0;
//         while(arr[i])
//         {
//         flag = ft_parse(command[j]);
    
//             if(( flag == 2 && !ft_strncmp(arr[i],  s, ft_strlen(s)) ) || (!ft_strncmp(arr[i],  var[0], ft_strlen(var[0]))))
//             {   
//                 if(!var[1])
//                 {
//                  flag = 5;
//                 break;
//                 }
//                 if(flag == 2)
//                 {
//                      str = ft_strjoin(s , "=");
//                     a= ft_parse(arr[i]);
//                     if(a == 0)
//                     {
//                        str = ft_strjoin(arr[i], "=");
//                        str= ft_strjoin(str, var[1]);
//                     }
//                    else if(var[1])
//                         str= ft_strjoin(arr[i], var[1]);
//                 }
//                 if(flag == 3 )
//                     str = ft_strdup(command[j]);
//                 if(flag == 0)
//                 {
//                     str = ft_strdup(command[j]);
//                 }
//              if(str)
//              {
//             if(flag == 3)
//             {
//                 remove_list(&global, arr[i]);
//                 break;
//             }
//             else 
//             {
//                     remove_list(&global,arr[i]);
//                     ft_lstadd_back(&global, ft_lstnew(str));
//                     flag = 1000;
//                }  
//                }
//             } 
//            i++; 
//         } 
//         if(flag==5)
//             break;
//         if(flag == 2)
//         {
//              str = ft_strjoin(s, "=");
//              str= ft_strjoin(str, var[1]);
//              ft_lstadd_back(&global, ft_lstnew(str));
//         }
//        else  if(flag != 1000 )
//              {
//         ft_lstadd_back(&global, ft_lstnew(command[j]));  
//                   }
//            b = 0;
//                     tmps = global;
//                     while(tmps)
//                     {
//                         tmps = tmps->next;
//                         b++;
//                     }
//          j++; 
//            }
// 		   printf("yes export\n");
//     return(0);
//     }