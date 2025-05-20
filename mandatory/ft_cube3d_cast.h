/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_cast.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:18:42 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/20 18:53:04 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE3D_CAST_H
# define FT_CUBE3D_CAST_H

# include "ft_cube3d.h"

// minimap wall structure
typedef struct s_wall
{
	int	start_x;
	int	start_y;
}	t_wall;
// draw circle structure
typedef struct s_dcircle
{
	int	x;
	int	y;
	int	err;
}	t_dcircle;
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

void	cast_cam(t_rcast *rcast, t_player *player);
void	cast_side(t_rcast *rcast, t_player *player);
void	cast_hit(t_rcast *rcast, char **map_data);
void	cast_dist(t_rcast *rcast, t_player *player);
void	cast_wall_x(t_rcast *rcast, t_player *player, t_image *texture);
void	cast_minimap(t_game *game);
void	draw_pixel(t_image *img, int x, int y, int color);
void	draw_circle(t_image *img, int cx, int cy, int color);
void	draw_line(t_image *img, t_player *player, int offset_x, int offset_y);

#endif