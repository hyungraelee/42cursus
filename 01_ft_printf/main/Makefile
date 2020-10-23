NAME = myprintf

SRC = main.c
OBJ = main.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBPRINT = ftprintf
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $^ -L .. -l $(LIBPRINT)
	@./$(NAME)

$(OBJ) : $(SRC)
	@make -C ../
	@$(CC) $(CFLAGS) -o $@ -c $^ -I ../include -I ../libft/include_libft

clean :
	@make -C ../ fclean
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
