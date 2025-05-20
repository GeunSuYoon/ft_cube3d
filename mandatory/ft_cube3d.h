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

# include "ft_cube3d_includes.h"
# include "ft_cube3d_defines.h"

// pos structure
typedef struct s_pos
{
	double	x;
	double	y;
	double	z;
}	t_pos;
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
// casting window structure
typedef struct s_ray
{
	t_image	*window_img;
	int		fc;
	int		cc;
	double	now_time;
	double	old_time;
	double	fram_time;
	int		x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		tex_x;
	double	step;
	double	tex_pos;
}	t_ray;
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
	int	color;
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
	double	plane_x;
	double	plane_y;
}	t_player;
// minimap structure
typedef struct s_minimap
{
	double	scale;
	int		offset_x;
	int		offset_y;
}	t_minimap;
// map structure
typedef struct s_map
{
	char		**map_data;
	size_t		map_height;
	size_t		map_width;
	t_minimap	*minimap;
}	t_map;
// mlx structure
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;
// game structure
typedef struct s_game
{
	t_ray		*rcast;
	t_image_con	*image_con;
	t_player	*player;
	t_map		*map;
	t_mlx		*mlx_ctl;
}	t_game;
// resizer structure
typedef struct s_cutter
{
	size_t	w_s;
	size_t	h_s;
	size_t	new_height;
}	t_cutter;

// game
t_game		*init_game(int map_fd);
// cast
void		get_frame_time(t_ray *rcast);
void		init_rcast_cf(t_ray *rcast);
void		casting_loop(t_game *game, t_ray *rcast, t_player *player);
// player info
void		set_player_pos(t_player *p, char **map_data, double x, double y);
void		set_player_dir(t_player *player, double dir, double rot_speed);
int			is_move_safe(double x, double y, char **map_data);
int			is_wall(double x, double y, char **map_data);
// key
void		key_ctl(t_game *game);
// window
void		cast_window(t_game *game);
int			close_window(t_game *game);
// free
void		game_free(t_game *game);
void		image_free(t_game *game, t_image *image);
// utils
size_t		ft_strtdlen(char **tdstr);
void		free_td_str(char **ptr, size_t height);
void		free_td_int(int **ptr, size_t height);
void		exit_err(t_game *game, char *str, int errsig);
void		print_err(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strndup(char *str, size_t len);
char		*read_line(int fd);
double		get_current_time(void);
// test
void		test_print_round_checker(int **round_checker, t_map *map);
void		test_print_mapdata(t_map *map);

#endif
