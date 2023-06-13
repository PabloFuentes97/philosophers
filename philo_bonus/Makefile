NAME = philo_bonus

SRC = lst_functions_bonus.c philo_bonus.c ft_split_bonus.c utils_bonus.c \
utils2_bonus.c ft_itoa_bonus.c set_args_bonus.c set_academy_bonus.c sems_bonus.c \
sems_philo_bonus.c gets_bonus.c sets_bonus.c checkers_bonus.c philo_func_bonus.c \
time_bonus.c print_bonus.c end_program_bonus.c

OBJ = $(SRC:.c=.o)

CC		= gcc

CCFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=thread -I.

all: $(NAME) 

$(NAME): $(OBJ)
			$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
