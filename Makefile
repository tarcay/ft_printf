LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		srcs/ft_putnbr_base.c \
		srcs/ft_strcmp.c \
		srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_putnbr.c \
		srcs/ft_putnbr_u.c \
		srcs/ft_print_int.c \
		srcs/ft_print_str.c \
		srcs/ft_print_char.c \
		srcs/ft_print_addr.c \
		srcs/ft_print_unsigned.c \
		srcs/ft_print_flag.c \
		
SURPL_O = ft_putnbr_base.o \
		  ft_strcmp.o \
		  ft_putchar.o \
		  ft_putstr.o \
		  ft_putnbr.o \
		  ft_putnbr_u.o \
		  ft_print_int.o \
		  ft_print_str.o \
		  ft_print_char.o \
		  ft_print_addr.o \
		  ft_print_unsigned.o \
		  ft_print_flag.o \

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