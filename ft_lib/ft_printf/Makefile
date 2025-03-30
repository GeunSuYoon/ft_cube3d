NAME	= libftprintf.a
SRC		= ./ft_printf.c			\
		  ./ft_printf_char.c	\
		  ./ft_printf_deci.c	\
		  ./ft_printf_hexa.c	\

OBJ		= $(SRC:.c=.o)
AR		= ar
ARFLAG	= rcus
CC		= cc
CFLAG	= -Wall -Wextra -Werror
HEADER	= ./

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C ./libft
	$(AR) $(ARFLAG) $@ $^

%.o 	: %.c
	@$(CC) $(CFLAG) -I $(HEADER) -o $@ -c $^

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -C ./libft fclean

clean :
	@rm -f $(OBJ)
	@$(MAKE) -C ./libft clean

re : fclean all

.PHONY : all fclean clean re