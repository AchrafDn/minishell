CC = cc
RM = rm -f
NAME = Minishell
Cflags = -Wall -Wextra -Werror -fsanitize=address -g3
Cfiles = split_mask.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstlast.c \
		libft/ft_lstnew.c \
		libft/ft_split.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		
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