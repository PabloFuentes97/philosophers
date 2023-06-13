NAME = philo

SRC = lst_functions.c philo.c ft_split.c utils.c utils2.c set_args.c \
set_academy.c set_get.c checkers.c philo_func.c time.c print.c end_program.c fork.c

OBJ = $(SRC:.c=.o)

all: $(NAME) 

CC		= gcc

CCFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=thread

$(NAME): $(OBJ)
		$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)
clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re