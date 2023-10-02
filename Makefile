NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_BONUS	= $(wildcard *_bonus.c)
SRC			= $(filter-out $(SRC_BONUS),$(wildcard *.c))
	
OBJS		= $(SRC:.c=.o)
OBJS_BONUS	= $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $^

$(NAME): $(OBJS)
	ar -rcs $@ $^

clean:
	-rm $(OBJS)

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus