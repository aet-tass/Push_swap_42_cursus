CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

SRC = push_swap.c check_arg.c s_stack.c \
 p_stack.c sort_small_stack.c rr_stack.c r_stack.c sort_five.c sort_range.c

OBJ = ${SRC:.c=.o}

all : NAME

NAME:  compile push_swap

compile:
	@make -C libft

push_swap: $(OBJ) $(compile)
		$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o push_swap

clean:
	@make clean -C libft
	@$(RM) $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -f push_swap

re : fclean all

.PHONY:		all clean fclean re
