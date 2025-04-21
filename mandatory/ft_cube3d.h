/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_cube3d.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geuyoon <geuyoon@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/19 00:28:05 by geuyoon		   #+#	#+#			 */
/*   Updated: 2025/04/20 08:54:35 by geuyoon		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FT_CUBE3D_H
# define FT_CUBE3D_H

// map symbol
# define EMPTY ' '
# define SPACE '0'
# define WALL '1'
# define PNORTH 'N'
# define PSOUTH 'S'
# define PWEST 'W'
# define PEAST 'E'
# define NEWLINE '\n'
// p_fix symbol
# define MNORTH "NO"
# define MSOUTH "SO"
# define MWEST "WE"
# define MEAST "EA"
# define MFC "F"
# define MCC "C"
// key symbol
# define KW 13
# define KA 0
# define KS 1
# define KD 2
# define KESC 53
# define KLEFT 123
# define KRIGHT 124
// err code
# define ERR 1
# define WSIZE 1
// err text
# define ETPROARG "unexpected program argument"
# define ETMAPNAME "unexpected program argument"
# define ETIMGINFO "unexpected image infomation"
# define ETCOLINFO "unexpected color infomation"
# define ETMAPINFO "unexpected map info"
# define ETMAPSHAPE "unexpected map shape"
# define ETPLAYERNO "no player info"
# define ETPLAYERPOS "unexpected player pos"
# define ETPLAYERDUP "duplicate player info"
// display
# define WWIDTH 1920
# define WHEIGHT 1060
# define SIZE 100
// player speed
# define MOVESPEED 0.1
# define ROTSPEED 0.1

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

// image structure
typedef struct s_image
{
	void	*img_ptr;
	char	*img_data;
	int		height;
	int		width;
	int		bpp;
	int		sizeline;
	int		endian;
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
// player structure
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}	t_player;
// map structure
typedef struct s_map
{
	char		**map_data;
	size_t		map_height;
	size_t		map_width;
}	t_map;
// mlx structure
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;
// data structure
typedef struct s_data
{
	t_image_con	*image_con;
	t_color_con	*color_con;
	t_player	*player;
	t_map		*map;
	t_mlx		*mlx_ctl;
}	t_data;
// resizer structure
typedef struct s_cutter
{
	size_t	w_s;
	size_t	h_s;
	size_t	new_height;
}	t_cutter;

// data
t_data		*init_data(int map_fd);
// image
t_image_con	*init_image_con(t_data *data, int map_fd);
void		parse_image(t_data *data, int map_fd);
void		image_resizer(t_data *data, t_image *image);
// color
t_color_con	*init_color_con(t_data *data, int map_fd);
void		parse_color(t_data *data, int map_fd);
// player
t_player	*init_player(t_data *data);
void		set_player_pos(t_player *player, size_t x, size_t y);
void		set_player_dir(t_player *player, char dir);
void		move_player(t_player *player, t_map *map, double x, double y);
void		rot_player(t_player *player, double p_x, double p_y);
// map
t_map		*init_map(t_data *data, int map_fd);
// map checker
void		map_checker(t_data *data, t_map *map);
void		map_dp(t_data *data, int **round_checker, size_t x, size_t y);
int			**init_round_checker(t_data *data, t_map *map);
int			map_ele_checker(char ele);
void		map_check_exit(t_data *data, int **round_checker, char *str, \
				int errsig);
void		map_p_pos_setter(t_data *data, int **round_checker, size_t x, \
				size_t y);
void		wall_topbot_copier(t_data *data, t_map *map, int **round_checker, \
				size_t h_cnt);
void		wall_copier(t_data *data, t_map *map, int **round_checker, \
				size_t h_cnt);
// map opt
void		map_optimizer(t_map *map, int **round_checker);
void		map_resizer(t_data *data, t_map *map);
// key
void		key_ctl(t_data *data);
// window
int			close_window(t_data *data);
// free
void		data_free(t_data *data);
void		image_free(t_data *data, t_image *image);
// utils
size_t		ft_strtdlen(char **tdstr);
void		free_td_str(char **ptr, size_t height);
void		free_td_int(int **ptr, size_t height);
void		exit_err(t_data *data, char *str, int errsig);
void		print_err(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strndup(char *str, size_t len);
char		*read_line(int fd);
// test
void		test_print_round_checker(int **round_checker, t_map *map);
void		test_print_mapdata(t_map *map);

#endif
