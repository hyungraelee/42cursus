
NAME = libftprintf.a
LIBFT = libft.a

INC_DIR = ./include_printf
INC_DIR_LIBFT = ./libft/include_libft
DIR_LIBFT = ./libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcv
RM = rm -f
SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft
	cp ./libft/$(LIBFT) ./$(NAME)
	$(AR) $(NAME) $^

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ -I$(INC_DIR_LIBFT) -I$(INC_DIR) -c $<

clean :
	make -C ./libft fclean
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re : fclean all
