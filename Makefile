LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		srcs/ft_base_ui.c \
		srcs/ft_base_ul.c \
		srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_putnbr.c \
		srcs/ft_is_conv_char.c \
		srcs/ft_is_flag.c \
		srcs/ft_lst_new_elem.c \
		srcs/ft_lst_free.c \
		srcs/ft_create_lst_format.c \
		srcs/ft_print_width.c \
		srcs/ft_apply_for_int.c \
		srcs/ft_count_size_nb.c \
		srcs/ft_apply_for_char.c \
		srcs/ft_apply_for_hexa.c \
		srcs/ft_apply_for_str.c \
		srcs/ft_apply_for_unsigned.c \
		srcs/ft_apply_for_ptr.c \
		srcs/ft_apply_for_percent.c \
		
SURPL_O = ft_base_ui.o \
		  ft_base_ul.o \
		  ft_putchar.o \
		  ft_putstr.o \
		  ft_putnbr.o \
		  ft_is_conv_char.o \
		  ft_is_flag.o \
		  ft_lst_new_elem.o \
		  ft_lst_free.o \
		  ft_create_lst_format.o \
		  ft_print_width.o \
		  ft_count_size_nb.o \
		  ft_apply_for_int.o \
		  ft_apply_for_char.o \
		  ft_apply_for_hexa.o \
		  ft_apply_for_str.o \
		  ft_apply_for_unsigned.o \
		  ft_apply_for_ptr.o \
		  ft_apply_for_percent.o \

CC = clang

FLAGS = -c -Wall -Werror -Wextra

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all