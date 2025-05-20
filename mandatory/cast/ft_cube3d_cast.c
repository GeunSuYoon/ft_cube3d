/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_cast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:17:21 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/20 19:41:06 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cube3d_cast.h"

void	casting_loop(t_game *game, t_ray *rcast, t_player *player);
t_image	*get_wall_texture(t_ray *rcast, t_image_con *img_con);
void	draw_loop(t_ray *rcast, t_image *texture);
void	mapping_loop(t_ray *rcast, t_image *texture, int draw_start, \
	int draw_end);

void	casting_loop(t_game *game, t_ray *rcast, t_player *player)
{
	t_image	*texture;

	init_rcast_cf(rcast);
	rcast->x = 0;
	while (rcast->x < WWIDTH)
	{
		cast_cam(rcast, player);
		cast_side(rcast, player);
		cast_hit(rcast, game->map->map_data);
		if (rcast->side)
			rcast->perp_wall_dist = rcast->side_dist_y - rcast->delta_dist_y;
		else
			rcast->perp_wall_dist = rcast->side_dist_x - rcast->delta_dist_x;
		if (rcast->perp_wall_dist < 0.01)
			rcast->perp_wall_dist = 0.01;
		rcast->line_height = (int)(WHEIGHT / rcast->perp_wall_dist);
		if (rcast->line_height > WHEIGHT)
			rcast->line_height = WHEIGHT;
		texture = get_wall_texture(rcast, game->image_con);
		cast_wall_x(rcast, player, texture);
		draw_loop(rcast, texture);
		rcast->x++;
	}
	cast_minimap(game);
}

t_image	*get_wall_texture(t_ray *rcast, t_image_con *image_con)
{
	t_image	*wall_texture;

	if (rcast->side)
	{
		if (rcast->ray_dir_y > 0)
			wall_texture = image_con->so;
		else
			wall_texture = image_con->no;
	}
	else
	{
		if (rcast->ray_dir_x > 0)
			wall_texture = image_con->we;
		else
			wall_texture = image_con->ea;
	}
	return (wall_texture);
}

void	draw_loop(t_ray *rcast, t_image *texture)
{
	int	draw_start;
	int	draw_end;
	int	y;

	draw_start = -rcast->line_height / 2 + WHEIGHT / 2;
	draw_end = rcast->line_height / 2 + WHEIGHT / 2;
	if (draw_end >= WHEIGHT)
		draw_end = WHEIGHT - 1;
	rcast->step = 1.0 * SIZE / rcast->line_height;
	if (draw_start < 0)
	{
		rcast->tex_pos = -draw_start * (1.0 * WHEIGHT / rcast->line_height);
		draw_start = 0;
	}
	else
		rcast->tex_pos = 0;
	y = draw_start;
	mapping_loop(rcast, texture, y, draw_end);
}

void	mapping_loop(t_ray *rcast, t_image *texture, int y, \
	int draw_end)
{
	int		tex_y;
	int		color;
	char	*pixel;

	while (y < draw_end)
	{
		tex_y = (int)(rcast->tex_pos) % texture->height;
		rcast->tex_pos += rcast->step;
		pixel = texture->img_data + \
			(tex_y * texture->sizeline + rcast->tex_x * (texture->bpp / 8));
		color = *(int *)pixel;
		draw_pixel(rcast->window_img, rcast->x, y, color);
		y++;
	}
}
