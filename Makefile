# Names
NAME	= cub3D
MNAME	= libmlx_Linux.a

# Source Files and Object Files, Header
SRC		= ./mandatory/ft_cube3d.c			\
		  ./mandatory/ft_cube3d_data.c		\
		  ./mandatory/ft_cube3d_image.c		\
		  ./mandatory/ft_cube3d_color.c		\
		  ./mandatory/ft_cube3d_map.c		\
		  ./mandatory/ft_cube3d_map_check.c	\
		  ./mandatory/ft_cube3d_map_check_utils.c	\
		  ./mandatory/ft_cube3d_map_opt.c	\
		  ./mandatory/ft_cube3d_free.c		\
		  ./mandatory/ft_cube3d_malloc.c	\
		  ./mandatory/ft_cube3d_utils.c		\
		  ./mandatory/ft_cube3d_err.c		\
		  ./mandatory/ft_cube3d_test.c		\

OBJ		= $(SRC:.c=.o)
HEADER	= ./mandatory

# Compiler and Flags
CC		= cc
CFLAG	= -Wall -Wextra -Werror -g
MLX		= ./mlx_linux/$(MNAME)
LFT		= ./ft_lib/ft_printf/libft/libft.a
GNL		= ./ft_lib/ft_gnl/libftgnl.a
INC		= -I $(HEADER) -I ./ft_lib/ft_printf/libft -I ./ft_lib/ft_gnl -I ./mlx_linux
LFLAG	= -Lft_lib/ft_printf/libft -lft
GFLAG	= -Lft_lib/ft_gnl -lftgnl
MFLAG	= -Lmlx_linux -lmlx_Linux -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm

# Rules
all 	: $(MLX) $(LFT) $(GNL) $(NAME)

$(NAME) : $(OBJ)
	@echo " [..] | Compiling cub3D.."
	@$(CC) $(CFLAG) $(OBJ) $(LFT) $(GNL) $(MFLAG) -o $@ $(INC)
	@echo " [OK] | cub3D is ready!"

%.o		: %.c
	@$(CC) $(CFLAG) $(INC) -o $@ -c $<

$(MLX)	:
	@echo " [..] | Compiling minilibx.."
	@make -s -C mlx_linux
	@echo " [OK] | minilibx is ready!"

$(LFT)	:
	@echo " [..] | Compiling libft.."
	@make -s -C ft_lib/ft_printf/libft
	@echo " [OK] | libft is ready!"

$(GNL)	:
	@echo " [..] | Compiling gnl.."
	@make -s -C ft_lib/ft_gnl
	@echo " [OK] | gnl is ready!"

fclean 	: clean
	@rm -f $(NAME) ./mlx_linux/$(MNAME)
	@$(MAKE) -C ./ft_lib/ft_gnl fclean -s || exit 1;
	@$(MAKE) -C ./ft_lib/ft_printf/libft fclean -s || exit 1;

clean 	:
	@rm -f $(OBJ)
	@$(MAKE) -C ./mlx_linux clean -s || exit 1;
	@$(MAKE) -C ./ft_lib/ft_gnl clean -s || exit 1;
	@$(MAKE) -C ./ft_lib/ft_printf/libft clean -s || exit 1;

re 		: fclean all

.PHONY 	: all fclean clean re
