CC = cc
RM = rm -f
NAME = a.out
Cflags = -Wall -Wextra -Werror
Cfiles = parssing.c\
		create_list.c \
		split_mask.c \
		fill_node.c \
		alloc_nodes_cmd_files.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstlast.c \
		libft/ft_lstnew.c \
		libft/ft_split.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		libft/ft_strcmp.c \
		libft/ft_strdup.c \
		
OBJ = ${Cfiles:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(Cflags) $(OBJ) -o $(NAME)

${OBJ} :  $(Cfiles)

.c.o:
		@$(CC) $(Cflags) -c $< -o $@

clean :
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

#-fsanitize=address -g3