NAME = minishell
Cflags = -Wall -Wextra -Werror 
Lflags = -lreadline -I/Users/kkouaz/Desktop/readline-8.2 -L /Users/kkouaz/Desktop/readline-8.2 -lcurses
Cfiles = parssing.c create_list.c split_mask.c fill_node.c alloc_nodes_cmd_files.c libft/ft_lstadd_back.c \
		libft/ft_lstlast.c libft/ft_lstnew.c   builtins.c tools.c libft/ft_atoi.c libft/ft_putstr_fd.c \
		libft/ft_strjoin.c libft/ft_putchar_fd.c libft/ft_strlcpy.c  libft/ft_strlen.c  libft/ft_isalnum.c \
		libft/ft_strncmp.c gcl/get_next_line.c gcl/get_next_line_utils.c exec.c files.c \
		heredoc.c libft/ft_isalpha.c libft/ft_split.c libft/ft_strdup.c libft/ft_strnstr.c \
		libft/ft_isdigit.c libft/ft_substr.c lists.c process.c tools2.c signals.c 

OBJ = ${Cfiles:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(Cflags) $(Lflags) -fsanitize=address -g3  $(OBJ) -o $(NAME)  
#@$(CC) $(Lflags) $(OBJ) -o $(NAME)

.c.o:
		@$(CC) $(Cflags) -c $< -o $@

clean :
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

