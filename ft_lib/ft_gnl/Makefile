NAME	= libftgnl.a
SRC		= ./get_next_line.c			\
		  ./get_next_line_utils.c	\

OBJ		= $(SRC:.c=.o)
AR		= ar
ARFLAG	= rcs
CC		= cc
CFLAG	= -Wall -Wextra -Werror
HEADER	= ./

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAG) $@ $^

%.o	:	%.c
	$(CC) $(CFLAG) -I $(HEADER) -o $@ -c $^

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJ)

re : fclean all

.PHONY : all fclean clean re