HEAD = philo.h 
NAME = philo
FLAGS = -Wall -Wextra -Werror
DIR = obj/
SRCS = main.c init_philos.c utils.c function_proccess.c checker_death.c utils_2.c
COLOR = \033[32m
ENDCOLOR = \033[0m
OBJS = $(patsubst %.c,$(DIR)%.o,$(SRCS))
.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
		cc -o $(NAME) $(OBJS) 
		@echo "${COLOR}Project succesfully compiled $(ENDCOLOR)"

		
$(DIR)%.o:%.c | $(DIR)
	cc $(FLAGS) -c $< -o $@

$(DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all
