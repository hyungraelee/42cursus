
NAME = libftprintf.a
LIBFT = libft.a

INC_DIR = ./include
INC_DIR_LIBFT = ./libft/include_libft
SRC_DIR = ./srcs
DIR_LIBFT = ./libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcv
RM = rm -f

SRCS =	ft_printf.c			\
		ft_set.c			\
		ft_parse.c			\
		ft_func_by_type.c	\
		ft_print_di.c		\
		ft_print_c.c		\
		ft_print_s.c		\
		ft_print_u.c		\
		ft_print_x.c		\
		ft_print_p.c		\
		ft_print_pct.c		\
		ft_print_o.c		\
		ft_print_n.c		\
		ft_print_f.c		\
		ft_print_f_util.c	\
		ft_print_e.c		\
		ft_print_e_util_a.c	\
		ft_print_e_util_b.c	\
		ft_print_g.c		\
		ft_apply.c			\
		ft_bigint.c			\
		ft_lltoa.c			\
		ft_ulltoa.c			\
		ft_get_data.c		\
		ft_util.c			\
		ft_convert.c		\
		ft_bigint_dec.c		\
		ft_bigint_int.c

OBJS_DIR = ./objs

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(addprefix $(OBJS_DIR)/, $(OBJS))
	@make -C ./libft
	@cp ./libft/$(LIBFT) ./$(NAME)
	@$(AR) $(NAME) $^

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INC_DIR_LIBFT) -I$(INC_DIR) -c $<

bonus : all

clean :
	@make -C ./libft fclean
	@$(RM) $(addprefix $(OBJS_DIR)/, $(OBJS))
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)
re : fclean all
