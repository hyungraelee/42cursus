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

test : test.c
	@gcc -o test test.c
	@echo "\033[1;5;92m"
	@./test

t : fclean test

clean :
	@make -C ../ fclean
	@$(RM) $(OBJ)
	@$(RM) test

fclean : clean
	@$(RM) $(NAME)

re : fclean all
