CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

SRC = push_swap.c check_arg.c s_stack.c \
 p_stack.c sort_small_stack.c rr_stack.c r_stack.c sort_five.c sort_range.c utils_2.c  utils_1.c

SRCB = push_swap_bonus.c utils_bonus.c \
 utils_3_bonus.c utils_2_bonus.c  utils_1_bonus.c get_next_line.c

OBJ = ${SRC:.c=.o}
OBJB = ${SRCB:.c=.o}
all : NAME
bonus: compile checker

NAME:  compile push_swap

compile:
	@make -C libft

push_swap: $(OBJ) $(compile)
		$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o push_swap


checker: $(OBJB) $(compile)
		$(CC) $(CFLAGS) $(OBJB) libft/libft.a -o checker

clean:
	@make clean -C libft
	@$(RM) $(OBJ) $(OBJB)

fclean : clean
	@make fclean -C libft
	@rm -f push_swap checker

re : fclean all

.PHONY:		all clean fclean re
