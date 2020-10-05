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
		./ft_strlcpy	\
		./ft_strlcat	


all : &(TARGET)

.c.o :
	&(CC) -c -o $@ $<

&(TARGET) : &(OBJS_PART1)
	&(CC) -o &(TARGET)
