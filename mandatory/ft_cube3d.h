/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:28:05 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/07 10:53:00 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE3D_H
# define FT_CUBE3D_H

# define EMPTY ' '
# define SPACE '0'
# define WALL '1'
# define PNORTH 'N'
# define PSOUTH 'S'
# define PWEST 'W'
# define PEAST 'E'
# define NEWLINE '\n'
# define MNORTH "NO"
# define MSOUTH "SO"
# define MWEST "WE"
# define MEAST "EA"
# define MFC "F"
# define MCC "C"
# define ERR 1
# define WSIZE 1

# include "../ft_lib/ft_printf/libft/libft.h"
# include "../ft_lib/ft_printf/ft_printf.h"
# include "../ft_lib/ft_gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <errno.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

// position structure
typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;
// image structure
typedef struct s_image
{
	void	*img_ptr;
	int		height;
	int		width;
}	t_image;
// image container structure
typedef struct s_image_con
{
	t_image	*no;
	t_image	*so;
	t_image	*we;
	t_image	*ea;
}	t_image_con;
// color structure
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;
// color container structure
typedef struct s_color_con
{
	t_color	*fc;
	t_color	*cc;
}	t_color_con;
// map structure
typedef struct s_map
{
	char	**map_data;
	size_t	map_height;
	size_t	map_width;
	t_pos	*p_pos;
}	t_map;
// mlx structure
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_pos	start_pos;
}	t_mlx;
// data structure
typedef struct s_data
{
	t_map		*map;
	t_image_con	*image_con;
	t_color_con	*color_con;
	t_mlx		*mlx_ctl;
}	t_data;

// data
t_data  *init_data(int map_fd);
// image
t_image_con	*init_image_con(t_data *data, int map_fd);
void	parse_image(t_data *data, int map_fd);
// color
t_color_con	*init_color_con(t_data *data, int map_fd);
void	parse_color(t_data *data, int map_fd);
// map
t_map	*init_map(t_data *data, int map_fd);
// map checker
void	wall_copier(t_data *data, t_map *map, int **round_checker);
void	map_dp(t_data *data, int **round_checker, size_t x, size_t y);
int		**init_round_checker(t_data *data, t_map *map);
int		map_ele_checker(char ele);
void	map_check_exit(t_data *data, int **round_checker, char *str, int errsig);
// map opt
void	map_optimizer(t_map *map, int **round_checker);
// free
void    data_free(t_data *data);

size_t	ft_strtdlen(char **tdstr);
void	free_td_str(char **ptr, size_t height);
void	free_td_int(int **ptr, size_t height);
void	exit_err(t_data *data, char *str, int errsig);
void	print_err(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
