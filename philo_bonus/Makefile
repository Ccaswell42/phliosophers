HEAD = philo_bonus.h 
NAME = philo_bonus
FLAGS = -Wall -Wextra -Werror
DIR = obj/
SRCS = init_philos.c main_bonus.c proc_bonus.c utils_bonus.c create_proc_bonus.c checker_bonus.c
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
