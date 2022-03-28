HEAD = philo.h 
NAME = philo
FLAGS = -Wall -Wextra -Werror
DIR = obj/
SRCS = main.c init_philos.c utils.c
COLOR = \033[32m
ENDCOLOR = \033[0m
OBJS = $(patsubst %.c,$(DIR)%.o,$(SRCS))
.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
		gcc -o $(NAME) $(OBJS) 
		@echo "${COLOR}Project succesfully compiled $(ENDCOLOR)"

		
$(DIR)%.o:%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all


// gcc -fsanitize=thread