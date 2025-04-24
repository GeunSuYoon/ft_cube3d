/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_cast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:17:21 by geuyoon           #+#    #+#             */
/*   Updated: 2025/04/24 11:50:02 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cube3d.h"

void    casting_loop(t_data *data, t_rcast *rcast, t_player *player);
t_image	*get_wall_texture(t_rcast *rcast, t_image_con *img_con);
void	draw_loop(t_rcast *rcast, t_image *texture);
void	mapping_loop(t_rcast *rcast, t_image *texture, int draw_start, int draw_end);
void	find_buf_addr(t_rcast *rcast, int y, int color);

void    casting_loop(t_data *data, t_rcast *rcast, t_player *player)
{
	t_image	*texture;

	rcast->x = 0;
	while (rcast->x < data->map->map_width)
	{		
		cast_cam(rcast, player);
		cast_side(rcast, player);
		cast_hit(rcast, data->map->map_data);
		if (rcast->side)
			rcast->perp_wall_dist = (rcast->side_dist_y - rcast->delta_dist_y);
		else
			rcast->perp_wall_dist = (rcast->side_dist_x - rcast->delta_dist_x);
		rcast->line_height = (int)(SIZE / rcast->perp_wall_dist);
		texture = get_wall_texture(rcast, data->image_con);
		cast_wall_x(rcast, player, texture);
		draw_loop(rcast, texture);
		rcast->x++;
	}
}

t_image	*get_wall_texture(t_rcast *rcast, t_image_con *image_con)
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
			wall_texture = image_con->ea;
		else
			wall_texture = image_con->we;
	}
}

void	draw_loop(t_rcast *rcast, t_image *texture)
{
	int	draw_start;
	int	draw_end;

	draw_start = -rcast->line_height / 2 + SIZE / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = rcast->line_height / 2 + SIZE / 2;
	if (draw_end >= SIZE)
		draw_end = SIZE - 1;
	rcast->step = 1.0 * SIZE / rcast->line_height;
	rcast->tex_pos = ((double)draw_start - (double)WHEIGHT / 2 + \
		(double)rcast->line_height / 2) * rcast->step;
	mapping_loop(rcast, texture, draw_start, draw_end);
}

void	mapping_loop(t_rcast *rcast, t_image *texture, int draw_start, int draw_end)
{
	int		y;
	int		tex_y;
	int		color;
	char	*pixel;

	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)rcast->tex_pos % texture->height;
		rcast->tex_pos += rcast->step;
		pixel = texture->img_data + \
			(tex_y * texture->sizeline + rcast->tex_x * (texture->bpp / 8));
		color = *(int *)pixel;
		find_buf_addr(rcast, y, color);
		y++;
	}
}

void	find_buf_addr(t_rcast *rcast, int y, int color)
{
	char	*dst;

	dst = rcast->window_img->img_data + (y * rcast->window_img->sizeline + \
			rcast->x * (rcast->window_img->bpp / 8));
	*(unsigned int *)dst = color;
}
