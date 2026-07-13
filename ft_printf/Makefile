NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
ARFLAGS		= rcs
RM			= rm -f

INCLUDES = -I. -I../libft

SRCS		= ft_printf.c \
	print_numbers.c \
	print_words.c \
	utils.c

OBJS		= $(SRCS:.c=.o)

HEADER		= ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re