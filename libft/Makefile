.SUFFIXES = .c.o

INC = libft.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS_PART1 =	\
		./ft_memset.c	\
		./ft_bzero.c	\
		./ft_memcpy.c	\
		./ft_memccpy.c	\
		./ft_memmove.c	\
		./ft_memchr.c	\
		./ft_memcmp.c	\
		./ft_strlen.c	\
		./ft_strlcpy.c	\
		./ft_strlcat.c	\
		./ft_strchr.c	\
		./ft_strrchr.c	\
		./ft_strnstr.c	\
		./ft_strncmp.c	\
		./ft_atoi.c		\
		./ft_isalpha.c	\
		./ft_isdigit.c	\
		./ft_isalnum.c	\
		./ft_isascii.c	\
		./ft_isprint.c	\
		./ft_toupper.c	\
		./ft_tolower.c	\
		./ft_calloc.c	\
		./ft_strdup.c

OBJS_PART1 = $(SRCS_PART1:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_PART1)
	ar rcv $@ $(OBJS_PART1)
	ranlib $@
.c.o : $(SRC_PART1) $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJS_PART1)
fclean : clean
	rm -f $(NAME)
re : fclean all
