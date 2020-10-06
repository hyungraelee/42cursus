CC = gcc
CFLAG = -Wall -Wextra -Werror
TARGET = libft.a

OBJS_PART1 =	\
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
		./ft_tolower.c


all : &(TARGET)

.c.o :
	&(CC) -c -o $@ $<

&(TARGET) : &(OBJS_PART1)
	&(CC) -o &(TARGET)
