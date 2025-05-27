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

#ifndef FT_CUBE3D_BONUS_H
# define FT_CUBE3D_BONUS_H

# include "ft_cube3d_includes_bonus.h"
# include "ft_cube3d_defines_bonus.h"

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
// image container structure
typedef struct s_image_con
{
	t_image	*no;
	t_image	*so;
	t_image	*we;
	t_image	*ea;
	int		fc;
	int		cc;
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
	t_image_con	*image_con;
	t_player	*player;
	t_map		*map;
	t_mlx		*mlx_ctl;
	t_image		*window_img;
	double		now_time;
	double		old_time;
	double		fram_time;
	int			move[4];
	int			rot[2];
	int			run_flag;
}	t_game;

// game
t_game		*init_game(int map_fd);
// cast
void		get_frame_time(t_game *game);
void		casting_loop(t_game *game, t_player *player);
// player info
void		set_player_pos(t_player *p, char **map_data, double x, double y);
void		set_player_dir(t_player *player, double dir, double rot_speed);
int			is_move_safe(double x, double y, char **map_data);
int			is_wall(double x, double y, char **map_data);
// key
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
// window
int			cast_window(void *arg);
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

#endif
