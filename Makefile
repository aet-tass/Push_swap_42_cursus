CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

SRC = push_swap.c check_arg.c first_rules.c  utils_1.c utils_2.c rules_2.c utils/libftprintf.a


OBJ = ${SRC:.c=.o}

all : NAME

NAME: compile push_swap

compile:
	@make -C utils

push_swap: $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) utils/libftprintf.a -o push_swap

clean:
	@$(RM) $(OBJ)
	@make clean -C utils
fclean : clean
	@rm -f push_swap
	@make fclean -C utils

re : fclean all

.PHONY:		all clean fclean re
