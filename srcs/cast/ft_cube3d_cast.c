/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_cast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:17:21 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/20 22:57:53 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cube3d_cast.h"

void	casting_loop(t_game *game, t_player *player);
void	init_window_cf(t_game *game, t_image_con *img_con);
t_image	*get_wall_texture(t_ray *ray, t_image_con *img_con);
void	draw_loop(t_game *game, t_ray *ray);
void	mapping_loop(t_game *game, t_ray *ray, int draw_start, \
	int draw_end);

void	casting_loop(t_game *game, t_player *player)
{
	t_ray	ray;

	init_window_cf(game, game->image_con);
	ray.x = 0;
	while (ray.x < WWIDTH)
	{
		cast_init_val(&ray, player);
		cast_side(&ray, player);
		cast_hit(&ray, game->map->map_data);
		if (ray.side)
			ray.perp_wall_dist = ray.side_dist_y - ray.delta_dist_y;
		else
			ray.perp_wall_dist = ray.side_dist_x - ray.delta_dist_x;
		ray.line_height = (int)(WHEIGHT / ray.perp_wall_dist);
		ray.texture = get_wall_texture(&ray, game->image_con);
		cast_wall_x(&ray, player, ray.texture);
		draw_loop(game, &ray);
		ray.x++;
	}
	cast_minimap(game);
}

void	init_window_cf(t_game *game, t_image_con *img_con)
{
	size_t	h_cnt;
	size_t	w_cnt;

	h_cnt = 0;
	while (h_cnt < WHEIGHT / 2)
	{
		w_cnt = 0;
		while (w_cnt < WWIDTH)
		{
			draw_pixel(game->window_img, w_cnt, h_cnt, img_con->cc);
			w_cnt++;
		}
		h_cnt++;
	}
	while (h_cnt < WHEIGHT)
	{
		w_cnt = 0;
		while (w_cnt < WWIDTH)
		{
			draw_pixel(game->window_img, w_cnt, h_cnt, img_con->fc);
			w_cnt++;
		}
		h_cnt++;
	}
}

t_image	*get_wall_texture(t_ray *ray, t_image_con *image_con)
{
	t_image	*wall_texture;

	if (ray->side)
	{
		if (ray->ray_dir_y > 0)
			wall_texture = image_con->so;
		else
			wall_texture = image_con->no;
	}
	else
	{
		if (ray->ray_dir_x > 0)
			wall_texture = image_con->we;
		else
			wall_texture = image_con->ea;
	}
	return (wall_texture);
}

void	draw_loop(t_game *game, t_ray *ray)
{
	int	draw_start;
	int	draw_end;
	int	y;

	draw_start = -ray->line_height / 2 + WHEIGHT / 2;
	draw_end = ray->line_height / 2 + WHEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WHEIGHT)
		draw_end = WHEIGHT - 1;
	ray->step = (double)ray->texture->height / ray->line_height;
	ray->tex_pos = (draw_start - (WHEIGHT / 2 - ray->line_height / 2)) * \
		ray->step;
	y = draw_start;
	mapping_loop(game, ray, y, draw_end);
}

void	mapping_loop(t_game *game, t_ray *ray, int y, \
	int draw_end)
{
	int		tex_y;
	int		color;
	char	*pixel;

	while (y < draw_end)
	{
		tex_y = (int)(ray->tex_pos);
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= ray->texture->height)
			tex_y = ray->texture->height - 1;
		pixel = ray->texture->img_data + \
			(tex_y * ray->texture->sizeline + \
			ray->tex_x * (ray->texture->bpp / 8));
		color = *(int *)pixel;
		draw_pixel(game->window_img, ray->x, y, color);
		ray->tex_pos += ray->step;
		y++;
	}
}
