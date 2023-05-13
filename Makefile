CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

SRC = push_swap.c check_arg.c s_stack.c  utils_1.c utils_2.c p_stack.c

OBJ = ${SRC:.c=.o}

all : NAME

NAME:  push_swap

compile:
	@make -C utils

push_swap: $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o push_swap

clean:
	@$(RM) $(OBJ)
fclean : clean
	@rm -f push_swap

re : fclean all

.PHONY:		all clean fclean re
