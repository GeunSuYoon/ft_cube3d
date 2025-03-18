# Names
NAME	= cub3D
MNAME	= libmlx.a

# Source Files and Object Files, Header
SRC		= ./mandatory/ft_so_long.c					\
		  ./mandatory/ft_so_long_coin.c				\
		  ./mandatory/ft_so_long_data.c				\
		  ./mandatory/ft_so_long_image.c			\
		  ./mandatory/ft_so_long_key.c				\
		  ./mandatory/ft_so_long_map_check_utils.c	\
		  ./mandatory/ft_so_long_map_check.c		\
		  ./mandatory/ft_so_long_map.c				\
		  ./mandatory/ft_so_long_player.c			\
		  ./mandatory/ft_so_long_pos.c				\
		  ./mandatory/ft_so_long_print_terminal.c	\
		  ./mandatory/ft_so_long_utils.c			\
		  ./mandatory/ft_so_long_window.c			\
		  ./mandatory/ft_so_long_free.c				\

OBJ		= $(SRC:.c=.o)
HEADER	= ./mandatory/ft_so_long.h

# Compiler and Flags
CC		= cc
CFLAG	= -Wall -Wextra -Werror
LFLAG	= -Lft_lib/ft_printf/libft -lft
PFLAG	= -Lft_lib/ft_printf -lftprintf
GFLAG	= -Lft_lib/ft_gnl -lftgnl
MFLAG	= -Lmlx -lmlx -Imlx
CONFLAG	= -framework OpenGL -framework AppKit
COMPOPT	= -lm

# Rules
all 	: $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C ./ft_lib/ft_printf
	@$(MAKE) -C ./ft_lib/ft_gnl
	@$(MAKE) -C ./mlx
	$(CC) $(CFLAG) $(MFLAG) $(LFLAG) $(PFLAG) $(GFLAG) $(CONFLAG) $(COMPOPT) -I $(HEADER) -o $@ $^

%.o		: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

fclean 	: clean
	@rm -f $(NAME) ./mlx/$(MNAME)
	@$(MAKE) -C ./ft_lib/ft_gnl fclean
	@$(MAKE) -C ./ft_lib/ft_printf fclean
	@$(MAKE) -C ./ft_lib/ft_printf/libft fclean

clean 	:
	@rm -f $(OBJ)
	@$(MAKE) -C ./ft_lib/ft_gnl clean
	@$(MAKE) -C ./ft_lib/ft_printf/libft clean
	@$(MAKE) -C ./mlx clean

re 		: fclean all

.PHONY 	: all fclean clean re