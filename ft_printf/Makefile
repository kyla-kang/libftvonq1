NAME = libftprintf.a

SRCS =	ft_printf.c print_char.c print_str.c print_ptr.c print_dec.c print_hexa.c process_specifier.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJS)
	ar -cr $(NAME) $(OBJS)

%.o:%.c ft_printf.h
	cc $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
