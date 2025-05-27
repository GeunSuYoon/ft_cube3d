/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_cast_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:18:42 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/27 12:06:39 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE3D_CAST_BONUS_H
# define FT_CUBE3D_CAST_BONUS_H

# include "ft_cube3d_bonus.h"

// casting window structure
typedef struct s_ray
{
	t_image	*texture;
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
// minimap wall structure
typedef struct s_wall
{
	int	start_x;
	int	start_y;
}	t_wall;
// draw line structure
typedef struct s_dline
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_dline;

void	cast_init_val(t_ray *ray, t_player *player);
void	cast_side(t_ray *ray, t_player *player);
void	cast_hit(t_ray *ray, char **map_data);
void	cast_dist(t_ray *ray, t_player *player);
void	cast_wall_x(t_ray *ray, t_player *player, t_image *texture);
void	cast_minimap(t_game *game);
void	draw_pixel(t_image *img, int x, int y, int color);
void	draw_circle(t_image *img, int cx, int cy, int color);
void	draw_line(t_image *img, t_player *player, int offset_x, int offset_y);
void	init_window_cf(t_game *game, t_image_con *img_con);

#endif