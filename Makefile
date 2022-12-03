NAME  = philo

SRCS  = philo.c \
		ft_atoi.c\
		ft_usleep.c\
		philo_utils.c\
		routines.c\

CC = @cc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

all : $(NAME)
$(NAME) : $(SRCS) 
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "philo is ready"

clean :
	@rm -f $(NAME)

fclean : clean

re : fclean all
