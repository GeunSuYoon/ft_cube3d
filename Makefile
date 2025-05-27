# Names
NAME	= cub3D
MNAME	= libmlx_Linux.a

# Source Files and Object Files, Header
SRC		= ./srcs/ft_cube3d.c						\
		  ./srcs/struct/ft_cube3d_data.c			\
		  ./srcs/struct/ft_cube3d_image.c			\
		  ./srcs/struct/ft_cube3d_image_utils.c		\
		  ./srcs/struct/ft_cube3d_color.c			\
		  ./srcs/struct/ft_cube3d_player.c			\
		  ./srcs/struct/ft_cube3d_player_utils.c	\
		  ./srcs/struct/ft_cube3d_map.c				\
		  ./srcs/struct/ft_cube3d_map_check.c		\
		  ./srcs/struct/ft_cube3d_map_check_utils.c	\
		  ./srcs/struct/ft_cube3d_map_opt.c			\
		  ./srcs/struct/ft_cube3d_map_resizer.c		\
		  ./srcs/struct/ft_cube3d_minimap.c			\
		  ./srcs/utils/ft_cube3d_free.c				\
		  ./srcs/utils/ft_cube3d_malloc.c			\
		  ./srcs/utils/ft_cube3d_utils.c			\
		  ./srcs/utils/ft_cube3d_err.c				\
		  ./srcs/cast/ft_cube3d_cast.c				\
		  ./srcs/cast/ft_cube3d_cast_value.c		\
		  ./srcs/cast/ft_cube3d_cast_minimap.c		\
		  ./srcs/cast/ft_cube3d_cast_draw.c			\
		  ./srcs/mlx_ctl/ft_cube3d_key.c			\
		  ./srcs/mlx_ctl/ft_cube3d_window.c			\

OBJ		= $(SRC:.c=.o)
HEADER	= ./includes

BSRC	= ./srcs_bonus/ft_cube3d_bonus.c						\
		  ./srcs_bonus/struct/ft_cube3d_data_bonus.c			\
		  ./srcs_bonus/struct/ft_cube3d_image_bonus.c			\
		  ./srcs_bonus/struct/ft_cube3d_image_utils_bonus.c		\
		  ./srcs_bonus/struct/ft_cube3d_color_bonus.c			\
		  ./srcs_bonus/struct/ft_cube3d_player_bonus.c			\
		  ./srcs_bonus/struct/ft_cube3d_player_utils_bonus.c	\
		  ./srcs_bonus/struct/ft_cube3d_map_bonus.c				\
		  ./srcs_bonus/struct/ft_cube3d_map_check_bonus.c		\
		  ./srcs_bonus/struct/ft_cube3d_map_check_utils_bonus.c	\
		  ./srcs_bonus/struct/ft_cube3d_map_opt_bonus.c			\
		  ./srcs_bonus/struct/ft_cube3d_map_resizer_bonus.c		\
		  ./srcs_bonus/struct/ft_cube3d_minimap_bonus.c			\
		  ./srcs_bonus/utils/ft_cube3d_free_bonus.c				\
		  ./srcs_bonus/utils/ft_cube3d_malloc_bonus.c			\
		  ./srcs_bonus/utils/ft_cube3d_utils_bonus.c			\
		  ./srcs_bonus/utils/ft_cube3d_err_bonus.c				\
		  ./srcs_bonus/cast/ft_cube3d_cast_bonus.c				\
		  ./srcs_bonus/cast/ft_cube3d_cast_value_bonus.c		\
		  ./srcs_bonus/cast/ft_cube3d_cast_minimap_bonus.c		\
		  ./srcs_bonus/cast/ft_cube3d_cast_draw_bonus.c			\
		  ./srcs_bonus/mlx_ctl/ft_cube3d_key_bonus.c			\
		  ./srcs_bonus/mlx_ctl/ft_cube3d_window_bonus.c			\

BOBJ	= $(BSRC:.c=.o)
BHEADER	= ./includes_bonus

# Compiler and Flags
CC		= cc
CFLAG	= -Wall -Wextra -Werror -g
MLX		= ./mlx_linux/$(MNAME)
LFT		= ./ft_lib/ft_printf/libft/libft.a
GNL		= ./ft_lib/ft_gnl/libftgnl.a
INC		= -I $(HEADER) -I ./ft_lib/ft_printf/libft -I ./ft_lib/ft_gnl -I ./mlx_linux
BINC	= -I $(BHEADER) -I ./ft_lib/ft_printf/libft -I ./ft_lib/ft_gnl -I ./mlx_linux
LFLAG	= -Lft_lib/ft_printf/libft -lft
GFLAG	= -Lft_lib/ft_gnl -lftgnl
MFLAG	= -Lmlx_linux -lmlx_Linux -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm

# Rules
all 	: $(MLX) $(LFT) $(GNL) $(NAME)

$(NAME) : $(OBJ)
	@echo " [..] | Compiling cub3D.."
	@$(CC) $(CFLAG) $(OBJ) $(LFT) $(GNL) $(MFLAG) -o $@ $(INC)
	@echo " [OK] | cub3D is ready!"

bonus	: $(MLX) $(LFT) $(GNL) $(BOBJ)
	@echo " [..] | Compiling cub3D bonus.."
	@$(CC) $(CFLAG) $(BOBJ) $(LFT) $(GNL) $(MFLAG) -o $(NAME) $(BINC)
	@echo " [OK] | cub3D bonus is ready!"
	@touch $@

%.o		: %.c
	@$(CC) $(CFLAG) $(INC) -o $@ -c $<

%_bonus.o		: %_bonus.c
	@$(CC) $(CFLAG) $(BINC) -o $@ -c $<

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
	@rm -f $(NAME) ./mlx_linux/$(MNAME) bonus
	@$(MAKE) -C ./ft_lib/ft_gnl fclean -s || exit 1;
	@$(MAKE) -C ./ft_lib/ft_printf/libft fclean -s || exit 1;

clean 	:
	@rm -f $(OBJ) $(BOBJ)
	@$(MAKE) -C ./mlx_linux clean -s || exit 1;
	@$(MAKE) -C ./ft_lib/ft_gnl clean -s || exit 1;
	@$(MAKE) -C ./ft_lib/ft_printf/libft clean -s || exit 1;

re 		: fclean all

.PHONY 	: all fclean clean re
