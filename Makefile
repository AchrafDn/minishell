CC = cc
RM = rm -f
NAME = minishell
Cflags = -Wall -Wextra -Werror -I /usr/include/readline -g3
Lflags = -L /usr/lib -lreadline
SanitizeFlags = -fsanitize=address
Cfiles = parssing.c \
		expand.c \
		create_list.c \
		split_mask.c \
		fill_node.c \
		alloc_nodes_cmd_files.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstlast.c \
		libft/ft_lstnew.c \
		libft/ft_lstadd_back_env.c \
		libft/ft_lstlast_env.c \
		libft/ft_lstnew_env.c \
		libft/ft_split.c \
		libft/ft_strjoin.c \
		libft/ft_strjoin_char.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		libft/ft_strcmp.c \
		libft/ft_str_env_cmp.c \
		libft/ft_strdup.c

OBJ = ${Cfiles:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(Lflags) $(OBJ) -o $(NAME)

fsanitize: Cflags += $(SanitizeFlags)
fsanitize: $(OBJ)
	@$(CC) $(Lflags) $(Cflags) $(OBJ) -o $(NAME)

.c.o:
	@$(CC) $(Cflags) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
#-fsanitize=address -g3